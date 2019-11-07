#include "AnimationSystem.h"

#include "Components/PlayerBodyComponent.h"

AnimationSystem::AnimationSystem()
{
	cocos2d::log("%s Constructor", "[ANIMATION SYSTEM]");

	m_director = cocos2d::Director::getInstance();
	m_entityManager = ECS::ECS_Engine::getInstance()->getEntityManager();
	m_eventManager = ECS::ECS_Engine::getInstance()->getEventManager();
}

AnimationSystem::~AnimationSystem()
{
	cocos2d::log("%s Destructor", "[ANIMATION SYSTEM]");
}

void AnimationSystem::Update()
{
	for (auto entity : *m_entityManager->getEntities())
	{
		
	}
}
