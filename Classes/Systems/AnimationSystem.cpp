#include "AnimationSystem.h"

USING_NS_CC;

AnimationSystem::AnimationSystem(entt::registry* registry)
	: m_registry(registry)
{
#if _DEBUG
	cocos2d::log("[AnimationSystem] Constructor");
#endif

	m_signalsManager = ECS::SignalsManager::getInstance();

	m_sfCache = cocos2d::SpriteFrameCache::getInstance();

	m_graphics = Graphics::getInstance();

	m_signalsManager->connect<&AnimationSystem::setLocalEntity>(Signals::NW_MY_ENTT, this);

	m_signalsManager->connect<&AnimationSystem::animateWalk>(Signals::ANIMATE_WALK, this);
	m_signalsManager->connect<&AnimationSystem::setBodyAll>(Signals::ANIMATE_SET_BODY_ALL, this);
	m_signalsManager->connect<&AnimationSystem::setBody>(Signals::ANIMATE_SET_BODY, this);
	m_signalsManager->connect<&AnimationSystem::setHead>(Signals::ANIMATE_SET_HEAD, this);
	m_signalsManager->connect<&AnimationSystem::setHelmet>(Signals::ANIMATE_SET_HELMET, this);
	m_signalsManager->connect<&AnimationSystem::setShield>(Signals::ANIMATE_SET_SHIELD, this);
	m_signalsManager->connect<&AnimationSystem::setWeapon>(Signals::ANIMATE_SET_WEAPON, this);
	m_signalsManager->connect<&AnimationSystem::animateSpell>(Signals::ANIMATE_SPELL, this);
	m_signalsManager->connect<&AnimationSystem::animateShield>(Signals::ANIMATE_SHIELD, this);
	m_signalsManager->connect<&AnimationSystem::animateWeapon>(Signals::ANIMATE_WEAPON, this);

	m_signalsManager->connect<&AnimationSystem::graphicsReload>(Signals::GRAPHICS_RELOAD_INSTANCE, this);
}

AnimationSystem::~AnimationSystem()
{
#if _DEBUG
	cocos2d::log("[AnimationSystem] Destructor");
#endif

	ECS::SignalsManager::getInstance()->disconnectAll(this);
}

void AnimationSystem::update(float dt)
{

}

void AnimationSystem::setLocalEntity(entt::entity entity, SLNet::BitStream * bs)
{
	m_localEntt = entity;
}

void AnimationSystem::animateWalk(entt::entity entity,  SLNet::BitStream* bs)
{
	auto playerC = m_registry->try_get<PlayerComponent>(entity);
	if (!playerC)
	{
#if _DEBUG
		cocos2d::log("[AnimationSystem] animateWalk() playerC is nullptr.");
#endif
		return;
	}

	setHead(entity, nullptr);
	setHelmet(entity, nullptr);

	CallFuncN* cbBody = CallFuncN::create(CC_CALLBACK_0(AnimationSystem::setBody, this, entity, nullptr));
	Action* seqBody = Sequence::create(playerC->_animBody[playerC->_direction], cbBody, nullptr);
	seqBody->setTag(AxnTags::AnimateSeqBody);
	playerC->_spriteBody->runAction(seqBody);

	if (playerC->_shield)
	{
		CallFuncN* cbShield = CallFuncN::create(CC_CALLBACK_0(AnimationSystem::setShield, this, entity, nullptr));
		Action* seqShield = Sequence::create(playerC->_animShield[playerC->_direction]->clone(), cbShield, nullptr);
		playerC->_spriteShield->runAction(seqShield);
	}

	if (playerC->_weapon)
	{
		CallFuncN* cbWeapon = CallFuncN::create(CC_CALLBACK_0(AnimationSystem::setWeapon, this, entity, nullptr));
		Action* seqWeapon = Sequence::create(playerC->_animWeapon[playerC->_direction]->clone(), cbWeapon, nullptr);
		playerC->_spriteWeapon->runAction(seqWeapon);
	}
}

void AnimationSystem::setBodyAll(entt::entity entity,  SLNet::BitStream* bs)
{
	setBody(entity, nullptr);
	setHead(entity, nullptr);
	setHelmet(entity, nullptr);
	setShield(entity, nullptr);
	setWeapon(entity, nullptr);
}

void AnimationSystem::animateSpell(entt::entity entity,  SLNet::BitStream* bs)
{
	if (!m_registry->valid(m_localEntt))
		return;

	if (!bs)
	{
#if _DEBUG
		cocos2d::log("[AnimationSystem] animateSpell() bs is nullptr.");
#endif
		return;
	}

	auto playerC = m_registry->try_get<PlayerComponent>(entity);

	if (!playerC)
	{
#if _DEBUG
		cocos2d::log("[AnimationSystem] animateSpell() playerC is nullptr.");
#endif
		return;
	}

	Animations animTag;
	bs->Read(animTag);

	Animate* animate = m_graphics->getccAnimation(animTag);

	if (!animate)
		return;

	int tag = getNewAnimTag();

	CallFuncN* cb = CallFuncN::create(CC_CALLBACK_0(AnimationSystem::animEnd, this, entity, tag));
	Action* seq = nullptr;

	auto sprite = Sprite::create("images/transparentPixel.png");

	Size contectSize = m_sfCache->getSpriteFrameByName(std::to_string(m_graphics->getAnimationsFrames(animTag)->_frames[0]))->getOriginalSize();

	seq = Sequence::create(animate->clone(), cb, nullptr);
	sprite->setContentSize(contectSize);
	sprite->setAnchorPoint(Vec2(0.5f, 0.0f));
	sprite->setPositionX(sprite->getPositionX() + playerC->_spriteBody->getContentSize().width * 0.5f);
	sprite->setPositionX(sprite->getPositionX() + m_graphics->getAnimationsFrames(animTag)->_offset[0]);
	sprite->setPositionY(sprite->getPositionY() + m_graphics->getAnimationsFrames(animTag)->_offset[1]);

	sprite->setTag(tag);
	playerC->_spriteBody->addChild(sprite, 20);
	sprite->setCameraMask(static_cast<int>(cocos2d::CameraFlag::USER1));

	sprite->runAction(seq);

	m_animsRunning.emplace(tag, sprite);
}

void AnimationSystem::animateWeapon(entt::entity entity,  SLNet::BitStream* bs)
{
	auto playerC = m_registry->try_get<PlayerComponent>(entity);
	if (!playerC)
	{
#if _DEBUG
		cocos2d::log("[AnimationSystem] animateWeapon() playerC is nullptr.");
#endif
		return;
	}

	if (playerC->_weapon && playerC->_spriteWeapon)
	{
		CallFuncN* cbWeapon = CallFuncN::create(CC_CALLBACK_0(AnimationSystem::setWeapon, this, entity, nullptr));
		Action* seqWeapon = Sequence::create(playerC->_animWeapon[playerC->_direction]->clone(), cbWeapon, nullptr);
		playerC->_spriteWeapon->runAction(seqWeapon);
	}
}

void AnimationSystem::animateShield(entt::entity entity,  SLNet::BitStream* bs)
{
	auto playerC = m_registry->try_get<PlayerComponent>(entity);
	if (!playerC)
	{
#if _DEBUG
		cocos2d::log("[AnimationSystem] animateShield() playerC is nullptr.");
#endif
		return;
	}

	if (playerC->_shield && playerC->_spriteShield)
	{
		CallFuncN* cbShield = CallFuncN::create(CC_CALLBACK_0(AnimationSystem::setShield, this, entity, nullptr));
		Action* seqShield = Sequence::create(playerC->_animShield[playerC->_direction]->clone(), cbShield, nullptr);
		playerC->_spriteShield->runAction(seqShield);
	}
}

void AnimationSystem::graphicsReload(entt::entity entity, SLNet::BitStream * bs)
{
	m_graphics = Graphics::getInstance();
}

void AnimationSystem::setBody(entt::entity entity, SLNet::BitStream* bs)
{
	auto playerC = m_registry->try_get<PlayerComponent>(entity);

	if (!playerC)
		return;

	if (!playerC->_spriteBody)
		return;

	if (!playerC->_body)
		return;

	playerC->_spriteBody->setSpriteFrame(m_sfCache->getSpriteFrameByName(std::to_string(playerC->_bodyStandingFrame[playerC->_direction])));
}

void AnimationSystem::setHead(entt::entity entity, SLNet::BitStream* bs)
{
	auto playerC = m_registry->try_get<PlayerComponent>(entity);

	if (!playerC)
		return;

	if (!playerC->_spriteHead)
		return;

	if (!playerC->_head)
		return;

	playerC->_spriteHead->setSpriteFrame(m_sfCache->getSpriteFrameByName(std::to_string(playerC->_headFrame[playerC->_direction])));
}

void AnimationSystem::setHelmet(entt::entity entity, SLNet::BitStream* bs)
{
	auto playerC = m_registry->try_get<PlayerComponent>(entity);

	if (!playerC)
		return;

	if (!playerC->_spriteHelmet)
		return;

	if (!playerC->_helmet)
		return;

	playerC->_spriteHelmet->setSpriteFrame(m_sfCache->getSpriteFrameByName(std::to_string(playerC->_helmetFrame[playerC->_direction])));
}

void AnimationSystem::setShield(entt::entity entity, SLNet::BitStream* bs)
{
	auto playerC = m_registry->try_get<PlayerComponent>(entity);

	if (!playerC)
		return;

	if (!playerC->_spriteShield)
		return;

	if (!playerC->_shield)
		return;

	playerC->_spriteShield->setSpriteFrame(m_sfCache->getSpriteFrameByName(std::to_string(playerC->_shieldFrame[playerC->_direction])));
}

void AnimationSystem::setWeapon(entt::entity entity, SLNet::BitStream* bs)
{
	auto playerC = m_registry->try_get<PlayerComponent>(entity);

	if (!playerC)
		return;

	if (!playerC->_spriteWeapon)
		return;

	if (!playerC->_weapon)
		return;

	playerC->_spriteWeapon->setSpriteFrame(m_sfCache->getSpriteFrameByName(std::to_string(playerC->_weaponFrame[playerC->_direction])));
}

int AnimationSystem::getNewAnimTag()
{
	int tag = 0;
	
	while (m_animsRunning.find(tag) != m_animsRunning.end())
		tag++;

	return tag;
}

void AnimationSystem::animEnd(entt::entity entity, int tag)
{
	if (m_animsRunning.find(tag) != m_animsRunning.end())
	{
		if (m_animsRunning.at(tag)->getParent())
			m_animsRunning.at(tag)->getParent()->removeChildByTag(tag);

		m_animsRunning.erase(tag);
		
	}
}
