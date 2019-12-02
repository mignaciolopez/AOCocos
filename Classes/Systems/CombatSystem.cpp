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

	m_eventManager->Subscribe(EVENTS::COMBAT_SPELLS_AIR, &CombatSystem::spellAir, this);
	m_eventManager->Subscribe(EVENTS::COMBAT_SPELLS_TARGET, &CombatSystem::spellTarget, this);
	m_eventManager->Subscribe(EVENTS::COMBAT_SPELLS_THROW, &CombatSystem::spellThrow, this);
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
	//m_eventManager->execute(EVENTS::ANIMATE_WEAPON, eid);
	
	m_entityManager->getComp(eid, AUDIO)->addAudio(2);
}

void CombatSystem::punchTarget(int eid, cocos2d::Event * ccEvnt, SLNet::BitStream * bs)
{
	//m_eventManager->execute(EVENTS::ANIMATE_WEAPON, eid);

	int targeteid = -1;
	if (bs)
		bs->Read(targeteid);

	m_entityManager->getComp(targeteid, PLAYER_BODY)->setAttacking(true);
	m_entityManager->getComp(eid, PLAYER_BODY)->setAttacking(true);

	m_eventManager->execute(EVENTS::ANIMATE_WEAPON, eid);
	m_eventManager->execute(EVENTS::ANIMATE_BLOOD, targeteid);
	m_entityManager->getComp(eid, AUDIO)->addAudio(10);

	return;

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
}

void CombatSystem::spellAir(int eid, cocos2d::Event * ccEvnt, SLNet::BitStream * bs)
{
	cocos2d::log("[COMBAT SYSTEM] Invalid target");
}

void CombatSystem::spellTarget(int eid, cocos2d::Event * ccEvnt, SLNet::BitStream * bs)
{
	int targeteid = -1;
	if (bs)
		bs->Read(targeteid);

	m_entityManager->getComp(targeteid, PLAYER_BODY)->setAttacking(true);

	m_eventManager->execute(EVENTS::ANIMATE_APOCALIPSIS, targeteid);
	m_entityManager->getComp(eid, AUDIO)->addAudio(27);
}

void CombatSystem::punch(int eid, cocos2d::Event * ccEvent, SLNet::BitStream * bs)
{
	if (m_entityManager->getComp(eid, PLAYER_BODY)->getAttacking())
		return;

	m_entityManager->getComp(eid, PLAYER_BODY)->setAttacking(true);

	m_eventManager->execute(EVENTS::ANIMATE_WEAPON, eid);

	//Lets try some client prediction here when renocking is implemented
	//for now just send the event to server
	SLNet::BitStream bsOut;
	bsOut.Write((SLNet::MessageID)EVENTS::COMBAT_PUNCH);
	bsOut.Write(eid);
	m_eventManager->execute(EVENTS::SEND_SERVER, eid, nullptr, &bsOut);
}

void CombatSystem::spellThrow(int eid, cocos2d::Event * ccEvent, SLNet::BitStream * bs)
{
}
