#include "RenderSystem.h"

#include "Components/PlayerBodyComponent.h"

#include "cocos2d.h"

RenderSystem::RenderSystem()
{
	cocos2d::log("%s Constructor", "[RENDER SYSTEM]");

	m_entityManager = ECS::ECS_Engine::getInstance()->getEntityManager();
	
	m_director = cocos2d::Director::getInstance();

	m_eventManager = ECS::ECS_Engine::getInstance()->getEventManager(); //del if not used

	m_eventManager->Subscribe(EVENTS::MY_EID, &RenderSystem::setLocalEntity, this);

	m_localeid = -1;
}

RenderSystem::~RenderSystem()
{
	cocos2d::log("%s Destructor", "[RENDER SYSTEM]");
}

void RenderSystem::Update()
{
	if (m_localeid != -1)
	{
		cocos2d::Vec2 pos = m_entityManager->getComp(m_localeid, ComponentType::PLAYER_BODY)
			->getBodySpr()->getPosition();

		for (auto cam : m_director->getRunningScene()->getCameras())
		{
			cam->setPosition3D(cocos2d::Vec3(pos.x, pos.y, 500));
			cam->lookAt(cocos2d::Vec3(pos.x, pos.y, 10));
			cam->setRotation3D(cocos2d::Vec3::ZERO);
		}
		//m_director->getRunningScene()->getDefaultCamera()->setPosition(
			//m_entityManager->getComp(m_localeid, ComponentType::PLAYER_BODY)
			//->getBodySpr()->getPosition());
	}

	/*for (auto it : *m_entityManager->getEntities())
	{
		if (m_entityManager->getComp(it.first, ComponentType::PLAYER_BODY)
			->getBodySpr()->getParent() != m_director->getRunningScene()->getChildByTag(123))
			m_director->getRunningScene()->getChildByTag(123)->addChild(
				m_entityManager->getComp(it.first, PLAYER_BODY)->getBodySpr());
	}*/

}

void RenderSystem::setLocalEntity(int eid, cocos2d::Event * ccevnt, SLNet::BitStream * bs)
{
	m_localeid = eid;
}
