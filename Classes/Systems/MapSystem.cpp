#include "MapSystem.h"

USING_NS_CC;

MapSystem::MapSystem(cocos2d::Scene* scene, entt::registry* registry)
	: m_scene(scene), m_registry(registry)
{
#if _DEBUG
	cocos2d::log("[MapSystem] Constructor");
#endif
	m_director = cocos2d::Director::getInstance();
	m_signalsManager = ECS::SignalsManager::getInstance();
	m_fileUtils = FileUtils::getInstance();

	m_localEntt = entt::null;

	m_signalsManager->connect<&MapSystem::setLocalEntity>(Signals::NW_MY_ENTT, this);

	m_signalsManager->connect<&MapSystem::addPlayerToMap>(Signals::MAP_ADD_PLAYER, this);
	m_signalsManager->connect<&MapSystem::removePlayerFromMap>(Signals::MAP_REM_PLAYER, this);

	m_signalsManager->connect<&MapSystem::canMove>(Signals::MAP_CAN_MOVE, this);

	m_signalsManager->connect<&MapSystem::toggleDebug>(Signals::MAP_TOGGLE_DEBUG, this);

	m_showDebug = false;

	m_registry->on_construct<MapComponent>().connect<&MapSystem::onConstructMapC>(this);
	m_registry->on_destroy<MapComponent>().connect<&MapSystem::onDestroyMapC>(this);
}

MapSystem::~MapSystem()
{
#if _DEBUG
	cocos2d::log("[MapSystem] Desstructor");
#endif

	
	ECS::SignalsManager::getInstance()->disconnectAll(this);

	if (m_registry->valid(m_localEntt))
	{
		m_registry->remove_if_exists<MapComponent>(m_localEntt);
		m_localEntt = entt::null;
	}

	m_registry->on_construct<MapComponent>().disconnect<&MapSystem::onConstructMapC>(this);
	m_registry->on_destroy<MapComponent>().disconnect<&MapSystem::onDestroyMapC>(this);
}

void MapSystem::update(float dt)
{
	if (!m_registry->valid(m_localEntt))
		return;

	auto mapC = m_registry->try_get<MapComponent>(m_localEntt);

	if (!mapC)
		return;

	int tilesY = mapC->_map->getMapSize().height;

	auto view = m_registry->view<PositionComponent, PlayerComponent>();

	for (auto& e : view)
	{
		auto posC = m_registry->try_get<PositionComponent>(e);
		auto playerC = m_registry->try_get<PlayerComponent>(e);

		if (!posC || !playerC)
			return;

		if (!playerC->_spriteBody)
			continue;

		float newZ = tilesY - posC->_y - 1;
		mapC->_map->reorderChild(playerC->_spriteBody, newZ);
	}
}

void MapSystem::onConstructMapC(entt::registry & registry, entt::entity entity)
{
	auto mapC = m_registry->try_get<MapComponent>(entity);

	//mapC->_lastTouch = Vec2::ZERO;

	mapC->_mapName = "Map" + std::to_string(mapC->_tag) + ".tmx";
	mapC->_path = cocos2d::FileUtils::getInstance()->fullPathForFilename(mapC->_mapName);
	mapC->_map = cocos2d::TMXTiledMap::create(mapC->_path);
	if (!mapC->_map)
	{
		cocos2d::MessageBox("onConstructMapC() Unable to load Map", "[MapSystem]");
		exit(-4);
	}
	//mapC->_map->getLayer("blocks")->setVisible(false);
	mapC->_map->setAnchorPoint(cocos2d::Vec2(0.0f, 0.0f));
	mapC->_map->setPosition(cocos2d::Vec2::ZERO);
	m_scene->addChild(mapC->_map, 1);
	mapC->_map->setCameraMask(static_cast<int>(cocos2d::CameraFlag::USER1));

	/*m_touchListener;
	m_touchListener = EventListenerTouchOneByOne::create();
	m_touchListener->setSwallowTouches(true);
	m_touchListener->onTouchBegan = CC_CALLBACK_2(MapSystem::onTouchBegan, this);
	//m_touchListener->onTouchMoved = CC_CALLBACK_2(MapSystem::onTouchMoved, this);
	m_touchListener->onTouchEnded = CC_CALLBACK_2(MapSystem::onTouchEnded, this);
	//m_touchListener->onTouchCancelled = CC_CALLBACK_2(MapSystem::onTouchCancelled, this);
	m_scene->getEventDispatcher()->addEventListenerWithSceneGraphPriority(m_touchListener, mapC->_map);*/
}

void MapSystem::onDestroyMapC(entt::registry & registry, entt::entity entity)
{
	if (!cocos2d::Director::getInstance()->getRunningScene())
		return;

	if (!cocos2d::Director::getInstance()->getRunningScene()->getUserData())
		return;

	auto mapC = m_registry->try_get<MapComponent>(m_localEntt);

	if (mapC->_map)
	{
		mapC->_map->removeAllChildren();

		if (mapC->_map->getParent())
			mapC->_map->getParent()->removeChild(mapC->_map);
	}
}

void MapSystem::setLocalEntity(entt::entity entity,  SLNet::BitStream* bs)
{
	m_localEntt = entity;	
}

void MapSystem::createMapComponent(entt::entity entity, SLNet::BitStream* bs)
{
	if (!m_registry->valid(m_localEntt))
		return;

	if (!bs)
		return;

	int tag = 1;
	bs->Read(tag);

	//m_registry->assign<MapComponent>(entity, m_scene, tag);
}

void MapSystem::removeMapComponent(entt::entity entity, SLNet::BitStream* bs)
{
	if (!m_registry->valid(entity))
		return;

	m_registry->remove_if_exists<MapComponent>(entity);
}

void MapSystem::addPlayerToMap(entt::entity entity,  SLNet::BitStream* bs)
{
	if (!m_registry->valid(m_localEntt))
		return;

	if (!m_registry->has<MapComponent>(m_localEntt))
		return;

	auto mapC = m_registry->try_get<MapComponent>(m_localEntt);


	if (!m_registry->valid(entity))
		return;

	if (!m_registry->has<PlayerComponent>(entity))
		return;

	auto playerC = m_registry->try_get<PlayerComponent>(entity);

	if (playerC->_spriteBody->getParent() != mapC->_map)
		mapC->_map->addChild(playerC->_spriteBody);
}

void MapSystem::removePlayerFromMap(entt::entity entity,  SLNet::BitStream* bs)
{
	if (!m_registry->valid(m_localEntt))
		return;

	if (!m_registry->has<MapComponent>(m_localEntt))
		return;

	auto mapC = m_registry->try_get<MapComponent>(m_localEntt);


	if (!m_registry->valid(entity))
		return;

	if (!m_registry->has<PlayerComponent>(entity))
		return;

	auto playerC = m_registry->try_get<PlayerComponent>(entity);

	if (playerC->_spriteBody->getParent() == mapC->_map)
		mapC->_map->removeChild(playerC->_spriteBody);
}

void MapSystem::canMove(entt::entity entity,  SLNet::BitStream* bs)
{
	if (!m_registry->valid(m_localEntt))
		return;

	if (!m_registry->has<PositionComponent>(m_localEntt))
		return;

	auto posC = m_registry->try_get<PositionComponent>(m_localEntt);

	if (!m_registry->has<MapComponent>(m_localEntt))
		return;

	auto mapC = m_registry->try_get<MapComponent>(m_localEntt);

	if (!m_registry->has<PlayerComponent>(m_localEntt))
		return;

	auto playerC = m_registry->try_get<PlayerComponent>(m_localEntt);

	int nx = posC->_x;
	int ny = posC->_y;
	int tilesX = mapC->_map->getMapSize().width - 1;
	int tilesY = mapC->_map->getMapSize().height - 1;
	posC->_canWalk = true;

	switch (playerC->_direction)
	{
	case Directions::North:
		ny++;
		break;
	case Directions::East:
		nx++;
		break;
	case Directions::South:
		ny--;
		break;
	case Directions::West:
		nx--;
		break;
	default:
		break;
	}

	//cocos2d::log("Next: (%i, %i)", nx, ny);
	auto view = m_registry->view<PositionComponent>();

	for (auto& entity : view)
	{
		if (entity == m_localEntt)
			continue;

		if (m_registry->try_get<PositionComponent>(entity)->_x == nx &&
			m_registry->try_get<PositionComponent>(entity)->_y == ny)
		{
			posC->_canWalk = false;
			return;
		}
	}

	if (nx < 0 || ny < 0 || nx > tilesX || ny > tilesY)
		posC->_canWalk = false;
	else if (mapC->_map->getLayer("blocks")->getTileAt(Vec2(nx, tilesY - ny)))
		posC->_canWalk = false;
}

void MapSystem::toggleDebug(entt::entity entity,  SLNet::BitStream* bs)
{
	m_showDebug = !m_showDebug;

	if (!m_registry->valid(m_localEntt))
		return;

	if (!m_registry->has<MapComponent>(m_localEntt))
		return;

	m_registry->try_get<MapComponent>(m_localEntt)->_map->getLayer("blocks")->setVisible(m_showDebug);
}

/*bool MapSystem::onTouchBegan(const cocos2d::Touch * touch, cocos2d::Event * ccEvnt)
{
	auto hudC = m_registry->try_get<HudComponent>(m_localEntt);
	//auto mapC = m_registry->try_get<MapComponent>(m_localEntt);

	Touch t = *touch;
	Size nodeSize = hudC->_clippingSize;
	Vec2 touchLocation = m_scene->convertTouchToNodeSpace(&t);
	Rect bbox = Rect(0, 0, nodeSize.width, nodeSize.height);
	Vec2 locationInNodeSpace = ccEvnt->getCurrentTarget()->convertToNodeSpace(touchLocation);

	if (bbox.containsPoint(locationInNodeSpace))
	{
		//this needs testing not sure if did ok
		return true;
	}

	return false;
}

void MapSystem::onTouchEnded(const cocos2d::Touch * touch, cocos2d::Event * ccEvnt)
{
	auto hudC = m_registry->try_get<HudComponent>(m_localEntt);
	auto mapC = m_registry->try_get<MapComponent>(m_localEntt);
	auto posC = m_registry->try_get<PositionComponent>(m_localEntt);

	if (!posC || !mapC || !hudC)
	{
		return;
	}

	Touch t = *touch;
	Size nodeSize = hudC->_clippingSize;
	Vec2 touchLocation = m_scene->convertTouchToNodeSpace(&t);
	Rect bbox = Rect(0, 0, nodeSize.width, nodeSize.height);
	Vec2 locationInNodeSpace = ccEvnt->getCurrentTarget()->convertToNodeSpace(touchLocation);

	if (bbox.containsPoint(locationInNodeSpace))
	{
		//this needs testing not sure if did ok

		Size viewSize = m_director->getWinSize();
		auto posOffset = m_director->convertToGL(touch->getLocation());

		posOffset.x -= 10;
		posOffset.y += 45;

		Vec2 mapCordinate = mapC->_map->convertToNodeSpace(posOffset);
		//cocos2d::log("[MAP SYSTEM] mousePosOffset convertToNodeSpace: %f, %f", mousePosOffset.x, mousePosOffset.y);
		int tileX = mapCordinate.x / mapC->_map->getTileSize().width;
		int tileY = (viewSize.height - mapCordinate.y) / mapC->_map->getTileSize().height;

		//cocos2d::log("[MAP SYSTEM] Casted: %d, %d", tileX, tileY);

		tileX -= 8 - posC->_x;
		tileY -= 6 - posC->_y;

		mapC->_lastTouch = Vec2(tileX, tileY);

		//cocos2d::log("[MAP SYSTEM] Casted: %d, %d", tileX, tileY);

		return;
	}
}*/
