#include "MovementSystem.h"

#include "Components/PositionComponent.h"
#include "Components/PlayerBodyComponent.h"

MovementSystem::MovementSystem()
{
	cocos2d::log("%s Constructor", "[MOVEMENT SYSTEM]");

	m_director = cocos2d::Director::getInstance();

	m_entityManager = ECS::ECS_Engine::getInstance()->getEntityManager();

	m_eventManager = ECS::ECS_Engine::getInstance()->getEventManager();
	m_eventManager->Subscribe(EVENTS::MOVE_NORTH, &MovementSystem::moveNorth, this);
	m_eventManager->Subscribe(EVENTS::MOVE_EAST, &MovementSystem::moveEast, this);
	m_eventManager->Subscribe(EVENTS::MOVE_SOUTH, &MovementSystem::moveSouth, this);
	m_eventManager->Subscribe(EVENTS::MOVE_WEST, &MovementSystem::moveWest, this);

	m_eventManager->Subscribe(EVENTS::SWITCH_FACING, &MovementSystem::switchRemoteFacing, this);

	m_eventManager->Subscribe(EVENTS::MY_EID, &MovementSystem::setLocalEntity, this);

	m_eventManager->Subscribe(EVENTS::MOVES_V_CREATE, &MovementSystem::createVector, this);
	m_eventManager->Subscribe(EVENTS::MOVES_V_REMOVE, &MovementSystem::removeVector, this);

	m_moveNorth = nullptr;
	m_moveEast = nullptr;
	m_moveSouth = nullptr;
	m_moveWest = nullptr;

	m_delayCallToStopMoving = nullptr;

	m_moveNorth = cocos2d::MoveBy::create(0.2f, cocos2d::Vec2(0, 32));
	m_moveEast = cocos2d::MoveBy::create(0.2f, cocos2d::Vec2(32, 0));
	m_moveSouth = cocos2d::MoveBy::create(0.2f, cocos2d::Vec2(0, -32));
	m_moveWest = cocos2d::MoveBy::create(0.2f, cocos2d::Vec2(-32, 0));

	m_moveNorth->retain();
	m_moveEast->retain();
	m_moveSouth->retain();
	m_moveWest->retain();

	m_delayCallToStopMoving = cocos2d::DelayTime::create(0.2f - 0.02f);
	m_delayCallToStopMoving->retain();

	m_delayRemote = cocos2d::DelayTime::create(0.3f);
	m_delayRemote->retain();

	m_localeid = -1;
}

MovementSystem::~MovementSystem()
{
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

	if (m_delayCallToStopMoving)
		if (m_delayCallToStopMoving->getReferenceCount())
			m_delayCallToStopMoving->release();

	if (m_delayRemote)
		if (m_delayRemote->getReferenceCount())
			m_delayRemote->release();

	for (auto move : m_pendingMoves)
	{
		if (move.second)
		{
			delete move.second;
			move.second = nullptr;
		}
	}

	cocos2d::log("%s Destructor", "[MOVEMENT SYSTEM]");
}

void MovementSystem::Update()
{
	for (auto& it = m_pendingMoves.begin(); it != m_pendingMoves.end() /* not hoisted */; /* no increment */)
	{
		if (it->second->size() > 0)
		{
			moveRemote(*it->second->begin(), it->first);
			it->second->erase(it->second->begin());
			//++it;
			break;
		}
		else
		{
			//m_entityManager->getComp(it->first, PLAYER_BODY)->setMoving(false);
			//if (m_entityManager->getComp(it->first, PLAYER_BODY))
			++it;
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

void MovementSystem::switchRemoteFacing(int eid, cocos2d::Event * ccevnt, SLNet::BitStream * bs)
{
	Direction dir;
	bs->Read(dir);
	m_entityManager->getComp(eid, PLAYER_BODY)->setDirection(dir);
	m_eventManager->execute(EVENTS::ANIMATION_SWITCH_FACING, eid, nullptr, nullptr);
}

void MovementSystem::move(Direction dir, int eid)
{
	if (!m_entityManager->getEntity(eid)) //Workaround
		return; //if this happens client should ask server to resync players
	//and check if the local player entity is ok.

	if (eid == m_localeid)
	{
		//this means the move comes from the inputSystem
		moveLocal(dir);
	}
	else
	{
		//It means it comes from server and is a remote player
		if (m_pendingMoves.find(eid) != m_pendingMoves.end())
		{
			m_pendingMoves.at(eid)->push_back(dir);
		}
	}
}

void MovementSystem::moveLocal(Direction dir)
{
	SLNet::BitStream bsOut;

	if (!m_entityManager->getComp(m_localeid, PLAYER_BODY)->getMoving() && 
		m_entityManager->getComp(m_localeid, PLAYER_BODY)->getDirection() != dir)
	{
		m_entityManager->getComp(m_localeid, PLAYER_BODY)->setDirection(dir);
		m_eventManager->execute(EVENTS::ANIMATION_SWITCH_FACING, m_localeid, nullptr, nullptr);
		bsOut.Write((SLNet::MessageID)EVENTS::SWITCH_FACING);
		bsOut.Write(m_localeid);
		bsOut.Write(dir);
		m_eventManager->execute(EVENTS::SEND_SERVER, m_localeid, nullptr, &bsOut);
	}

	m_eventManager->execute(EVENTS::MAP_CAN_MOVE, m_localeid, nullptr, nullptr);
	if (!m_entityManager->getComp(m_localeid, PLAYER_BODY)->getCanWalk())
		return;

	if (!m_entityManager->getComp(m_localeid, PLAYER_BODY)->getMoving())
	{
		bsOut.Reset();
		int x = 0, y = 0;
		cocos2d::CallFuncN* stopMovingCB = cocos2d::CallFuncN::create(CC_CALLBACK_0(MovementSystem::stopMoving, this, m_localeid));
		cocos2d::Action* secuence;
		switch (dir)
		{
		case North:
			y++;
			bsOut.Write((SLNet::MessageID)EVENTS::MOVE_NORTH);
			bsOut.Write(m_localeid);
			m_eventManager->execute(EVENTS::SEND_SERVER, m_localeid, nullptr, &bsOut);
			secuence = cocos2d::Sequence::create(m_moveNorth->clone(), stopMovingCB, nullptr);
			break;
		case East:
			x++;
			bsOut.Write((SLNet::MessageID)EVENTS::MOVE_EAST);
			bsOut.Write(m_localeid);
			m_eventManager->execute(EVENTS::SEND_SERVER, m_localeid, nullptr, &bsOut);
			secuence = cocos2d::Sequence::create(m_moveEast->clone(), stopMovingCB, nullptr);
			break;
		case South:
			y--;
			bsOut.Write((SLNet::MessageID)EVENTS::MOVE_SOUTH);
			bsOut.Write(m_localeid);
			m_eventManager->execute(EVENTS::SEND_SERVER, m_localeid, nullptr, &bsOut);
			secuence = cocos2d::Sequence::create(m_moveSouth->clone(), stopMovingCB, nullptr);
			break;
		case West:
			x--;
			bsOut.Write((SLNet::MessageID)EVENTS::MOVE_WEST);
			bsOut.Write(m_localeid);
			m_eventManager->execute(EVENTS::SEND_SERVER, m_localeid, nullptr, &bsOut);
			secuence = cocos2d::Sequence::create(m_moveWest->clone(), stopMovingCB, nullptr);
			break;
		}

		m_entityManager->getComp(m_localeid, PLAYER_BODY)->getBodySpr()->runAction(secuence);

		m_entityManager->getComp(m_localeid, PLAYER_BODY)->setMoving(true);
		m_eventManager->execute(EVENTS::ANIMATE, m_localeid, nullptr, nullptr);

		m_entityManager->getComp(m_localeid, POSITION)->setX(
			m_entityManager->getComp(m_localeid, POSITION)->getX() + x);

		m_entityManager->getComp(m_localeid, POSITION)->setY(
			m_entityManager->getComp(m_localeid, POSITION)->getY() + y);


		m_entityManager->getComp(m_localeid, AUDIO)->addAudio(23);
		//cocos2d::log("Pos: %i, %i", 
			//m_entityManager->getComp(m_localeid, POSITION)->getX(),
			//m_entityManager->getComp(m_localeid, POSITION)->getY());
	}
}

void MovementSystem::moveRemote(Direction dir, int eid)
{
	int x = 0, y = 0;
	m_entityManager->getComp(eid, PLAYER_BODY)->setDirection(dir);
	cocos2d::CallFuncN* stopMovingCB = cocos2d::CallFuncN::create(CC_CALLBACK_0(MovementSystem::stopMoving, this, eid));
	cocos2d::Action* secuence;
	switch (dir)
	{
	case North:
		y++;
		secuence = cocos2d::Sequence::create(m_moveNorth->clone(), stopMovingCB, nullptr);
		break;
	case East:
		x++;
		secuence = cocos2d::Sequence::create(m_moveEast->clone(), stopMovingCB, nullptr);
		break;
	case South:
		y--;
		secuence = cocos2d::Sequence::create(m_moveSouth->clone(), stopMovingCB, nullptr);
		break;
	case West:
		x--;
		secuence = cocos2d::Sequence::create(m_moveWest->clone(), stopMovingCB, nullptr);
		break;
	}

	m_entityManager->getComp(eid, PLAYER_BODY)->setMoving(true);
	m_eventManager->execute(EVENTS::ANIMATE, eid, nullptr, nullptr);

	m_entityManager->getComp(eid, PLAYER_BODY)->getBodySpr()->runAction(secuence);

	m_entityManager->getComp(eid, POSITION)->setX(
		m_entityManager->getComp(eid, POSITION)->getX() + x);

	m_entityManager->getComp(eid, POSITION)->setY(
		m_entityManager->getComp(eid, POSITION)->getY() + y);

	m_entityManager->getComp(eid, AUDIO)->addAudio(23);
}

void MovementSystem::stopMoving(int eid)
{
	m_entityManager->getComp(eid, PLAYER_BODY)->setMoving(false);
}

void MovementSystem::setLocalEntity(int eid, cocos2d::Event * ccevent, SLNet::BitStream * bs)
{
	m_localeid = eid;
}

void MovementSystem::createVector(int eid, cocos2d::Event * ccevent, SLNet::BitStream * bs)
{
	std::vector<Direction>* vec = new (std::nothrow) std::vector<Direction>;
	m_pendingMoves.emplace(eid, vec);
}

void MovementSystem::removeVector(int eid, cocos2d::Event * ccevent, SLNet::BitStream * bs)
{
	if (m_pendingMoves.find(eid) != m_pendingMoves.end())
	{
		delete m_pendingMoves.at(eid);
		m_pendingMoves.at(eid) = nullptr;
		m_pendingMoves.erase(eid);
	}
}
