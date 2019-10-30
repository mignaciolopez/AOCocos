#include "RenderSystem.h"

#include "Components/SpriteComponent.h"

#include "cocos2d.h"

#define LOGID "[RENDER SYSTEM]"

RenderSystem::RenderSystem()
{
	cocos2d::log("%s Constructor", LOGID);

	m_componentManager = ECS::ECSEngine::GetInstance()->GetComponentManager();
	
	m_director = cocos2d::Director::getInstance();

	m_compatibleComponents.push_back(ComponentType::SPRITE);

	m_eventManager = ECS::ECSEngine::GetInstance()->getEventManager();
	m_eventManager->Subscribe(EVENTS::MOVE, &RenderSystem::spawn, this);
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

			spr = (reinterpret_cast<SpriteComponent*>
					(m_componentManager->getComponent(componentID)))->_sprite;			
				
			if (spr->getParent() != m_director->getRunningScene())
				m_director->getRunningScene()->addChild(spr);
		}
	}
}

void RenderSystem::spawn(unsigned int eid, unsigned int cid)
{
	cocos2d::Sprite* spr = (reinterpret_cast<SpriteComponent*>
		(m_componentManager->getComponent(cid)))->_sprite;

	cocos2d::MoveBy* move = cocos2d::MoveBy::create(0.01f, cocos2d::Vec2(1.f, 1.f));
	spr->runAction(move);
}
