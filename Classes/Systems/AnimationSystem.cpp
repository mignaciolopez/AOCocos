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
		for (auto it : entity.second->getComponents(ComponentType::PLAYER_BODY))
		{
			cocos2d::Sprite* spr = (reinterpret_cast<PlayerBodyComponent*>(it))->_sprite;

			if (spr->getParent() != m_director->getRunningScene())
				m_director->getRunningScene()->addChild(spr);
		}
	}
}
