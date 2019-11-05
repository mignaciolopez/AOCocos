#include "RenderSystem.h"

#include "Components/SpriteComponent.h"

#include "cocos2d.h"

RenderSystem::RenderSystem()
{
	cocos2d::log("%s Constructor", "[RENDER SYSTEM]");

	m_entiyManager = ECS::ECS_Engine::getInstance()->getEntityManager();
	
	m_director = cocos2d::Director::getInstance();

	m_compatibleComponents.push_back(ComponentType::SPRITE);

	m_eventManager = ECS::ECS_Engine::getInstance()->getEventManager(); //del if not used
}

RenderSystem::~RenderSystem()
{
	cocos2d::log("%s Destructor", "[RENDER SYSTEM]");
}

void RenderSystem::Update()
{
	//cocos2d::log("%s Update", "[RENDER SYSTEM]");

	for (auto compatibleComponent : m_compatibleComponents)
	{
		for (auto entity : *m_entiyManager->getEntities())
		{
			for (auto it : entity.second->getComponents(ComponentType::SPRITE))
			{
				 cocos2d::Sprite* spr = (reinterpret_cast<SpriteComponent*>(it))->_sprite;

				if (spr->getParent() != m_director->getRunningScene())
					m_director->getRunningScene()->addChild(spr);
			}
		}
	}
}
