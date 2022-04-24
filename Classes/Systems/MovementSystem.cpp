#include "MovementSystem.h"

USING_NS_CC;

MovementSystem::MovementSystem(entt::registry* registry)
	: m_registry(registry)
{
#if _DEBUG
	cocos2d::log("[MovementSystem] Constructor");
#endif

	m_signalsManager = ECS::SignalsManager::getInstance();

	m_registry->on_replace<PositionComponent>().connect<&MovementSystem::onUpdatePosC>(this);

	m_signalsManager->connect<&MovementSystem::setLocalEntity>(Signals::NW_MY_ENTT, this);

	m_signalsManager->connect<&MovementSystem::moveNorth>(Signals::MOVE_NORTH, this);
	m_signalsManager->connect<&MovementSystem::moveEast>(Signals::MOVE_EAST, this);
	m_signalsManager->connect<&MovementSystem::moveSouth>(Signals::MOVE_SOUTH, this);
	m_signalsManager->connect<&MovementSystem::moveWest>(Signals::MOVE_WEST, this);

	m_signalsManager->connect<&MovementSystem::switchRemoteFacing>(Signals::SWITCH_FACING, this);

	m_signalsManager->connect<&MovementSystem::moveRenock>(Signals::MOVE_RENOCK, this);

	m_localEntt = entt::null;

	m_director = cocos2d::Director::getInstance();

	m_moveNorth = nullptr;
	m_moveEast = nullptr;
	m_moveSouth = nullptr;
	m_moveWest = nullptr;

	m_moveNorth = cocos2d::MoveBy::create(0.2f, cocos2d::Vec2(0, 32));
	m_moveEast = cocos2d::MoveBy::create(0.2f, cocos2d::Vec2(32, 0));
	m_moveSouth = cocos2d::MoveBy::create(0.2f, cocos2d::Vec2(0, -32));
	m_moveWest = cocos2d::MoveBy::create(0.2f, cocos2d::Vec2(-32, 0));

	m_moveNorth->retain();
	m_moveEast->retain();
	m_moveSouth->retain();
	m_moveWest->retain();

	m_fpsPivot = 0.02f;
}

MovementSystem::~MovementSystem()
{
#if _DEBUG
	cocos2d::log("[MovementSystem] Destructor");
#endif

	m_registry->on_replace<PositionComponent>().disconnect<&MovementSystem::onUpdatePosC>(this);

	ECS::SignalsManager::getInstance()->disconnectAll(this);

	if (m_moveNorth)
		if (m_moveNorth->getReferenceCount())
			m_moveNorth->release();

	if (m_moveEast)
		if (m_moveEast->getReferenceCount())
			m_moveEast->release();

	if (m_moveSouth)
		if (m_moveSouth->getReferenceCount())
			m_moveSouth->release();
	
	if (m_moveWest)
		if (m_moveWest->getReferenceCount())
			m_moveWest->release();
}

void MovementSystem::update(float dt)
{
	double rel = (std::min(120.0f, m_director->getFrameRate()) * 100) / 60;
	m_fpsPivot = 0.02 / (rel / 100.0);

	for (auto& e = m_entitiesToUpdate.cbegin(); e != m_entitiesToUpdate.cend();)
	{
		auto posC = m_registry->try_get<PositionComponent>(e->first);

		if (posC->_pendingMoves.size() > 0)
		{
			if (move(e->first, posC->_pendingMoves[0]))
				posC->_pendingMoves.erase(posC->_pendingMoves.begin());

			e++;
		}
		else
		{
			if (m_entitiesToUpdate.find(e->first) != m_entitiesToUpdate.end())
				e = m_entitiesToUpdate.erase(e);
		}
	}
}

void MovementSystem::onUpdatePosC(entt::registry & registry, entt::entity entity)
{
	if (m_entitiesToUpdate.find(entity) == m_entitiesToUpdate.end())
		m_entitiesToUpdate.emplace(entity, entity);
}

void MovementSystem::moveNorth(entt::entity entity, SLNet::BitStream* bs)
{
	if (entity == m_localEntt)
	{
		move(m_localEntt, Directions::North);
		return;
	}

	m_registry->replace<PositionComponent>(entity, [](auto &pos) { pos._pendingMoves.push_back(Directions::North); });

	/*if (m_registry->has<PositionComponent>(entity))
		m_registry->get<PositionComponent>(entity)._pendingMoves.push_back(Directions::North);*/
}

void MovementSystem::moveEast(entt::entity entity, SLNet::BitStream* bs)
{
	if (entity == m_localEntt)
	{
		move(m_localEntt, Directions::East);
		return;
	}

	m_registry->replace<PositionComponent>(entity, [](auto &pos) { pos._pendingMoves.push_back(Directions::East); });
	
	/*if (m_registry->has<PositionComponent>(entity))
		m_registry->get<PositionComponent>(entity)._pendingMoves.push_back(Directions::East);*/
}

void MovementSystem::moveSouth(entt::entity entity, SLNet::BitStream* bs)
{
	if (entity == m_localEntt)
	{
		move(m_localEntt, Directions::South);
		return;
	}

	m_registry->replace<PositionComponent>(entity, [](auto &pos) { pos._pendingMoves.push_back(Directions::South); });
	
	/*if (m_registry->has<PositionComponent>(entity))
		m_registry->get<PositionComponent>(entity)._pendingMoves.push_back(Directions::South);*/
}

void MovementSystem::moveWest(entt::entity entity, SLNet::BitStream* bs)
{
	if (entity == m_localEntt)
	{
		move(m_localEntt, Directions::West);
		return;
	}

	m_registry->replace<PositionComponent>(entity, [](auto &pos) { pos._pendingMoves.push_back(Directions::West); });
	
	/*if (m_registry->has<PositionComponent>(entity))
		m_registry->get<PositionComponent>(entity)._pendingMoves.push_back(Directions::West);*/
}

void MovementSystem::switchRemoteFacing(entt::entity entity,  SLNet::BitStream* bs)
{
	if (!bs)
	{
#if _DEBUG
		cocos2d::log("[MovementSystem] switchRemoteFacing bs is nullptr.");
#endif
		return;
	}

	Directions dir;
	bs->Read(dir);

	if (m_registry->has<PlayerComponent>(entity))
		m_registry->get<PlayerComponent>(entity)._direction = dir;

	m_signalsManager->publish(Signals::ANIMATE_SET_BODY_ALL, entity);
}

void MovementSystem::moveRenock(entt::entity entity,  SLNet::BitStream* bs)
{
	if (!bs)
	{
#if _DEBUG
		cocos2d::log("[MovementSystem] (moveRenock) bs is nullptr.");
#endif
		return;
	}

	auto posC = m_registry->try_get<PositionComponent>(entity);
	auto playerC = m_registry->try_get<PlayerComponent>(entity);

	if (!posC || !playerC)
	{
		return;
	}

	posC->_renocking = true;

	int mapID = 0, x = 0, y = 0;
	Directions dir = Directions::INVALID;
	bs->Read(mapID);
	bs->Read(x);
	bs->Read(y);
	bs->Read(dir);

	posC->_mapID = mapID;
	posC->_x = x;
	posC->_y = y;
	playerC->_direction = dir;

	playerC->_spriteBody->setPositionX(posC->_x * 32 + 16);
	playerC->_spriteBody->setPositionY(posC->_y * 32);

	m_signalsManager->publish(Signals::ANIMATE_SET_BODY_ALL, entity);
}

bool MovementSystem::move(entt::entity entity, Directions dir)
{
	//if (dir == Directions::INVALID)
	//	return true;

	auto posC = m_registry->try_get<PositionComponent>(entity);

	if(!posC)
		return false;

	auto playerC = m_registry->try_get<PlayerComponent>(entity);
	if (!playerC)
		return false;

	if (posC->_moving && entity == m_localEntt)
		return false;

	playerC->_direction = dir;

	SLNet::BitStream bsOut;

	switch (dir)
	{
	case Directions::East:
		//playerC->_spriteBody->reorderChild(playerC->_spriteWeapon, 3);
		//playerC->_spriteBody->reorderChild(playerC->_spriteShield, 2);
		break;
	case Directions::West:
		//playerC->_spriteBody->reorderChild(playerC->_spriteWeapon, 2);
		//playerC->_spriteBody->reorderChild(playerC->_spriteShield, 3);
		break;
	default:
		break;
	}

	if (entity == m_localEntt)
	{
		m_signalsManager->publish(Signals::MAP_CAN_MOVE, m_localEntt);
		if (!posC->_canWalk)
		{
			bsOut.Write((SLNet::MessageID)Signals::SWITCH_FACING);
			bsOut.Write(m_localEntt);
			bsOut.Write(dir);
			m_signalsManager->publish(Signals::NW_SEND_SERVER, m_localEntt, &bsOut);

			m_signalsManager->publish(Signals::ANIMATE_SET_BODY_ALL, entity);
			return true;
		}

		bsOut.Reset();
	}

	if (m_registry->has<PositionComponent>(entity))
	{
		m_registry->replace<PositionComponent>(entity, [](auto &posiC)
		{
			posiC._moving = true;
		});
	}

	int x = 0, y = 0;

	switch (dir)
	{
	case Directions::North:
		y++;
		playerC->_spriteBody->runAction(m_moveNorth->clone());
		if (entity == m_localEntt)
			bsOut.Write((SLNet::MessageID)Signals::MOVE_NORTH);
		break;
	case Directions::East:
		x++;
		playerC->_spriteBody->runAction(m_moveEast->clone());
		if (entity == m_localEntt)
			bsOut.Write((SLNet::MessageID)Signals::MOVE_EAST);
		break;
	case Directions::South:
		y--;
		playerC->_spriteBody->runAction(m_moveSouth->clone());
		if (entity == m_localEntt)
			bsOut.Write((SLNet::MessageID)Signals::MOVE_SOUTH);
		break;
	case Directions::West:
		x--;
		playerC->_spriteBody->runAction(m_moveWest->clone());
		if (entity == m_localEntt)
			bsOut.Write((SLNet::MessageID)Signals::MOVE_WEST);	
		break;
	default:
		return false;
	}

	if (entity == m_localEntt)
	{
		bsOut.Write(m_localEntt);
		m_signalsManager->publish(Signals::NW_SEND_SERVER, m_localEntt, &bsOut);
	}

	if (m_registry->has<PositionComponent>(entity))
		m_registry->replace<PositionComponent>(entity, [x, &y](auto &posiC)
	{
		if (y > 0)
		{
			posiC._y += y;
			y = 0;
		}
		posiC._x += x; 
	});
	
	

	CallFuncN* callback = CallFuncN::create(CC_CALLBACK_0(MovementSystem::stopMoving, this, entity, y));
	DelayTime* dtcb = cocos2d::DelayTime::create(m_vel - m_fpsPivot);
	Action* secuence = Sequence::create(dtcb, callback, nullptr);
	secuence->setTag(AxnTags::StopMovingSeq);
	playerC->_spriteBody->runAction(secuence);

	if (m_registry->has<FXComponent>(entity))
		m_registry->replace<FXComponent>(entity, [](auto &fxC) { fxC._FXs.push_back(FXS::WalkStep1); });

	m_signalsManager->publish(Signals::ANIMATE_WALK, entity);

	return true;
}

void MovementSystem::stopMoving(entt::entity entity, int y)
{
	/*auto posC = m_registry->try_get<PositionComponent>(entity);

	if (!posC)
		return;

	if (posC->_renocking)
	{
		auto playerC = m_registry->try_get<PlayerComponent>(entity);
		if (playerC)
		{
			playerC->_spriteBody->setPositionX(posC->_x * 32 + 16);
			playerC->_spriteBody->setPositionY(posC->_y * 32);
			posC->_renocking = false;
			posC->_moving = false;
		}
		return;
	}*/

	SLNet::BitStream bsOut;
	bsOut.Write((SLNet::MessageID)Signals::MOVE_STOP);
	bsOut.Write(m_localEntt);
	m_signalsManager->publish(Signals::NW_SEND_SERVER, m_localEntt, &bsOut);

	if (m_registry->has<PositionComponent>(entity))
		m_registry->replace<PositionComponent>(entity, [=](auto &posC)
	{
		if (posC._renocking)
		{
			if (m_registry->has<PlayerComponent>(entity))
				m_registry->replace<PlayerComponent>(entity, [=](auto &playerC)
			{
				playerC._spriteBody->setPositionX(posC._x * 32 + 16);
				playerC._spriteBody->setPositionY(posC._y * 32);
			});
			posC._renocking = false;
			posC._moving = false;
		}
		else
		{
			posC._y += y;
			posC._moving = false;
		}
	});
}

void MovementSystem::setLocalEntity(entt::entity entity, SLNet::BitStream* bs)
{
	m_localEntt = entity;
}
