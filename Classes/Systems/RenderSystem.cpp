#include "RenderSystem.h"

#include "Components/ComponentsList.h"
#include "ECS/ECSEngine.h"
#include "ECS/Entities/Entity.h"
#include "Components/BodyComponent.h"

#include "cocos2d.h"

#define LOGID "[RENDER SYSTEM]"

RenderSystem::RenderSystem()
{
	cocos2d::log("%s Constructor", LOGID);

	m_compatibleComponents.push_back(ComponentType::BODYCOMPONENT);
}

RenderSystem::~RenderSystem()
{
	cocos2d::log("%s Destructor", LOGID);
}

void RenderSystem::Update()
{
	//cocos2d::log("%s Update", LOGID);

	for (auto comp : m_compatibleComponents)
	{
		for (auto entity :
			ECS::ECSEngine::GetInstance()->GetEntityManager()->
			GetEntitiesWithComponent(comp))
		{
			for (auto compType : entity->GetComponentsOfType(comp))
			{
				cocos2d::Sprite* spr = (reinterpret_cast<BodyComponent*>(compType))->_bodySprite;
				
				if (spr->getParent() != cocos2d::Director::getInstance()->getRunningScene())
					cocos2d::Director::getInstance()->getRunningScene()->addChild(spr);
			}
		}
	}
}