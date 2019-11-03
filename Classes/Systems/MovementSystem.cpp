#include "MovementSystem.h"

#include "Components/SpriteComponent.h"
#include "Components/PositionComponent.h"

#include "cocos2d.h"

MovementSystem::MovementSystem()
{
	cocos2d::log("%s Constructor", "[MOVEMENT SYSTEM]");

	m_director = cocos2d::Director::getInstance();

	m_compatibleComponents.push_back(ComponentType::SPRITE);
	m_compatibleComponents.push_back(ComponentType::POSITION);

	m_entityManager = ECS::ECSEngine::GetInstance()->GetEntityManager();

	m_eventManager = ECS::ECSEngine::GetInstance()->getEventManager();
	m_eventManager->Subscribe(EVENTS::MOVE_NORTH, &MovementSystem::moveNorth, this);
	m_eventManager->Subscribe(EVENTS::MOVE_EAST, &MovementSystem::moveEast, this);
	m_eventManager->Subscribe(EVENTS::MOVE_SOUTH, &MovementSystem::moveSouth, this);
	m_eventManager->Subscribe(EVENTS::MOVE_WEST, &MovementSystem::moveWest, this);

	m_eventManager->Subscribe(EVENTS::MY_EID, &MovementSystem::setLocalEntity, this);

	m_localEntity = -1;
}

MovementSystem::~MovementSystem()
{
	cocos2d::log("%s Destructor", "[MOVEMENT SYSTEM]");
}

void MovementSystem::Update()
{
	//cocos2d::log("%s Update", LOGID);
	for (auto& it = m_pendingMoves.begin(); it != m_pendingMoves.end() /* not hoisted */; /* no increment */)
	{
		if (it->second->size() > 0)
		{
			if (moveRemote(*it->second->begin(), it->first))
				it->second->erase(it->second->begin());
			++it;
		}
		else
		{
			delete it->second;
			it->second = nullptr;
			m_pendingMoves.erase(it++);
		}
	}
}

void MovementSystem::moveNorth(int eid, cocos2d::Event* ccevnt, SLNet::BitStream* bs)
{
	move(Direction::North, eid);
}

void MovementSystem::moveEast(int eid, cocos2d::Event* ccevnt, SLNet::BitStream* bs)
{
	move(Direction::East, eid);
}

void MovementSystem::moveSouth(int eid, cocos2d::Event* ccevnt, SLNet::BitStream* bs)
{
	move(Direction::South, eid);
}

void MovementSystem::moveWest(int eid, cocos2d::Event* ccevnt, SLNet::BitStream* bs)
{
	move(Direction::West, eid);
}

void MovementSystem::move(Direction dir, int eid)
{
	if (!m_entityManager->getEntity(eid)) //Workaround
		return;

	if (eid == m_localEntity)
	{
		//this means the move comes from the inputSystem
		for (auto it : m_entityManager->getEntity(eid)->getComponents(ComponentType::SPRITE))
		{
			if (!(reinterpret_cast<SpriteComponent*>(it))->_moving)
			{
				cocos2d::Sprite* spr = (reinterpret_cast<SpriteComponent*>(it))->_sprite;
				SLNet::BitStream bsOut;
				float x = 0, y = 0;
				switch (dir)
				{
				case North:
					y = 32.0f;
					bsOut.Write((SLNet::MessageID)EVENTS::MOVE_NORTH);
					bsOut.Write(m_localEntity);
					m_eventManager->execute(EVENTS::SEND_SERVER, m_localEntity, nullptr, &bsOut);
					break;
				case East:
					x = 32.0f;
					bsOut.Write((SLNet::MessageID)EVENTS::MOVE_EAST);
					bsOut.Write(m_localEntity);
					m_eventManager->execute(EVENTS::SEND_SERVER, m_localEntity, nullptr, &bsOut);
					break;
				case South:
					y = -32.0f;
					bsOut.Write((SLNet::MessageID)EVENTS::MOVE_SOUTH);
					bsOut.Write(m_localEntity);
					m_eventManager->execute(EVENTS::SEND_SERVER, m_localEntity, nullptr, &bsOut);
					break;
				case West:
					x = -32.0f;
					bsOut.Write((SLNet::MessageID)EVENTS::MOVE_WEST);
					bsOut.Write(m_localEntity);
					m_eventManager->execute(EVENTS::SEND_SERVER, m_localEntity, nullptr, &bsOut);
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

				for (auto it : m_entityManager->getEntity(eid)->getComponents(ComponentType::POSITION))
				{
					(reinterpret_cast<PositionComponent*>(it))->_x = spr->getPosition().x + x;
					(reinterpret_cast<PositionComponent*>(it))->_y = spr->getPosition().y + y;
				}
			}
		}
	}
	else
	{
		//It means it comes from server and is a remote player
		if (m_pendingMoves.find(eid) == m_pendingMoves.end())
		{
			std::vector<Direction>* vec = new (std::nothrow) std::vector<Direction>;
			vec->push_back(dir);
			m_pendingMoves.emplace(eid, vec);
		}
		else
		{
			m_pendingMoves.at(eid)->push_back(dir);
		}
	}
}

bool MovementSystem::moveRemote(Direction dir, int eid)
{
	if (!m_entityManager->getEntity(eid)) //Workaround
		return true;

	bool returnFlag = true;

	for (auto it : m_entityManager->getEntity(eid)->getComponents(ComponentType::SPRITE))
	{
		if (!(reinterpret_cast<SpriteComponent*>(it))->_moving)
		{
			cocos2d::Sprite* spr = (reinterpret_cast<SpriteComponent*>(it))->_sprite;
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

			for (auto it : m_entityManager->getEntity(eid)->getComponents(ComponentType::POSITION))
			{
				(reinterpret_cast<PositionComponent*>(it))->_x = spr->getPosition().x + x;
				(reinterpret_cast<PositionComponent*>(it))->_y = spr->getPosition().y + y;
			}
		}
		else
			returnFlag = false;
	}
	return returnFlag;
}

void MovementSystem::stopMoving(int eid)
{
	for (auto it : m_entityManager->getEntity(eid)->getComponents(ComponentType::SPRITE))
		(reinterpret_cast<SpriteComponent*>(it))->_moving = false;
}

void MovementSystem::setLocalEntity(int eid, cocos2d::Event * ccevent, SLNet::BitStream * bs)
{
	m_localEntity = eid;
}
