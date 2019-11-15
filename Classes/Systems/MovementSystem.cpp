#include "MovementSystem.h"

#include "Components/PositionComponent.h"
#include "Components/PlayerBodyComponent.h"

USING_NS_CC;

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

	m_localeid = -1;

	m_fpsCounter = 60;
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

#if _DEBUG
	cocos2d::log("%s Destructor", "[MOVEMENT SYSTEM]");
#endif
}

void MovementSystem::Update()
{
	if (m_localeid == -1)
		return;

	m_fpsCounter++;

	m_clock_e = clock();
	double elapsed_secs = double(m_clock_e - m_clock_b) / CLOCKS_PER_SEC;
	if (elapsed_secs > 1)
	{
		m_fpsCounter = std::min(200, m_fpsCounter);
		double rel = (m_fpsCounter * 100) / 60;
		m_fpsPivot = 0.02 / (rel / 100.0);
		m_fpsCounter = 0;
		m_clock_b = clock();
	}

	for (auto e : *m_entityManager->getEntities())
	{
		if (move(e.first, m_entityManager->getComp(e.first, POSITION)->getNextMove()))
			m_entityManager->getComp(e.first, POSITION)->removeFirstMove();
	}
}

void MovementSystem::moveNorth(int eid, cocos2d::Event* ccevnt, SLNet::BitStream* bs)
{
	if (eid == m_localeid)
	{
		move(eid, Direction::North);
		return;
	}
	m_entityManager->getComp(eid, POSITION)->setNextMove(Direction::North);
}

void MovementSystem::moveEast(int eid, cocos2d::Event* ccevnt, SLNet::BitStream* bs)
{
	if (eid == m_localeid)
	{
		move(eid, Direction::East);
		return;
	}
	m_entityManager->getComp(eid, POSITION)->setNextMove(Direction::East);
}

void MovementSystem::moveSouth(int eid, cocos2d::Event* ccevnt, SLNet::BitStream* bs)
{
	if (eid == m_localeid)
	{
		move(eid, Direction::South);
		return;
	}
	m_entityManager->getComp(eid, POSITION)->setNextMove(Direction::South);
}

void MovementSystem::moveWest(int eid, cocos2d::Event* ccevnt, SLNet::BitStream* bs)
{
	if (eid == m_localeid)
	{
		move(eid, Direction::West);
		return;
	}
	m_entityManager->getComp(eid, POSITION)->setNextMove(Direction::West);
}

void MovementSystem::switchRemoteFacing(int eid, cocos2d::Event * ccevnt, SLNet::BitStream * bs)
{
	Direction dir;
	bs->Read(dir);
	m_entityManager->getComp(eid, PLAYER_BODY)->setDirection(dir);
	//m_eventManager->execute(EVENTS::ANIMATION_SWITCH_FACING, eid, nullptr, nullptr);
}

bool MovementSystem::move(int eid, Direction dir)
{
	if (dir == Direction::INVALID)
		return false;

	if (m_entityManager->getComp(eid, PLAYER_BODY)->getMoving())
		return false;

	m_entityManager->getComp(eid, PLAYER_BODY)->setDirection(dir);

	SLNet::BitStream bsOut;

	if (eid == m_localeid)
	{
		m_eventManager->execute(EVENTS::MAP_CAN_MOVE, m_localeid, nullptr, nullptr);
		if (!m_entityManager->getComp(m_localeid, PLAYER_BODY)->getCanWalk())
		{
			bsOut.Write((SLNet::MessageID)EVENTS::SWITCH_FACING);
			bsOut.Write(m_localeid);
			bsOut.Write(dir);
			m_eventManager->execute(EVENTS::SEND_SERVER, m_localeid, nullptr, &bsOut);
			return true;
		}

		bsOut.Reset();
	}

	m_entityManager->getComp(eid, PLAYER_BODY)->setMoving(true);

	int x = 0, y = 0;

	switch (dir)
	{
	case Direction::North:
		y++;
		m_entityManager->getComp(eid, PLAYER_BODY)->getBodySpr()->runAction(m_moveNorth->clone());
		if (eid == m_localeid)
			bsOut.Write((SLNet::MessageID)EVENTS::MOVE_NORTH);
		break;
	case Direction::East:
		x++;
		m_entityManager->getComp(eid, PLAYER_BODY)->getBodySpr()->runAction(m_moveEast->clone());
		if (eid == m_localeid)
			bsOut.Write((SLNet::MessageID)EVENTS::MOVE_EAST);
		break;
	case Direction::South:
		y--;
		m_entityManager->getComp(eid, PLAYER_BODY)->getBodySpr()->runAction(m_moveSouth->clone());
		if (eid == m_localeid)
			bsOut.Write((SLNet::MessageID)EVENTS::MOVE_SOUTH);
		break;
	case Direction::West:
		x--;
		m_entityManager->getComp(eid, PLAYER_BODY)->getBodySpr()->runAction(m_moveWest->clone());
		if (eid == m_localeid)
			bsOut.Write((SLNet::MessageID)EVENTS::MOVE_WEST);	
		break;
	default:
		return false;
	}

	if (eid == m_localeid)
	{
		bsOut.Write(m_localeid);
		m_eventManager->execute(EVENTS::SEND_SERVER, m_localeid, nullptr, &bsOut);
	}

	m_entityManager->getComp(eid, POSITION)->setX(
		m_entityManager->getComp(eid, POSITION)->getX() + x);

	m_entityManager->getComp(eid, POSITION)->setY(
		m_entityManager->getComp(eid, POSITION)->getY() + y);

	CallFuncN* callback = CallFuncN::create(CC_CALLBACK_0(MovementSystem::stopMoving, this, eid));
	DelayTime* dtcb = cocos2d::DelayTime::create(m_vel - m_fpsPivot);
	Action* secuence = Sequence::create(dtcb, callback, nullptr);
	m_entityManager->getComp(eid, PLAYER_BODY)->getBodySpr()->runAction(secuence);

	m_entityManager->getComp(eid, AUDIO)->addAudio(23);

	m_eventManager->execute(EVENTS::ANIMATE, eid);

	return true;
}

void MovementSystem::stopMoving(int eid)
{
	m_entityManager->getComp(eid, PLAYER_BODY)->setMoving(false);
}

void MovementSystem::setLocalEntity(int eid, cocos2d::Event * ccevent, SLNet::BitStream * bs)
{
	m_localeid = eid;
}
