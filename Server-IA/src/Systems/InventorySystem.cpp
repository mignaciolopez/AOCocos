#include "InventorySystem.h"

InventorySystem::InventorySystem(entt::registry* registry)
	: m_registry(registry)
{
	ECS_Log::s_consoleL->trace("[InventorySystem] Constructor");

	m_signalsManager = ECS::SignalsManager::getSignalsManager();

	m_localEntt = entt::null;

	m_registry->on_construct<InventoryComponent>().connect<&InventorySystem::onConstructInventoryC>(this);
	m_registry->on_destroy<InventoryComponent>().connect<&InventorySystem::onDestroyInventoryC>(this);

	m_signalsManager->connect<&InventorySystem::inventorySync>(Signals::INVENTORY_SYNC, this);
	m_signalsManager->connect<&InventorySystem::inventoryUse>(Signals::INVENTORY_ITEM_USE, this);
	m_signalsManager->connect<&InventorySystem::graphicsReload>(Signals::GRAPHICS_RELOAD_INSTANCE, this);
}

InventorySystem::~InventorySystem()
{
	ECS_Log::s_consoleL->trace("[InventorySystem] Destructor");

	m_signalsManager->disconnectAll(this);

	m_registry->on_construct<InventoryComponent>().disconnect<&InventorySystem::onConstructInventoryC>(this);
	m_registry->on_destroy<InventoryComponent>().disconnect<&InventorySystem::onDestroyInventoryC>(this);
}

void InventorySystem::update(double dt)
{
}

void InventorySystem::onConstructInventoryC(entt::registry & registry, entt::entity entity)
{
	auto invC = m_registry->try_get<InventoryComponent>(entity);

	//this should be read from DB
	int index = 0;
	//item 0
	auto item0 = new (std::nothrow) InventoryComponent::Item;
	item0->_col = 0;
	item0->_row = 0;
	item0->_itemType = Items::Potion_Blue;
	item0->_quantity = 5000;
	index = item0->_row * 5 + item0->_col;
	invC->_inventory[index] = item0;
	
	auto item1 = new (std::nothrow) InventoryComponent::Item;
	item1->_col = 1;
	item1->_row = 0;
	item1->_itemType = Items::Potion_Red;
	item1->_quantity = 5000;
	index = item1->_row * 5 + item1->_col;
	invC->_inventory[index] = item1;
}

void InventorySystem::onDestroyInventoryC(entt::registry & registry, entt::entity entity)
{
	auto invC = m_registry->try_get<InventoryComponent>(entity);
	for (auto& item : invC->_inventory)
	{
		if (item)
		{
			delete item;
			item = nullptr;
		}
	}
}

void InventorySystem::inventorySync(entt::entity entity, SLNet::BitStream * bs)
{
	auto invC = m_registry->try_get<InventoryComponent>(entity);

	SLNet::BitStream bsOut;
	bsOut.Write((SLNet::MessageID)Signals::INVENTORY_SYNC);
	bsOut.Write(entity);

	int itemsCount = 0;
	for (int i = 0; i < 25; i++)
	{
		if (invC->_inventory[i])
			itemsCount++;
	}

	if (!itemsCount)
		return;

	bsOut.Write(itemsCount);	//num of items

	for (auto& item : invC->_inventory)
	{
		if (!item)
			continue;

		bsOut.Write(item->_col);
		bsOut.Write(item->_row);
		bsOut.Write(item->_itemType);
		bsOut.Write((uint16_t)item->_quantity);
	}

	m_signalsManager->publish(Signals::NW_SEND_CLIENT, entity, &bsOut);
}

void InventorySystem::inventoryUse(entt::entity entity, SLNet::BitStream * bs)
{
	auto playerC = m_registry->try_get<PlayerComponent>(entity);
	if (!playerC)
	{
		return;
	}

	if (!playerC->_isAlive)
		return;

	auto intC = m_registry->try_get<IntervalComponent>(entity);

	if (!intC)
		return;

	if (intC->_dtLastUse < intC->_constUse)
	{
		return;
	}

	if (!bs)
	{
		return;
	}

	auto invC = m_registry->try_get<InventoryComponent>(entity);

	if (!invC)
	{
		return;
	}

	Items itemType;
	int col = -1, row = -1;


	bs->Read(itemType);
	bs->Read(col);
	bs->Read(row);

	int index = row * 5 + col;
	if (index > 25 || col == -1 || row == -1)
		return;

	if (itemType != invC->_inventory[index]->_itemType)
	{
		//This is a werid situation that the client is not in sync with server and must be analized or just sync the inventory again?
		inventorySync(entity, nullptr);
		return;
	}

	invC->_inventory[index]->_quantity--;

	switch (invC->_inventory[index]->_itemType)
	{
	case Items::Potion_Blue:
		m_signalsManager->publish(Signals::MANA_USE_POTION, entity);
		break;
	case Items::Potion_Red:
		m_signalsManager->publish(Signals::HEALTH_USE_POTION, entity);
		break;
	default:
		break;
	}

	if (invC->_inventory[index]->_quantity < 1)
	{
		SLNet::BitStream bsOut;
		bsOut.Write((SLNet::MessageID)Signals::INVENTORY_ITEM_UPDATE);
		bsOut.Write(entity);
		bsOut.Write(Items::NoItem);
		bsOut.Write(invC->_inventory[index]->_col);
		bsOut.Write(invC->_inventory[index]->_row);
		bsOut.Write(invC->_inventory[index]->_quantity);
		m_signalsManager->publish(Signals::NW_SEND_CLIENT, entity, &bsOut);

		delete invC->_inventory[index];
		invC->_inventory[index] = nullptr;
	}
	else
	{
		SLNet::BitStream bsOut;
		bsOut.Write((SLNet::MessageID)Signals::INVENTORY_ITEM_UPDATE);
		bsOut.Write(entity);
		bsOut.Write(invC->_inventory[index]->_itemType);
		bsOut.Write(invC->_inventory[index]->_col);
		bsOut.Write(invC->_inventory[index]->_row);
		bsOut.Write(invC->_inventory[index]->_quantity);
		m_signalsManager->publish(Signals::NW_SEND_CLIENT, entity, &bsOut);
	}

	intC->_dtLastUse = 0.0f;
}

void InventorySystem::graphicsReload(entt::entity entity, SLNet::BitStream * bs)
{
	
}
