#include "CombatSystem.h"

USING_NS_CC;

CombatSystem::CombatSystem(entt::registry* registry)
	: m_registry(registry)
{
#if _DEBUG
	cocos2d::log("[CombatSystem] Constructor");
#endif

	m_signalsManager = ECS::SignalsManager::getInstance();

	m_signalsManager->connect<&CombatSystem::setLocalEntity>(Signals::NW_MY_ENTT, this);

	m_signalsManager->connect<&CombatSystem::punchAir>(Signals::COMBAT_PUNCH_AIR, this);
	m_signalsManager->connect<&CombatSystem::punchTarget>(Signals::COMBAT_PUNCH_TARGET, this);
	m_signalsManager->connect<&CombatSystem::punch>(Signals::COMBAT_PUNCH, this);

	m_signalsManager->connect<&CombatSystem::spellAir>(Signals::COMBAT_SPELLS_AIR, this);
	m_signalsManager->connect<&CombatSystem::spellTarget>(Signals::COMBAT_SPELLS_TARGET, this);

	m_signalsManager->connect<&CombatSystem::spellThrow>(Signals::UI_SPELL_TRHOUW, this);

	m_signalsManager->connect<&CombatSystem::dead>(Signals::COMBAT_DEAD, this);
	m_signalsManager->connect<&CombatSystem::resurrect>(Signals::COMBAT_RESURRECT, this);

	m_localEntt = entt::null;
}

CombatSystem::~CombatSystem()
{
#if _DEBUG
	cocos2d::log("[CombatSystem] Destructor");
#endif

	ECS::SignalsManager::getInstance()->disconnectAll(this);
}

void CombatSystem::update(float dt)
{
	if (!m_registry->valid(m_localEntt))
		return;

}

void CombatSystem::setLocalEntity(entt::entity entity, SLNet::BitStream* bs)
{
	m_localEntt = entity;
}

void CombatSystem::punchAir(entt::entity entity,  SLNet::BitStream* bs)
{
	auto playerC = m_registry->try_get<PlayerComponent>(entity);

	if (!playerC)
		return;

	m_signalsManager->publish(Signals::ANIMATE_WEAPON, entity);
	
	if (m_registry->has<FXComponent>(entity))
		m_registry->replace<FXComponent>(entity, [](auto &fxC) { fxC._FXs.push_back(FXS::MeleeAttackFail); });

	auto intC = m_registry->try_get<IntervalComponent>(entity);

	if (intC)
		intC->_dtLastAttack = 0.0f;
}

void CombatSystem::punchTarget(entt::entity entity,  SLNet::BitStream* bs)
{
	if (!bs)
	{
		return;
	}

	entt::entity targetEntity = entt::null;
	bs->Read(targetEntity);

	if (!m_registry->valid(targetEntity))
		return;

	auto playerC = m_registry->try_get<PlayerComponent>(entity);

	auto targetPlayerC = m_registry->try_get<PlayerComponent>(targetEntity);
	

	if (!playerC || !targetPlayerC)
		return;

	m_signalsManager->publish(Signals::ANIMATE_WEAPON, entity);

	SLNet::BitStream bsOut;
	bsOut.Write(Animations::Anim_Blood);
	m_signalsManager->publish(Signals::ANIMATE_SPELL, targetEntity, &bsOut);

	if (m_registry->has<FXComponent>(entity))
		m_registry->replace<FXComponent>(entity, [](auto &fxC) { fxC._FXs.push_back(FXS::MeleeAttack); });


	auto intC = m_registry->try_get<IntervalComponent>(entity);
	if (intC)
		intC->_dtLastAttack = 0.0f;
}

void CombatSystem::spellAir(entt::entity entity,  SLNet::BitStream* bs)
{
#if _DEBUG
	cocos2d::log("[CombatSystem] Invalid target");
#endif

	/*auto playerC = m_registry->try_get<PlayerComponent>(entity);

	if (!playerC)
		return;*/

	auto intC = m_registry->try_get<IntervalComponent>(entity);

	if (intC)
		intC->_dtLastAttack = 0.0f;
}

void CombatSystem::spellTarget(entt::entity entity,  SLNet::BitStream* bs)
{
	if (!bs)
	{
		return;
	}

	entt::entity targetEntity = entt::null;
	bs->Read(targetEntity);

	if (!m_registry->valid(targetEntity))
		return;

	if (targetEntity == m_localEntt)
	{
		auto healthC = m_registry->try_get<HealthComponent>(m_localEntt);
	}

	SLNet::BitStream bsOut;
	bsOut.Write(Animations::Anim_Apocalipsis);
	m_signalsManager->publish(Signals::ANIMATE_SPELL, targetEntity, &bsOut);

	if (m_registry->has<FXComponent>(entity))
		m_registry->replace<FXComponent>(entity, [](auto &fxC) { fxC._FXs.push_back(FXS::ApocalipsisExplotion); });

	auto intC = m_registry->try_get<IntervalComponent>(entity);

	if (intC)
		intC->_dtLastAttack = 0.0f;
}

void CombatSystem::punch(entt::entity entity, SLNet::BitStream* bs)
{
	auto intC = m_registry->try_get<IntervalComponent>(m_localEntt);

	if (!intC)
		return;

	if (intC->_dtLastAttack < intC->_constAttack)
	{
		//show u cant attack yet
		return;
	}

	//Lets try some client prediction here when renocking is implemented
	//for now just send the event to server
	SLNet::BitStream bsOut;
	bsOut.Write((SLNet::MessageID)Signals::COMBAT_PUNCH);
	bsOut.Write(entity);
	m_signalsManager->publish(Signals::NW_SEND_SERVER, entity, &bsOut);
}

void CombatSystem::spellThrow(entt::entity entity, SLNet::BitStream* bs)
{
	if (!m_registry->valid(m_localEntt))
		return;

	auto intC = m_registry->try_get<IntervalComponent>(m_localEntt);

	if (!intC)
		return;

	if (intC->_dtLastAttack < intC->_constAttack)
	{
		//show u cant attack yet
		return;
	}

	if (!bs)
	{
		return;
	}

	auto mapC = m_registry->try_get<MapComponent>(m_localEntt);

	if (!mapC)
	{
		return;
	}

	auto posC = m_registry->try_get<PositionComponent>(m_localEntt);

	if (!posC)
	{
		return;
	}

	float x = 0.0f;
	float y = 0.0f;

	bs->Read(x);
	bs->Read(y);

	Vec2 touchLocation = Vec2(x, y);

	//cocos2d::log("[MAP SYSTEM] mouseEvent: %f, %f", mouseEvent->getLocationInView().x, mouseEvent->getLocationInView().y);

	Size viewSize = Director::getInstance()->getWinSize();
	auto mousePosOffset = Director::getInstance()->convertToGL(touchLocation);

	//cocos2d::log("[MAP SYSTEM] convertToGL: %f, %f", mousePosOffset.x, mousePosOffset.y);
	mousePosOffset.x -= 10;
	mousePosOffset.y += 45;
	//cocos2d::log("[MAP SYSTEM] mousePosOffset corrected: %f, %f", mousePosOffset.x, mousePosOffset.y);


	Vec2 mapCordinate = mapC->_map->convertToNodeSpace(mousePosOffset);
	//cocos2d::log("[MAP SYSTEM] mousePosOffset convertToNodeSpace: %f, %f", mousePosOffset.x, mousePosOffset.y);
	int tileX = mapCordinate.x / mapC->_map->getTileSize().width;
	int tileY = (viewSize.height - mapCordinate.y) / mapC->_map->getTileSize().height;

	//cocos2d::log("[MAP SYSTEM] Casted: %d, %d", tileX, tileY);

	tileX -= 8 - posC->_x;
	tileY -= 6 - posC->_y;

	cocos2d::log("[MAP SYSTEM] Casted: %d, %d", tileX, tileY);


	SLNet::BitStream bsOut;
	bsOut.Write((SLNet::MessageID)Signals::COMBAT_SPELLS_THROW);
	bsOut.Write(m_localEntt);
	bsOut.Write(tileX);
	bsOut.Write(tileY);
	m_signalsManager->publish(Signals::NW_SEND_SERVER, m_localEntt, &bsOut);
}

void CombatSystem::dead(entt::entity entity,  SLNet::BitStream* bs)
{
	if (!bs)
	{
		return;
	}

	entt::entity deadEntity = entt::null;

	bs->Read(deadEntity);

	if (!m_registry->valid(deadEntity))
		return;

	if (deadEntity == m_localEntt)
	{
		auto healthC = m_registry->try_get<HealthComponent>(m_localEntt);
		healthC->_hp = 0;
	}

	auto playerC = m_registry->try_get<PlayerComponent>(deadEntity);
	playerC->_isAlive = false;
	
	playerC->_lastBody = playerC->_body;
	playerC->_body = Bodies::Body_Casper_White;
	playerC->_spriteBody->setOpacity(80);
	playerC->_spriteBody->setOpacityModifyRGB(true);
	m_signalsManager->publish(Signals::GRAPHICS_LOAD_BODY, deadEntity);

	playerC->_lastHead = playerC->_head;
	playerC->_head = Heads::Head_Casper_White;
	playerC->_spriteHead->setOpacity(80);
	playerC->_spriteHead->setOpacityModifyRGB(true);
	playerC->_spriteHead->setPositionX(playerC->_spriteHead->getPositionX() + 2.0f);
	playerC->_spriteHead->setPositionY(playerC->_spriteHead->getPositionY() - 9.0f);
	m_signalsManager->publish(Signals::GRAPHICS_LOAD_HEAD, deadEntity);

	playerC->_helmet = Helmets::NoHelmet;
	m_signalsManager->publish(Signals::GRAPHICS_LOAD_HELMET, deadEntity);

	playerC->_shield = Shields::NoShield;
	m_signalsManager->publish(Signals::GRAPHICS_LOAD_SHIELD, deadEntity);

	playerC->_weapon = Weapons::NoWeapon;
	m_signalsManager->publish(Signals::GRAPHICS_LOAD_WEAPON, deadEntity);


	/*auto vpSprC = m_entityManager->getComp(eid, ComponentType::VPSPR);

	std::string vsh = FileUtils::getInstance()->fullPathForFilename("Simple.vsh");
	std::string fsh = FileUtils::getInstance()->fullPathForFilename("GreyScale.fsh");
	vpSprC->getVPSpr()->setGLProgram(GLProgram::createWithFilenames(vsh, fsh));*/
}

void CombatSystem::resurrect(entt::entity entity,  SLNet::BitStream* bs)
{
	if (entity == m_localEntt)
	{
		auto healthC = m_registry->try_get<HealthComponent>(entity);
		healthC->_hp = healthC->_hpMax;
	}

	auto playerC = m_registry->try_get<PlayerComponent>(entity);
	if (playerC->_isAlive)
		return;

	playerC->_isAlive = true;

	playerC->_body = playerC->_lastBody;
	playerC->_spriteBody->setOpacity(255);
	playerC->_spriteBody->setOpacityModifyRGB(true);
	m_signalsManager->publish(Signals::GRAPHICS_LOAD_BODY, entity);

	playerC->_head = playerC->_lastHead;
	playerC->_spriteHead->setOpacity(255);
	playerC->_spriteHead->setOpacityModifyRGB(true);
	playerC->_spriteHead->setPositionX(playerC->_spriteHead->getPositionX() - 2.0f);
	playerC->_spriteHead->setPositionY(playerC->_spriteHead->getPositionY() + 9.0f);
	m_signalsManager->publish(Signals::GRAPHICS_LOAD_HEAD, entity);

	playerC->_helmet = Helmets::NoHelmet;
	m_signalsManager->publish(Signals::GRAPHICS_LOAD_HELMET, entity);

	playerC->_shield = Shields::NoShield;
	m_signalsManager->publish(Signals::GRAPHICS_LOAD_SHIELD, entity);

	playerC->_weapon = Weapons::NoWeapon;
	m_signalsManager->publish(Signals::GRAPHICS_LOAD_WEAPON, entity);

	SLNet::BitStream bsInt;
	bsInt.Write(ParticleAnims::ExplodingRing);
	m_signalsManager->publish(Signals::PARTICLES_ANIM_SPAWN, entity, &bsInt);

	if (m_registry->has<FXComponent>(entity))
		m_registry->replace<FXComponent>(entity, [](auto &fxC) { fxC._FXs.push_back(FXS::Resurrect); });

	/*auto vpSprC = m_entityManager->getComp(eid, ComponentType::VPSPR);

	//vpSprC->getVPSpr()->setGLProgram(vpSprC->getDefaultGLP());
	std::string vsh = FileUtils::getInstance()->fullPathForFilename("Simple.vsh");
	std::string fsh = FileUtils::getInstance()->fullPathForFilename("vpSpr.fsh");
	vpSprC->getVPSpr()->setGLProgram(GLProgram::createWithFilenames(vsh, fsh));

	m_signalsManager->execute(EVENTS::LIGHT_SETUP, eid);*/
}
