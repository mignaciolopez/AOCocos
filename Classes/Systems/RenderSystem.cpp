#include "RenderSystem.h"

#include "Components/PlayerBodyComponent.h"

#include "cocos2d.h"

RenderSystem::RenderSystem()
{
	cocos2d::log("%s Constructor", "[RENDER SYSTEM]");

	m_entiyManager = ECS::ECS_Engine::getInstance()->getEntityManager();
	
	m_director = cocos2d::Director::getInstance();

	m_eventManager = ECS::ECS_Engine::getInstance()->getEventManager(); //del if not used
}

RenderSystem::~RenderSystem()
{
	cocos2d::log("%s Destructor", "[RENDER SYSTEM]");
}

void RenderSystem::Update()
{
	for (auto entity : *m_entiyManager->getEntities())
	{
		for (auto it : entity.second->getComponents(ComponentType::PLAYER_BODY))
		{
				cocos2d::Sprite* spr = (reinterpret_cast<PlayerBodyComponent*>(it))->_sprite;

			if (spr->getParent() != m_director->getRunningScene())
				m_director->getRunningScene()->addChild(spr);
		}
	}
}
