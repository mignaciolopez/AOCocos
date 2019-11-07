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
		m_director->getRunningScene()->getDefaultCamera()->setPosition(
			m_entityManager->getComp(m_localeid, ComponentType::PLAYER_BODY)
			->getBodySpr()->getPosition());
	}

	for (auto it : *m_entityManager->getEntities())
	{
		if (m_entityManager->getComp(it.first, ComponentType::PLAYER_BODY)
			->getBodySpr()->getParent() != m_director->getRunningScene())
			m_director->getRunningScene()->addChild(
				m_entityManager->getComp(it.first, PLAYER_BODY)->getBodySpr());
	}

}

void RenderSystem::setLocalEntity(int eid, cocos2d::Event * ccevnt, SLNet::BitStream * bs)
{
	m_localeid = eid;
}
