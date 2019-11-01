#include "RenderSystem.h"

#include "Components/SpriteComponent.h"

#include "cocos2d.h"

RenderSystem::RenderSystem()
{
	cocos2d::log("%s Constructor", "[RENDER SYSTEM]");

	m_componentManager = ECS::ECSEngine::GetInstance()->GetComponentManager();
	
	m_director = cocos2d::Director::getInstance();

	m_compatibleComponents.push_back(ComponentType::SPRITE);

	m_eventManager = ECS::ECSEngine::GetInstance()->getEventManager(); //del if not used
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
		for (auto componentID : m_componentManager->getComponentsOfType(compatibleComponent))
		{
			cocos2d::Sprite* spr;

			spr = (reinterpret_cast<SpriteComponent*>
					(m_componentManager->getComponent(componentID)))->_sprite;			
				
			if (spr->getParent() != m_director->getRunningScene())
				m_director->getRunningScene()->addChild(spr);
		}
	}
}
