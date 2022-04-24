#include "InventorySystem.h"

USING_NS_CC;

InventorySystem::InventorySystem(cocos2d::Scene* scene, entt::registry* registry)
	: m_scene(scene), m_registry(registry)
{
#if _DEBUG
	cocos2d::log("[InventorySystem] Constructor");
#endif
	m_director = cocos2d::Director::getInstance();
	m_signalsManager = ECS::SignalsManager::getInstance();

	m_graphics = Graphics::getInstance();

	m_localEntt = entt::null;

	m_registry->on_construct<InventoryComponent>().connect<&InventorySystem::onConstructInventoryC>(this);
	m_registry->on_destroy<InventoryComponent>().connect<&InventorySystem::onDestroyInventoryC>(this);

	m_signalsManager->connect<&InventorySystem::setLocalEntity>(Signals::NW_MY_ENTT, this);
	m_signalsManager->connect<&InventorySystem::inventorySync>(Signals::INVENTORY_SYNC, this);
	m_signalsManager->connect<&InventorySystem::inventoryItemUse>(Signals::INVENTORY_ITEM_USE, this);
	m_signalsManager->connect<&InventorySystem::inventoryItemUpdate>(Signals::INVENTORY_ITEM_UPDATE, this);
	m_signalsManager->connect<&InventorySystem::graphicsReload>(Signals::GRAPHICS_RELOAD_INSTANCE, this);
}

InventorySystem::~InventorySystem()
{
#if _DEBUG
	cocos2d::log("[InventorySystem] Destructor");
#endif

	ECS::SignalsManager::getInstance()->disconnectAll(this);

	m_registry->on_construct<InventoryComponent>().disconnect<&InventorySystem::onConstructInventoryC>(this);
	m_registry->on_destroy<InventoryComponent>().disconnect<&InventorySystem::onDestroyInventoryC>(this);
}

void InventorySystem::update(float dt)
{
	if (!m_registry->valid(m_localEntt))
		return;

	
}

void InventorySystem::onConstructInventoryC(entt::registry & registry, entt::entity entity)
{
	//i should get the info from the server for the local entity
	auto inventoryC = m_registry->try_get<InventoryComponent>(entity);

	auto hudC = m_registry->try_get<HudComponent>(entity);

	if (!hudC)
	{
		return;
	}

	inventoryC->_node = Node::create();
	inventoryC->_node->setContentSize(inventoryC->_size);
	inventoryC->_node->setPosition(inventoryC->_pos);
	hudC->_hudNode->addChild(inventoryC->_node, 8);

	inventoryC->_yellowSquare = DrawNode::create(1.0f);
	inventoryC->_yellowSquare->drawRect(Vec2::ZERO, Vec2(32, 32), Color4F::YELLOW);
	inventoryC->_yellowSquare->setVisible(false);
	inventoryC->_yellowSquare->setAnchorPoint(Vec2(0.0f, 1.0f));
	inventoryC->_node->addChild(inventoryC->_yellowSquare, 10);
}

void InventorySystem::onDestroyInventoryC(entt::registry & registry, entt::entity entity)
{
	auto inventoryC = m_registry->try_get<InventoryComponent>(entity);

	inventoryC->_node->removeAllChildren();

	for (auto& it : inventoryC->_inventory)
	{
		if (it)
		{
			delete it;
			it = nullptr;
		}
	}

	auto hudC = m_registry->try_get<HudComponent>(entity);

	if (!hudC)
	{
		return;
	}

	hudC->_hudNode->removeChild(inventoryC->_node);
}

void InventorySystem::setLocalEntity(entt::entity entity, SLNet::BitStream * bs)
{
	m_localEntt = entity;
}

void InventorySystem::inventorySync(entt::entity entity, SLNet::BitStream * bs)
{
	if (!bs)
	{
		//log something
		return;
	}

	auto invC = m_registry->try_get<InventoryComponent>(entity);
	if (!invC)
	{
		//log something
		return;
	}

	for (auto& it : invC->_inventory)
	{
		if (it)
		{
			delete it;
			it = nullptr;
		}
	}

	invC->_node->removeAllChildren();
	invC->_selected = std::make_pair(-1, -1);

	invC->_yellowSquare = DrawNode::create(1.0f);
	invC->_yellowSquare->drawRect(Vec2::ZERO, Vec2(32, 32), Color4F::YELLOW);
	invC->_yellowSquare->setVisible(false);
	invC->_yellowSquare->setAnchorPoint(Vec2(0.0f, 1.0f));
	invC->_node->addChild(invC->_yellowSquare, 10);

	int numbOfItems = 0;
	bs->Read(numbOfItems);

	for (int i = 0; i < numbOfItems; i++)
	{
		int col = -1;
		int row = -1;
		Items itemType = Items::NoItem;
		uint16_t quantity = 0;

		bs->Read(col);
		bs->Read(row);
		bs->Read(itemType);
		bs->Read(quantity);

		int index = row * 5 + col;
		if (index > 25 || col == -1 || row == -1)
			return;

		auto item = createItem(itemType, col, row, quantity);
		invC->_inventory[index] = item;
		invC->_node->addChild(item->_sprite, 1);
	}
}

void InventorySystem::inventoryItemUse(entt::entity entity, SLNet::BitStream * bs)
{
	auto intC = m_registry->try_get<IntervalComponent>(m_localEntt);

	if (!intC)
		return;

	if (intC->_dtLastUse < intC->_constUse)
	{
		//show u cant attack yet
		return;
	}

	auto playerC = m_registry->try_get<PlayerComponent>(entity);
	if (!playerC)
	{
		return;
	}

	if (!playerC->_isAlive)
		return;

	auto invC = m_registry->try_get<InventoryComponent>(entity);
	if (!invC)
	{
		//log something
		return;
	}

	int index = invC->_selected.second * 5 + invC->_selected.first;
	if (index > 25 || invC->_selected.first == -1 || invC->_selected.second == -1)
		return;

	if (invC->_inventory[index] == nullptr)
		return;

	if (invC->_inventory[index]->_quantity < 1)
	{
		return;
	}

	SLNet::BitStream bsOut;
	bsOut.Write((SLNet::MessageID)Signals::INVENTORY_ITEM_USE);
	bsOut.Write(m_localEntt);
	bsOut.Write(invC->_inventory[index]->itemType);
	bsOut.Write(invC->_inventory[index]->_col); // col
	bsOut.Write(invC->_inventory[index]->_row); // row
	m_signalsManager->publish(Signals::NW_SEND_SERVER, m_localEntt, &bsOut);	
}

void InventorySystem::inventoryItemUpdate(entt::entity entity, SLNet::BitStream * bs)
{
	if (!bs)
	{
		return;
	}

	Items itemType;
	int col = -1, row = -1;
	uint16_t quantity = -1;

	bs->Read(itemType);
	bs->Read(col);
	bs->Read(row);
	bs->Read(quantity);

	int index = row * 5 + col;
	if (index > 25 || col == -1 || row == -1)
		return;

	auto invC = m_registry->try_get<InventoryComponent>(entity);

	if (invC->_inventory[index])
	{
		if (invC->_inventory[index]->itemType == itemType)
		{
			invC->_inventory[index]->_quantity = quantity;
			invC->_inventory[index]->_labelQuantity->setString(std::to_string(quantity));
		}
		else
		{
			removeItem(index);
			if (itemType == Items::NoItem)
				return;

			auto item = createItem(itemType, col, row, quantity);
			invC->_inventory[index] = item;
			invC->_node->addChild(item->_sprite, 1);
		}
	}
	else
	{
		auto item = createItem(itemType, col, row, quantity);
		invC->_inventory[index] = item;
		invC->_node->addChild(item->_sprite, 1);
	}
}

void InventorySystem::graphicsReload(entt::entity entity, SLNet::BitStream * bs)
{
	m_graphics = Graphics::getInstance();
}

bool InventorySystem::onTouchBegan(const cocos2d::Touch * touch, cocos2d::Event * ccEvnt)
{
	Touch t = *touch;
	Size nodeSize = ccEvnt->getCurrentTarget()->getContentSize();
	Vec2 touchLocation = m_scene->convertTouchToNodeSpace(&t);
	Rect bbox = Rect(0, 0, nodeSize.width, nodeSize.height);
	Vec2 locationInNodeSpace = ccEvnt->getCurrentTarget()->convertToNodeSpace(touchLocation);

	if (bbox.containsPoint(locationInNodeSpace) && ccEvnt->getCurrentTarget()->getParent()->isVisible())
	{
		auto inventoryC = m_registry->try_get<InventoryComponent>(m_localEntt);
		if (!inventoryC)
		{
			//log something
			return false;
		}
		auto item = static_cast<InventoryComponent::Item*>(ccEvnt->getCurrentTarget()->getUserData());
		inventoryC->_selected = std::make_pair(item->_col, item->_row);

		inventoryC->_yellowSquare->setVisible(true);
		inventoryC->_yellowSquare->setPosition(item->_col * 32, inventoryC->_node->getContentSize().height - (item->_row + 1) * 32);

		return true;
	}

	return false;
}

void InventorySystem::onTouchMoved(const cocos2d::Touch * touch, cocos2d::Event * ccEvnt)
{
}

void InventorySystem::onTouchEnded(const cocos2d::Touch * touch, cocos2d::Event * ccEvnt)
{
}

void InventorySystem::onTouchCancelled(const cocos2d::Touch * touch, cocos2d::Event * ccEvnt)
{
}

InventoryComponent::Item * InventorySystem::createItem(Items itemType, int col, int row, uint16_t quantity)
{
	auto invC = m_registry->try_get<InventoryComponent>(m_localEntt);
	if (!invC)
	{
		return nullptr;
	}

	auto item = new (std::nothrow) InventoryComponent::Item;

	item->itemType = itemType;

	item->_col = col;
	item->_row = row;

	item->_sprite = m_graphics->getItemSprite(itemType);
	item->_sprite->setAnchorPoint(Vec2(0.0f, 1.0f));
	item->_sprite->setPosition(32 * col, invC->_node->getContentSize().height - 32 * row);
	item->_sprite->setUserData(item);

	item->_labelQuantity = Label::createWithSystemFont(std::to_string(quantity), "arial", 10.0f);
	item->_labelQuantity->setAnchorPoint(Vec2(0.0f, 0.0f));
	item->_labelQuantity->setHorizontalAlignment(TextHAlignment::RIGHT);
	item->_labelQuantity->setVerticalAlignment(TextVAlignment::BOTTOM);

	item->_displayName = Label::createWithSystemFont(m_graphics->getItemJson(itemType)->_displayName, "arial", 16.0f);

	item->_quantity = quantity;

	item->_touchListener = EventListenerTouchOneByOne::create();
	item->_touchListener->setSwallowTouches(false);
	item->_touchListener->onTouchBegan = CC_CALLBACK_2(InventorySystem::onTouchBegan, this);
	item->_touchListener->onTouchMoved = CC_CALLBACK_2(InventorySystem::onTouchMoved, this);
	item->_touchListener->onTouchEnded = CC_CALLBACK_2(InventorySystem::onTouchEnded, this);
	item->_touchListener->onTouchCancelled = CC_CALLBACK_2(InventorySystem::onTouchCancelled, this);

	m_scene->getEventDispatcher()->addEventListenerWithSceneGraphPriority(item->_touchListener, item->_sprite);

	item->_sprite->addChild(item->_labelQuantity, 1);

	return item;
}

void InventorySystem::removeItem(int index)
{
	auto invC = m_registry->try_get<InventoryComponent>(m_localEntt);
	if (!invC)
	{
		return;
	}

	auto item = invC->_inventory[index];
	if (!item)
		return;

	m_scene->getEventDispatcher()->removeEventListener(item->_touchListener);

	item->_sprite->removeAllChildrenWithCleanup(true);

	invC->_node->removeChild(item->_sprite);

	delete invC->_inventory[index];
	invC->_inventory[index] = nullptr;

	if (invC->_selected.second * 5 + invC->_selected.first == index)
	{
		invC->_selected.first = -1;
		invC->_selected.second = -1;
	}

	invC->_yellowSquare->setVisible(false);
}
