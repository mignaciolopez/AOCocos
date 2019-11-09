#include "MapSystem.h"

MapSystem::MapSystem()
{
	cocos2d::log("%s Constructor", "[MAP SYSTEM]");

	m_director = cocos2d::Director::getInstance();
	m_entityManager = ECS::ECS_Engine::getInstance()->getEntityManager();
	m_eventManager = ECS::ECS_Engine::getInstance()->getEventManager();

	m_eventManager->Subscribe(EVENTS::MY_EID, &MapSystem::setLocaleid, this);
	m_eventManager->Subscribe(EVENTS::LOAD_MAP, &MapSystem::loadMap, this);

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
		if (m_entityManager->getComp(eit.first, ComponentType::PLAYER_BODY)
			->getBodySpr()->getParent() != m_entityManager->getComp(m_localeid, MAP)->getMap())
			m_entityManager->getComp(m_localeid, MAP)->getMap()->addChild(
				m_entityManager->getComp(eit.first, PLAYER_BODY)->getBodySpr());

		auto p = m_entityManager->getComp(eit.first, ComponentType::PLAYER_BODY)->getBodySpr()->getPosition();
		p = CC_POINT_POINTS_TO_PIXELS(p);
		float newZ = 20 - ((p.y-20) / 32);
		m_entityManager->getComp(m_localeid, MAP)->getMap()->reorderChild(
		m_entityManager->getComp(eit.first, ComponentType::PLAYER_BODY)->getBodySpr(), newZ);
	}
}

void MapSystem::setLocaleid(int eid, cocos2d::Event * ccevnt, SLNet::BitStream * bs)
{
	m_localeid = eid;

	m_currentMapC = new (std::nothrow) MapComponent;

	m_entityManager->AddComponentToEntity(eid, m_currentMapC);

	//Just to emulate what server should say
	SLNet::BitStream _bs;
	SLNet::RakString rs = "Map1.tmx";
	_bs.Write(rs);
	m_eventManager->execute(EVENTS::LOAD_MAP, eid, nullptr, &_bs);
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

	if (m_entityManager->getComp(m_localeid, MAP)->getMap())
	{
		if (m_entityManager->getComp(m_localeid, MAP)->getMap()->getParent() == m_director->getRunningScene())
			m_director->getRunningScene()->removeChild(m_entityManager->getComp(m_localeid, MAP)->getMap());
	}

	m_entityManager->getComp(m_localeid, MAP)->setMap(cocos2d::experimental::TMXTiledMap::create(path));
	m_entityManager->getComp(m_localeid, MAP)->getMap()->retain();
	m_director->getRunningScene()->getChildByTag(123)->addChild(m_entityManager->getComp(m_localeid, MAP)->getMap(), 0);
	m_entityManager->getComp(m_localeid, MAP)->getMap()->setPosition3D(cocos2d::Vec3::ZERO);
}
