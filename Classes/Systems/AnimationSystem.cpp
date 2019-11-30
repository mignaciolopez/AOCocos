#include "AnimationSystem.h"

#include "Components/PlayerBodyComponent.h"

#include "Graphics/Graphics.h"

AnimationSystem::AnimationSystem()
{
#if _DEBUG
	cocos2d::log("%s Constructor", "[ANIMATION SYSTEM]");
#endif

	m_director = cocos2d::Director::getInstance();
	m_entityManager = ECS::ECS_Engine::getInstance()->getEntityManager();
	m_eventManager = ECS::ECS_Engine::getInstance()->getEventManager();
	m_sfCache = cocos2d::SpriteFrameCache::getInstance();

	m_eventManager->Subscribe(EVENTS::ANIMATE, &AnimationSystem::animate, this);
}

AnimationSystem::~AnimationSystem()
{
	
#if _DEBUG
	cocos2d::log("%s Destructor", "[ANIMATION SYSTEM]");
#endif
}

void AnimationSystem::Update()
{
	for (auto e : *m_entityManager->getEntities())
	{
		if (!m_entityManager->getComp(e.first, PLAYER_BODY)->getMoving())
			setBodyCF(e.first);
	}
}

void AnimationSystem::animate(int eid, cocos2d::Event*, SLNet::BitStream* bs)
{
	setHead(eid);
	setHelmet(eid);

	m_entityManager->getComp(eid, ComponentType::PLAYER_BODY)->getBodySpr()->runAction(
		m_entityManager->getComp(eid, ComponentType::PLAYER_BODY)->getAnimBody()->clone());

	m_entityManager->getComp(eid, ComponentType::PLAYER_BODY)->getShieldSpr()->runAction(
		m_entityManager->getComp(eid, ComponentType::PLAYER_BODY)->getAnimShield()->clone());

	m_entityManager->getComp(eid, ComponentType::PLAYER_BODY)->getWeaponSpr()->runAction(
		m_entityManager->getComp(eid, ComponentType::PLAYER_BODY)->getAnimWeapon()->clone());
}

void AnimationSystem::setBodyCF(int eid)
{
	setBody(eid);
	setHead(eid);
	setShield(eid);
	setHelmet(eid);
	setWeapon(eid);
}

void AnimationSystem::setBody(int eid)
{
	Direction dir = m_entityManager->getComp(eid, ComponentType::PLAYER_BODY)->getDirection();
	auto bodySpr = m_entityManager->getComp(eid, ComponentType::PLAYER_BODY)->getBodySpr();
	bodySpr->setSpriteFrame(m_sfCache->getSpriteFrameByName(std::to_string(m_entityManager->getComp(eid, ComponentType::PLAYER_BODY)->getBodyGs(dir))));
}

void AnimationSystem::setHead(int eid)
{
	Direction dir = m_entityManager->getComp(eid, ComponentType::PLAYER_BODY)->getDirection();
	auto headSpr = m_entityManager->getComp(eid, ComponentType::PLAYER_BODY)->getHeadSpr();
	headSpr->setSpriteFrame(m_sfCache->getSpriteFrameByName(std::to_string(m_entityManager->getComp(eid, ComponentType::PLAYER_BODY)->getHeadGs(dir))));
}

void AnimationSystem::setShield(int eid)
{
	Direction dir = m_entityManager->getComp(eid, ComponentType::PLAYER_BODY)->getDirection();
	auto shieldSpr = m_entityManager->getComp(eid, ComponentType::PLAYER_BODY)->getShieldSpr();
	shieldSpr->setSpriteFrame(m_sfCache->getSpriteFrameByName(std::to_string(m_entityManager->getComp(eid, ComponentType::PLAYER_BODY)->getShieldGs(dir))));
}

void AnimationSystem::setHelmet(int eid)
{
	Direction dir = m_entityManager->getComp(eid, ComponentType::PLAYER_BODY)->getDirection();
	auto helmetSpr = m_entityManager->getComp(eid, ComponentType::PLAYER_BODY)->getHelmetSpr();
	helmetSpr->setSpriteFrame(m_sfCache->getSpriteFrameByName(std::to_string(m_entityManager->getComp(eid, ComponentType::PLAYER_BODY)->getHelmetGs(dir))));
}

void AnimationSystem::setWeapon(int eid)
{
	Direction dir = m_entityManager->getComp(eid, ComponentType::PLAYER_BODY)->getDirection();
	auto weaponSpr = m_entityManager->getComp(eid, ComponentType::PLAYER_BODY)->getWeaponSpr();
	weaponSpr->setSpriteFrame(m_sfCache->getSpriteFrameByName(std::to_string(m_entityManager->getComp(eid, ComponentType::PLAYER_BODY)->getWeaponGs(dir))));
}
