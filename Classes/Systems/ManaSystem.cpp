#include "ManaSystem.h"

USING_NS_CC;

ManaSystem::ManaSystem(cocos2d::Scene* scene, entt::registry* registry)
	: m_scene(scene), m_registry(registry)
{
#if _DEBUG
	cocos2d::log("[ManaSystem] Constructor");
#endif
	m_director = cocos2d::Director::getInstance();
	m_signalsManager = ECS::SignalsManager::getInstance();

	m_graphics = Graphics::getInstance();

	m_localEntt = entt::null;

	m_registry->on_construct<ManaComponent>().connect<&ManaSystem::onConstructManaC>(this);
	m_registry->on_destroy<ManaComponent>().connect<&ManaSystem::onDestroyManaC>(this);

	m_signalsManager->connect<&ManaSystem::setLocalEntity>(Signals::NW_MY_ENTT, this);

	m_signalsManager->connect<&ManaSystem::meditateStart>(Signals::MEDITATE_START, this);
	m_signalsManager->connect<&ManaSystem::meditateEnd>(Signals::MEDITATE_END, this);

	m_signalsManager->connect<&ManaSystem::manaUpdate>(Signals::MANA_UPDATE, this);

	m_signalsManager->connect<&ManaSystem::manaUsePotion>(Signals::MANA_USE_POTION, this);
}

ManaSystem::~ManaSystem()
{
#if _DEBUG
	cocos2d::log("[ManaSystem] Destructor");
#endif

	ECS::SignalsManager::getInstance()->disconnectAll(this);

	m_registry->on_construct<ManaComponent>().disconnect<&ManaSystem::onConstructManaC>(this);
	m_registry->on_destroy<ManaComponent>().disconnect<&ManaSystem::onDestroyManaC>(this);
}

void ManaSystem::update(float dt)
{
	if (!m_registry->valid(m_localEntt))
		return;

	auto manaC = m_registry->try_get<ManaComponent>(m_localEntt);
	manaC->_lblMp->setString(std::to_string(manaC->_mp) + " / " + std::to_string(manaC->_mpMax));
	manaC->_percent = (manaC->_mp * 100.0f) / manaC->_mpMax;

	float barPercent = (manaC->_percent * 88.0f) / 100.0f;
	manaC->_sprBar->setContentSize(Size(barPercent, 10.0f));
}

void ManaSystem::onConstructManaC(entt::registry & registry, entt::entity entity)
{
	//i should get the info from the server for the local entity
	auto manaC = m_registry->try_get<ManaComponent>(entity);

	auto hudC = m_registry->try_get<HudComponent>(entity);

	if (!hudC)
	{
		return;
	}

	manaC->_node = Node::create();
	manaC->_node->setContentSize(Size(88.0f, 10.0f));
	manaC->_node->setAnchorPoint(Vec2(0.0f, 0.0f));
	manaC->_node->setIgnoreAnchorPointForPosition(false);
	manaC->_node->setPosition(572.0f, 115.0f);

	manaC->_percent = (manaC->_mp * 100.0f) / manaC->_mpMax;

	float barPercent = (manaC->_percent * 88.0f) / 100.0f;

	manaC->_sprBar = Sprite::create("images/manaBar.png");
	manaC->_sprBar->setContentSize(Size(barPercent, 10.0f));
	manaC->_sprBar->setAnchorPoint(Vec2(0.0f, 0.0f));

	manaC->_lblMp = Label::createWithSystemFont(std::to_string(manaC->_mp) + " / " + std::to_string(manaC->_mpMax), "arial",
		10.0f, Size(88.0f, 12.0f), TextHAlignment::CENTER, TextVAlignment::CENTER);
	manaC->_lblMp->setAnchorPoint(Vec2(0.0f, 0.0f));

	manaC->_node->addChild(manaC->_sprBar);
	manaC->_node->addChild(manaC->_lblMp);
	hudC->_hudNode->addChild(manaC->_node, 10);
}

void ManaSystem::onDestroyManaC(entt::registry & registry, entt::entity entity)
{
	auto manaC = m_registry->try_get<ManaComponent>(entity);

	manaC->_node->removeAllChildren();

	auto hudC = m_registry->try_get<HudComponent>(entity);

	if (!hudC)
	{
		return;
	}

	hudC->_hudNode->removeChild(manaC->_node);
}

void ManaSystem::setLocalEntity(entt::entity entity, SLNet::BitStream * bs)
{
	m_localEntt = entity;
}

void ManaSystem::meditateStart(entt::entity entity, SLNet::BitStream* bs)
{
	if (entity == m_localEntt)
	{
		auto manaC = m_registry->try_get<ManaComponent>(entity);
		auto posC = m_registry->try_get<PositionComponent>(entity);

		if (!manaC || !posC)
		{
			return;
		}

		if (manaC->_meditating || posC->_moving)
			return;

		manaC->_meditating = true;
	}

	SLNet::BitStream bsInt;
	bsInt.Write(ParticleAnims::MeditationFlowers);
	m_signalsManager->publish(Signals::PARTICLES_ANIM_SPAWN, entity, &bsInt);
}

void ManaSystem::meditateEnd(entt::entity entity, SLNet::BitStream * bs)
{
	if (entity == m_localEntt)
	{
		auto manaC = m_registry->try_get<ManaComponent>(entity);

		if (!manaC)
		{
			return;
		}

		if (!manaC->_meditating)
			return;

		manaC->_meditating = false;
	}

	SLNet::BitStream bsInt;
	bsInt.Write(ParticleAnims::MeditationFlowers);
	m_signalsManager->publish(Signals::PARTICLES_ANIM_UNSPAWN, entity, &bsInt);
}

void ManaSystem::manaUpdate(entt::entity entity, SLNet::BitStream * bs)
{
	if (!bs)
	{
		return;
	}

	auto manaC = m_registry->try_get<ManaComponent>(entity);

	if (!manaC)
	{
		return;
	}

	int mp = 0;
	bs->Read(mp);
	manaC->_mp = mp;
}

void ManaSystem::manaUsePotion(entt::entity entity, SLNet::BitStream * bs)
{
	if (m_registry->has<FXComponent>(entity))
		m_registry->replace<FXComponent>(entity, [](auto &fxC) { fxC._FXs.push_back(FXS::Drink); });

	auto intC = m_registry->try_get<IntervalComponent>(entity);

	if (intC)
		intC->_dtLastUse = 0.0f;
}
