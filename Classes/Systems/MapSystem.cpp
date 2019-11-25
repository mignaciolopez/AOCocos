#include "MapSystem.h"

USING_NS_CC;

MapSystem::MapSystem()
{
	cocos2d::log("%s Constructor", "[MAP SYSTEM]");

	m_director = cocos2d::Director::getInstance();
	m_entityManager = ECS::ECS_Engine::getInstance()->getEntityManager();
	m_eventManager = ECS::ECS_Engine::getInstance()->getEventManager();

	m_eventManager->Subscribe(EVENTS::MY_EID, &MapSystem::setLocaleid, this);
	m_eventManager->Subscribe(EVENTS::MAP_CHILD_ADD, &MapSystem::addeidChild, this);
	m_eventManager->Subscribe(EVENTS::MAP_CHILD_REMOVE, &MapSystem::removeChild, this);

	m_eventManager->Subscribe(EVENTS::MAP_CREATE, &MapSystem::createMapC, this);
	m_eventManager->Subscribe(EVENTS::MAP_LOAD, &MapSystem::loadMap, this);

	m_eventManager->Subscribe(EVENTS::MAP_CAN_MOVE, &MapSystem::canMove, this);

	m_eventManager->Subscribe(EVENTS::MAP_TOGGLE_DEBUG, &MapSystem::toggleDebug, this);

	m_localeid = -1;
}

MapSystem::~MapSystem()
{
	m_entityManager->removeComponent(m_localeid, ComponentType::MAP);
#if _DEBUG
	cocos2d::log("%s Destructor", "[MAP SYSTEM]");
#endif
}

void MapSystem::Update()
{
	if (m_localeid == -1)
		return;

	for (auto eit : *m_entityManager->getEntities())
	{
		auto p = m_entityManager->getComp(eit.first, ComponentType::PLAYER_BODY)->getBodySpr()->getPosition();
		p = CC_POINT_POINTS_TO_PIXELS(p);
		float newZ = 20 - ((p.y-20) / 32); //tiles in Y - ((p.y-Tiles in Y) / Tile Height);
		m_entityManager->getComp(m_localeid, MAP)->getMap()->reorderChild( //localeid is the only one entity who has a map, remote ones dont, this is not wrong
		m_entityManager->getComp(eit.first, ComponentType::PLAYER_BODY)->getBodySpr(), newZ);
	}
}

void MapSystem::setLocaleid(int eid, cocos2d::Event * ccevnt, SLNet::BitStream * bs)
{
	m_localeid = eid;
}

void MapSystem::addeidChild(int eid, cocos2d::Event * ccevnt, SLNet::BitStream * bs)
{
	if (m_entityManager->getComp(eid, PLAYER_BODY)->getBodySpr()->getParent() !=
		m_currentMapC->getMap())
		m_currentMapC->getMap()->addChild(m_entityManager->getComp(eid, PLAYER_BODY)->getBodySpr());
}

void MapSystem::removeChild(int eid, cocos2d::Event * ccevnt, SLNet::BitStream * bs)
{
	if (m_entityManager->getComp(eid, PLAYER_BODY)->getBodySpr()->getParent() ==
		m_currentMapC->getMap())
		m_currentMapC->getMap()->removeChild(m_entityManager->getComp(eid, PLAYER_BODY)->getBodySpr());
}

void MapSystem::createMapC(int eid, cocos2d::Event * ccevnt, SLNet::BitStream * bs)
{
	m_currentMapC = new (std::nothrow) MapComponent;

	m_entityManager->AddComponentToEntity(eid, m_currentMapC);

	//Just to emulate what server should say ******remove
	SLNet::BitStream _bs;
	SLNet::RakString rs = "Map1.tmx";
	_bs.Write(rs);

	m_eventManager->execute(EVENTS::MAP_LOAD, eid, nullptr, &_bs);
}

void MapSystem::loadMap(int eid, cocos2d::Event * ccevnt, SLNet::BitStream * bs)
{
	if (!bs)
		return;

	SLNet::RakString mapName;
	bs->Read(mapName);
	
	if (mapName.GetLength() <= 0)
		return;

	std::string path = cocos2d::FileUtils::getInstance()->fullPathForFilename(mapName.C_String());

	if (m_currentMapC->getMap())
	{
		if (m_currentMapC->getMap()->getParent() == m_entityManager->getComp(eid, LAYER3D)->getLayer())
			m_entityManager->getComp(eid, LAYER3D)->getLayer()->removeChild(m_currentMapC->getMap());
	}

	m_currentMapC->setMap(cocos2d::TMXTiledMap::create(path));
	
	if (m_currentMapC->getMap())
		m_currentMapC->getMap()->retain();

	m_currentMapC->getMap()->getLayer("blocks")->setVisible(false);

	m_entityManager->getComp(eid, LAYER3D)->getLayer()->addChild(m_currentMapC->getMap(), 0);
	m_currentMapC->getMap()->setCameraMask(static_cast<int>(CameraFlag::USER2));

	Vec2 mapPos = m_entityManager->getComp(eid, PLAYER_BODY)->getBodySpr()->getPosition();

	m_currentMapC->getMap()->setPosition3D(cocos2d::Vec3::ZERO);
	//m_currentMapC->getMap()->setPosition3D(cocos2d::Vec3(208.0f + 6 -mapPos.x, 416.0f / 2.0f + 32 - mapPos.y, 0.0f));
	//m_currentMapC->getMap()->setRotation3D(Vec3(-90, 0, 0));
	m_currentMapC->getMap()->setAnchorPoint(Vec2(0.0f, 0.0f));
}

void MapSystem::canMove(int eid, cocos2d::Event * ccevnt, SLNet::BitStream * bs)
{
	int nx = m_entityManager->getComp(eid, POSITION)->getX();
	int ny = m_entityManager->getComp(eid, POSITION)->getY();

	int tilesY = m_currentMapC->getMap()->getMapSize().height - 1;

	m_entityManager->getComp(m_localeid, PLAYER_BODY)->setCanWalk(true);

	switch (m_entityManager->getComp(m_localeid, PLAYER_BODY)->getDirection())
	{
	case Direction::North:
		ny++;
		break;
	case Direction::East:
		nx++;
		break;
	case Direction::South:
		ny--;
		break;
	case Direction::West:
		nx--;
		break;
	default:
		break;
	}

	//cocos2d::log("Next: (%i, %i)", nx, ny);
	for (auto e : *m_entityManager->getEntities())
	{
		if (eid == e.first)
			continue;
		if (m_entityManager->getComp(e.first, POSITION)->getX() == nx &&
			m_entityManager->getComp(e.first, POSITION)->getY() == ny)
		{
			m_entityManager->getComp(m_localeid, PLAYER_BODY)->setCanWalk(false);
			return;
		}
	}

	if (nx < 0 || ny < 0 || nx > 19 || ny > 19)
		m_entityManager->getComp(m_localeid, PLAYER_BODY)->setCanWalk(false);
	else if (m_currentMapC->getMap()->getLayer("blocks")->getTileAt(Vec2(nx, tilesY - ny)))
		m_entityManager->getComp(m_localeid, PLAYER_BODY)->setCanWalk(false);
}

void MapSystem::toggleDebug(int eid, cocos2d::Event * ccevnt, SLNet::BitStream * bs)
{
	if (m_currentMapC->getMap()->getLayer("blocks")->isVisible())
		m_currentMapC->getMap()->getLayer("blocks")->setVisible(false);
	else
		m_currentMapC->getMap()->getLayer("blocks")->setVisible(true);
}
