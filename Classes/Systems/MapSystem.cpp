#include "MapSystem.h"

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

	m_localeid = -1;
}

MapSystem::~MapSystem()
{
	m_entityManager->removeComponent(m_localeid, ComponentType::MAP);

	cocos2d::log("%s Destructor", "[MAP SYSTEM]");
}

void MapSystem::Update()
{
	if (m_localeid == -1)
		return;

	for (auto eit : *m_entityManager->getEntities())
	{
		auto p = m_entityManager->getComp(eit.first, ComponentType::PLAYER_BODY)->getBodySpr()->getPosition();
		p = CC_POINT_POINTS_TO_PIXELS(p);
		float newZ = 20 - ((p.y-20) / 32);
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

	m_currentMapC->setMap(cocos2d::experimental::TMXTiledMap::create(path));
	
	if (m_currentMapC->getMap())
		m_currentMapC->getMap()->retain();

	m_entityManager->getComp(eid, LAYER3D)->getLayer()->addChild(m_currentMapC->getMap(), 0);
	m_currentMapC->getMap()->setPosition3D(cocos2d::Vec3::ZERO);
}