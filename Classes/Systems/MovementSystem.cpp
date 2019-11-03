#include "MovementSystem.h"

#include "Components/SpriteComponent.h"

#include "cocos2d.h"

MovementSystem::MovementSystem()
{
	cocos2d::log("%s Constructor", "[MOVEMENT SYSTEM]");

	m_director = cocos2d::Director::getInstance();

	m_compatibleComponents.push_back(ComponentType::SPRITE);

	m_entityManager = ECS::ECSEngine::GetInstance()->GetEntityManager();

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

void MovementSystem::moveNorth(int eid,  cocos2d::Event* ccevnt, SLNet::BitStream* bs)
{
	move(Direction::North, eid);
}

void MovementSystem::moveEast(int eid,  cocos2d::Event* ccevnt, SLNet::BitStream* bs)
{
	move(Direction::East, eid);
}

void MovementSystem::moveSouth(int eid,  cocos2d::Event* ccevnt, SLNet::BitStream* bs)
{
	move(Direction::South, eid);
}

void MovementSystem::moveWest(int eid,  cocos2d::Event* ccevnt, SLNet::BitStream* bs)
{
	move(Direction::West, eid);
}

void MovementSystem::move(Direction dir, int eid)
{
	for (auto it : m_entityManager->getEntity(eid)->getComponents(ComponentType::SPRITE))
	{
		cocos2d::Sprite* spr = (reinterpret_cast<SpriteComponent*>(it))->_sprite;

		if (!(reinterpret_cast<SpriteComponent*>(it))->_moving)
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
			(reinterpret_cast<SpriteComponent*>(it))->_moving = true;

			cocos2d::DelayTime* pause = cocos2d::DelayTime::create(0.2f - 0.02f);
			cocos2d::Action* action;
			cocos2d::CallFuncN* CallBack = cocos2d::CallFuncN::create(CC_CALLBACK_0(MovementSystem::stopMoving, this, eid));
			action = cocos2d::Sequence::create(pause, CallBack, nullptr);
			spr->runAction(action);
		}
	}
}

void MovementSystem::stopMoving(int eid)
{
	for (auto it : m_entityManager->getEntity(eid)->getComponents(ComponentType::SPRITE))
		(reinterpret_cast<SpriteComponent*>(it))->_moving = false;
}
