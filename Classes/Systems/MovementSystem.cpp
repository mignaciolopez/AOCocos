#include "MovementSystem.h"

#include "Components/SpriteComponent.h"

#include "cocos2d.h"

MovementSystem::MovementSystem()
{
	cocos2d::log("%s Constructor", "[MOVEMENT SYSTEM]");

	m_componentManager = ECS::ECSEngine::GetInstance()->GetComponentManager();

	m_director = cocos2d::Director::getInstance();

	m_compatibleComponents.push_back(ComponentType::SPRITE);

	m_eventManager = ECS::ECSEngine::GetInstance()->getEventManager();
	m_eventManager->Subscribe(EVENTS::MOVE_NORTH, &MovementSystem::moveNorth, this);
	m_eventManager->Subscribe(EVENTS::MOVE_EAST, &MovementSystem::moveEast, this);
	m_eventManager->Subscribe(EVENTS::MOVE_SOUTH, &MovementSystem::moveSouth, this);
	m_eventManager->Subscribe(EVENTS::MOVE_WEST, &MovementSystem::moveWest, this);
}

MovementSystem::~MovementSystem()
{
	cocos2d::log("%s Destructor", "[MOVEMENT SYSTEM]");
}

void MovementSystem::Update()
{
	//cocos2d::log("%s Update", LOGID);
}

void MovementSystem::moveNorth(unsigned int eid, unsigned int cid, cocos2d::Event* ccevnt)
{
	move(Direction::North, eid, cid);
}

void MovementSystem::moveEast(unsigned int eid, unsigned int cid, cocos2d::Event* ccevnt)
{
	move(Direction::East, eid, cid);
}

void MovementSystem::moveSouth(unsigned int eid, unsigned int cid, cocos2d::Event* ccevnt)
{
	move(Direction::South, eid, cid);
}

void MovementSystem::moveWest(unsigned int eid, unsigned int cid, cocos2d::Event* ccevnt)
{
	move(Direction::West, eid, cid);
}

void MovementSystem::move(Direction dir, unsigned int eid, unsigned int cid)
{
	cocos2d::Sprite* spr = (reinterpret_cast<SpriteComponent*>
		(m_componentManager->getComponent(cid)))->_sprite;

	if (!(reinterpret_cast<SpriteComponent*>(m_componentManager->getComponent(cid)))->_moving)
	{
		float x = 0, y = 0;
		switch (dir)
		{
		case North:
			y = 32.0f;
			break;
		case East:
			x = 32.0f;
			break;
		case South:
			y = -32.0f;
			break;
		case West:
			x = -32.0f;
			break;
		}
		cocos2d::MoveBy* move = cocos2d::MoveBy::create(0.2f, cocos2d::Vec2(x, y));
		spr->runAction(move);
		(reinterpret_cast<SpriteComponent*>(m_componentManager->getComponent(cid)))->_moving = true;

		cocos2d::DelayTime* pause = cocos2d::DelayTime::create(0.2f - 0.02f);
		cocos2d::Action* action;
		cocos2d::CallFuncN* CallBack = cocos2d::CallFuncN::create(CC_CALLBACK_0(MovementSystem::stopMoving, this, cid));
		action = cocos2d::Sequence::create(pause, CallBack, nullptr);
		spr->runAction(action);
	}

}

void MovementSystem::stopMoving(unsigned int cid)
{
	(reinterpret_cast<SpriteComponent*>(m_componentManager->getComponent(cid)))->_moving = false;
}
