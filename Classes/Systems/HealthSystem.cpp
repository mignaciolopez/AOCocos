#include "HealthSystem.h"

USING_NS_CC;

HealthSystem::HealthSystem(cocos2d::Scene* scene, entt::registry* registry)
	: m_scene(scene), m_registry(registry)
{
#if _DEBUG
	cocos2d::log("[HealthSystem] Constructor");
#endif
	m_director = cocos2d::Director::getInstance();
	m_signalsManager = ECS::SignalsManager::getInstance();

	m_localEntt = entt::null;

	m_registry->on_construct<HealthComponent>().connect<&HealthSystem::onConstructHealthC>(this);
	m_registry->on_destroy<HealthComponent>().connect<&HealthSystem::onDestroyHealthC>(this);

	m_signalsManager->connect<&HealthSystem::setLocalEntity>(Signals::NW_MY_ENTT, this);

	m_signalsManager->connect<&HealthSystem::healthUpdate>(Signals::HEALTH_UPDATE, this);

	m_signalsManager->connect<&HealthSystem::healthUsePotion>(Signals::HEALTH_USE_POTION, this);
}

HealthSystem::~HealthSystem()
{
#if _DEBUG
	cocos2d::log("[HealthSystem] Destructor");
#endif

	ECS::SignalsManager::getInstance()->disconnectAll(this);

	m_registry->on_construct<HealthComponent>().disconnect<&HealthSystem::onConstructHealthC>(this);
	m_registry->on_destroy<HealthComponent>().disconnect<&HealthSystem::onDestroyHealthC>(this);
}

void HealthSystem::update(float dt)
{
	if (!m_registry->valid(m_localEntt))
		return;

	auto healthC = m_registry->try_get<HealthComponent>(m_localEntt);
	healthC->_lblHp->setString(std::to_string(healthC->_hp) + " / " + std::to_string(healthC->_hpMax));
	healthC->_percent = (healthC->_hp * 100.0f) / healthC->_hpMax;

	float barPercent = (healthC->_percent * 88.0f) / 100.0f;
	healthC->_sprBar->setContentSize(Size(barPercent, 10.0f));
}

void HealthSystem::onConstructHealthC(entt::registry & registry, entt::entity entity)
{
	//i should get the info from the server for the local entity
	auto healthC = m_registry->try_get<HealthComponent>(entity);

	auto hudC = m_registry->try_get<HudComponent>(entity);

	if (!hudC)
	{
		return;
	}

	healthC->_node = Node::create();
	healthC->_node->setContentSize(Size(88.0f, 10.0f));
	healthC->_node->setAnchorPoint(Vec2(0.0f, 0.0f));
	healthC->_node->setIgnoreAnchorPointForPosition(false);
	healthC->_node->setPosition(572.0f, 92.0f);

	healthC->_percent = (healthC->_hp * 100.0f) / healthC->_hpMax;

	float barPercent = (healthC->_percent * 88.0f) / 100.0f;

	healthC->_sprBar = Sprite::create("images/healthBar.png");
	healthC->_sprBar->setContentSize(Size(barPercent, 10.0f));
	healthC->_sprBar->setAnchorPoint(Vec2(0.0f, 0.0f));

	healthC->_lblHp = Label::createWithSystemFont(std::to_string(healthC->_hp) + " / " + std::to_string(healthC->_hpMax), "arial",
		10.0f, Size(88.0f, 12.0f), TextHAlignment::CENTER, TextVAlignment::CENTER);
	healthC->_lblHp->setAnchorPoint(Vec2(0.0f, 0.0f));

	healthC->_node->addChild(healthC->_sprBar);
	healthC->_node->addChild(healthC->_lblHp);
	hudC->_hudNode->addChild(healthC->_node, 10);
}

void HealthSystem::onDestroyHealthC(entt::registry & registry, entt::entity entity)
{
	auto healthC = m_registry->try_get<HealthComponent>(entity);

	healthC->_node->removeAllChildren();

	auto hudC = m_registry->try_get<HudComponent>(entity);

	if (!hudC)
	{
		return;
	}

	hudC->_hudNode->removeChild(healthC->_node);
}

void HealthSystem::setLocalEntity(entt::entity entity, SLNet::BitStream * bs)
{
	m_localEntt = entity;
}

void HealthSystem::healthUpdate(entt::entity entity, SLNet::BitStream * bs)
{
	if (!bs)
	{
		return;
	}

	auto healthC = m_registry->try_get<HealthComponent>(entity);

	if (!healthC)
	{
		return;
	}

	int hp = 0;
	bs->Read(hp);
	healthC->_hp = hp;
}

void HealthSystem::healthUsePotion(entt::entity entity, SLNet::BitStream * bs)
{
	if (m_registry->has<FXComponent>(entity))
		m_registry->replace<FXComponent>(entity, [](auto &fxC) { fxC._FXs.push_back(FXS::Drink); });
	
	auto intC = m_registry->try_get<IntervalComponent>(entity);

	if (intC)
		intC->_dtLastUse = 0.0f;
}