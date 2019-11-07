#include "RenderSystem.h"

#include "Components/PlayerBodyComponent.h"

#include "cocos2d.h"

RenderSystem::RenderSystem()
{
	cocos2d::log("%s Constructor", "[RENDER SYSTEM]");

	m_entityManager = ECS::ECS_Engine::getInstance()->getEntityManager();
	
	m_director = cocos2d::Director::getInstance();

	m_eventManager = ECS::ECS_Engine::getInstance()->getEventManager(); //del if not used
}

RenderSystem::~RenderSystem()
{
	cocos2d::log("%s Destructor", "[RENDER SYSTEM]");
}

void RenderSystem::Update()
{
	for (auto it : *m_entityManager->getEntities())
	{
		if (m_entityManager->getComp(it.first, ComponentType::PLAYER_BODY)
			->getBody()->getParent() != m_director->getRunningScene())
			m_director->getRunningScene()->addChild(
				m_entityManager->getComp(it.first, PLAYER_BODY)->getBody());
	}
}
