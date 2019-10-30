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
	m_eventManager->Subscribe(EVENTS::MOVE_NORTH, &RenderSystem::moveNorth, this);
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

void RenderSystem::moveNorth(unsigned int eid, unsigned int cid)
{
	cocos2d::Sprite* spr = (reinterpret_cast<SpriteComponent*>
		(m_componentManager->getComponent(cid)))->_sprite;

	if (!(reinterpret_cast<SpriteComponent*>(m_componentManager->getComponent(cid)))->_moving)
	{
		cocos2d::MoveBy* move = cocos2d::MoveBy::create(0.2f, cocos2d::Vec2(0.0f, 32.0f));
		spr->runAction(move);
		(reinterpret_cast<SpriteComponent*>(m_componentManager->getComponent(cid)))->_moving = true;

		cocos2d::DelayTime* pause = cocos2d::DelayTime::create(0.2f - 0.02f);
		cocos2d::Action* action;
		cocos2d::CallFuncN* CallBack = cocos2d::CallFuncN::create(CC_CALLBACK_0(RenderSystem::stopMoving, this, cid));
		action = cocos2d::Sequence::create(pause, CallBack, nullptr);
		spr->runAction(action);
	}
	
}

void RenderSystem::stopMoving(unsigned int cid)
{
	(reinterpret_cast<SpriteComponent*>(m_componentManager->getComponent(cid)))->_moving = false;
}
