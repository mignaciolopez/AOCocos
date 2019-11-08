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

	m_eventManager->Subscribe(EVENTS::MY_EID, &MovementSystem::setLocalEntity, this);

	m_eventManager->Subscribe(EVENTS::EID_JOINED, &MovementSystem::createVector, this);
	m_eventManager->Subscribe(EVENTS::EID_QUIT, &MovementSystem::removeVector, this);

	m_eventManager->Subscribe(EVENTS::SYNC_PLAYERS, &MovementSystem::createVectors, this);


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
			break;
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
	if (!m_entityManager->getComp(m_localeid, PLAYER_BODY)->getMoving())
	{
		m_entityManager->getComp(m_localeid, PLAYER_BODY)->setDirection(dir);
		SLNet::BitStream bsOut;
		float x = 0, y = 0;
		cocos2d::CallFuncN* stopMovingCB = cocos2d::CallFuncN::create(CC_CALLBACK_0(MovementSystem::stopMoving, this, m_localeid));
		cocos2d::Action* secuence;
		switch (dir)
		{
		case North:
			y = 32.0f;
			bsOut.Write((SLNet::MessageID)EVENTS::MOVE_NORTH);
			bsOut.Write(m_localeid);
			m_eventManager->execute(EVENTS::SEND_SERVER, m_localeid, nullptr, &bsOut);
			secuence = cocos2d::Sequence::create(m_moveNorth->clone(), stopMovingCB, nullptr);
			break;
		case East:
			x = 32.0f;
			bsOut.Write((SLNet::MessageID)EVENTS::MOVE_EAST);
			bsOut.Write(m_localeid);
			m_eventManager->execute(EVENTS::SEND_SERVER, m_localeid, nullptr, &bsOut);
			secuence = cocos2d::Sequence::create(m_moveEast->clone(), stopMovingCB, nullptr);
			break;
		case South:
			y = -32.0f;
			bsOut.Write((SLNet::MessageID)EVENTS::MOVE_SOUTH);
			bsOut.Write(m_localeid);
			m_eventManager->execute(EVENTS::SEND_SERVER, m_localeid, nullptr, &bsOut);
			secuence = cocos2d::Sequence::create(m_moveSouth->clone(), stopMovingCB, nullptr);
			break;
		case West:
			x = -32.0f;
			bsOut.Write((SLNet::MessageID)EVENTS::MOVE_WEST);
			bsOut.Write(m_localeid);
			m_eventManager->execute(EVENTS::SEND_SERVER, m_localeid, nullptr, &bsOut);
			//m_entityManager->getComp(m_localeid, PLAYER_BODY)->getBodySpr()->runAction(m_moveWest->clone());
			secuence = cocos2d::Sequence::create(m_moveWest->clone(), stopMovingCB, nullptr);
			break;
		}

		m_entityManager->getComp(m_localeid, PLAYER_BODY)->getBodySpr()->runAction(secuence);

		m_entityManager->getComp(m_localeid, PLAYER_BODY)->setMoving(true);
		m_eventManager->execute(EVENTS::ANIMATE, m_localeid, nullptr, nullptr);

		m_entityManager->getComp(m_localeid, POSITION)->setX(
			m_entityManager->getComp(m_localeid, PLAYER_BODY)->getBodySpr()->getPosition().x + x);

		m_entityManager->getComp(m_localeid, POSITION)->setY(
			m_entityManager->getComp(m_localeid, PLAYER_BODY)->getBodySpr()->getPosition().y + y);
	}
}

void MovementSystem::moveRemote(Direction dir, int eid)
{
	float x = 0, y = 0;
	m_entityManager->getComp(eid, PLAYER_BODY)->setDirection(dir);
	cocos2d::CallFuncN* stopMovingCB = cocos2d::CallFuncN::create(CC_CALLBACK_0(MovementSystem::stopMoving, this, eid));
	cocos2d::Action* secuence;
	switch (dir)
	{
	case North:
		y = 32.0f;
		secuence = cocos2d::Sequence::create(m_moveNorth->clone(), stopMovingCB, nullptr);
		break;
	case East:
		x = 32.0f;
		secuence = cocos2d::Sequence::create(m_moveEast->clone(), stopMovingCB, nullptr);
		break;
	case South:
		y = -32.0f;
		secuence = cocos2d::Sequence::create(m_moveSouth->clone(), stopMovingCB, nullptr);
		break;
	case West:
		x = -32.0f;
		secuence = cocos2d::Sequence::create(m_moveWest->clone(), stopMovingCB, nullptr);
		break;
	}

	m_entityManager->getComp(eid, PLAYER_BODY)->setMoving(true);
	m_eventManager->execute(EVENTS::ANIMATE, eid, nullptr, nullptr);

	m_entityManager->getComp(eid, PLAYER_BODY)->getBodySpr()->runAction(secuence);

	m_entityManager->getComp(eid, POSITION)->setX(
		m_entityManager->getComp(eid, PLAYER_BODY)->getBodySpr()->getPosition().x + x);

	m_entityManager->getComp(eid, POSITION)->setY(
		m_entityManager->getComp(eid, PLAYER_BODY)->getBodySpr()->getPosition().y + y);
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

void MovementSystem::createVectors(int eid, cocos2d::Event * ccevent, SLNet::BitStream * bs)
{
	bs->ResetReadPointer();
	bs->IgnoreBytes(sizeof(SLNet::MessageID));
	bs->IgnoreBytes(sizeof(int));
	unsigned int count = 0;
	bs->Read(count);
	for (unsigned int i = 0; i < count; i++)
	{
		int reid = -1;
		float rx, ry;
		bs->Read(reid);
		bs->Read(rx);
		bs->Read(ry);
		std::vector<Direction>* vec = new (std::nothrow) std::vector<Direction>;
		m_pendingMoves.emplace(reid, vec);
	}
}
