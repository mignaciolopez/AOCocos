#include "CombatSystem.h"

USING_NS_CC;

CombatSystem::CombatSystem()
{
#if _DEBUG
	cocos2d::log("[COMBAT SYSTEM] Constructor");
#endif

	m_entityManager = ECS::ECS_Engine::getInstance()->getEntityManager();
	m_eventManager = ECS::ECS_Engine::getInstance()->getEventManager();

	m_eventManager->Subscribe(EVENTS::MY_EID, &CombatSystem::setLocaleid, this);
	m_eventManager->Subscribe(EVENTS::COMBAT_PUNCH_AIR, &CombatSystem::punchAir, this);
	m_eventManager->Subscribe(EVENTS::COMBAT_PUNCH_TARGET, &CombatSystem::punchTarget, this);
	m_eventManager->Subscribe(EVENTS::COMBAT_PUNCH, &CombatSystem::punch, this);
}

CombatSystem::~CombatSystem()
{
#if _DEBUG
	cocos2d::log("[COMBAT SYSTEM] Destructor");
#endif
}

void CombatSystem::update(float dt)
{
}

void CombatSystem::setLocaleid(int eid, cocos2d::Event * ccEvent, SLNet::BitStream * bs)
{
	m_localeid = eid;
}

void CombatSystem::punchAir(int eid, cocos2d::Event * ccEvnt, SLNet::BitStream * bs)
{
	m_eventManager->execute(EVENTS::ANIMATE_WEAPON, eid);
	
	m_entityManager->getComp(eid, AUDIO)->addAudio(2);
}

void CombatSystem::punchTarget(int eid, cocos2d::Event * ccEvnt, SLNet::BitStream * bs)
{
	m_eventManager->execute(EVENTS::ANIMATE_WEAPON, eid);

	int targeteid = -1;
	if (bs)
		bs->Read(targeteid);

	if (targeteid == m_localeid)
	{
		//this means i got hited
		//predict damage
		//blodd animation
	}
	else if (eid == m_localeid)
	{
		//this menas i git eid
		//animate my self punching
	}
	else
	{
		//animate who corresponds
	}

	m_entityManager->getComp(eid, AUDIO)->addAudio(10);
}

void CombatSystem::punch(int eid, cocos2d::Event * ccEvent, SLNet::BitStream * bs)
{
	if (m_entityManager->getComp(eid, PLAYER_BODY)->getAttacking())
		return;

	m_entityManager->getComp(eid, PLAYER_BODY)->setAttacking(true);

	//Lets try some client prediction here when renocking is implemented
	//for now just send the event to server
	SLNet::BitStream bsOut;
	bsOut.Write((SLNet::MessageID)EVENTS::COMBAT_PUNCH);
	bsOut.Write(eid);
	m_eventManager->execute(EVENTS::SEND_SERVER, eid, nullptr, &bsOut);
}
