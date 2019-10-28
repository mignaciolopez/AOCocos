#include "RenderSystem.h"

#include "Components/BodyComponent.h"
#include "Components/HeadComponent.h"

#include "cocos2d.h"

#define LOGID "[RENDER SYSTEM]"

RenderSystem::RenderSystem()
{
	cocos2d::log("%s Constructor", LOGID);

	m_componentManager = ECS::ECSEngine::GetInstance()->GetComponentManager();
	
	m_director = cocos2d::Director::getInstance();

	m_compatibleComponents.push_back(ComponentType::BODYCOMPONENT);
	m_compatibleComponents.push_back(ComponentType::HEADCOMPONENT);
}

RenderSystem::~RenderSystem()
{
	cocos2d::log("%s Destructor", LOGID);
}

void RenderSystem::Update()
{
	//cocos2d::log("%s Update", LOGID);

	for (auto compatibleComponent : m_compatibleComponents)
	{
		for (auto componentID : m_componentManager->getComponentsOfType(compatibleComponent))
		{
			cocos2d::Sprite* spr;
			if (compatibleComponent == ComponentType::BODYCOMPONENT)
			{
				spr = (reinterpret_cast<BodyComponent*>
					(m_componentManager->getComponent(componentID)))->_bodySprite;
			}
			else if (compatibleComponent == ComponentType::HEADCOMPONENT)
			{
				spr = (reinterpret_cast<HeadComponent*>
					(m_componentManager->getComponent(componentID)))->_sprite;
			}
			
				
			if (spr->getParent() != m_director->getRunningScene())
				m_director->getRunningScene()->addChild(spr);
		}
	}
}