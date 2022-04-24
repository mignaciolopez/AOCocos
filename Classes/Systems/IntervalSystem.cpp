#include "IntervalSystem.h"

USING_NS_CC;

IntervalSystem::IntervalSystem(cocos2d::Scene* scene, entt::registry* registry)
	: m_scene(scene), m_registry(registry)
{
#if _DEBUG
	cocos2d::log("[IntervalSystem] Constructor");
#endif

	m_signalsManager = ECS::SignalsManager::getInstance();

	m_registry->on_construct<IntervalComponent>().connect<&IntervalSystem::onConstructIntC>(this);

	m_signalsManager->connect<&IntervalSystem::setLocalEntity>(Signals::NW_MY_ENTT, this);
}

IntervalSystem::~IntervalSystem()
{
#if _DEBUG
	cocos2d::log("[IntervalSystem] Destructor");
#endif

	m_registry->on_construct<IntervalComponent>().disconnect<&IntervalSystem::onConstructIntC>(this);

	ECS::SignalsManager::getInstance()->disconnectAll(this);
}

void IntervalSystem::update(float dt)
{
	if (!m_registry->valid(m_localEntt))
		return;

	auto intC = m_registry->try_get<IntervalComponent>(m_localEntt);

	if (!intC)
		return;

	intC->_dtLastAttack += dt;
	intC->_dtLastCastSpell += dt;
	intC->_dtLastUse += dt;
}

void IntervalSystem::onConstructIntC(entt::registry & registry, entt::entity entity)
{
	loadIntervals(entity, nullptr);
}

void IntervalSystem::setLocalEntity(entt::entity entity, SLNet::BitStream * bs)
{
	m_localEntt = entity;
}

void IntervalSystem::loadIntervals(entt::entity entity, SLNet::BitStream * bs)
{
	auto intC = m_registry->try_get<IntervalComponent>(entity);

	if (!intC)
		return;

	auto fileUtils = FileUtils::getInstance();

	std::string framesBodiesPath = fileUtils->fullPathForFilename("intervals.json");
	auto framesBodiesJason = fileUtils->getStringFromFile(framesBodiesPath);
	cocos2d::log("[IntervalSystem] File: %s", framesBodiesPath.c_str());

	std::stringstream ss(framesBodiesJason);
	std::string line;

	while (std::getline(ss, line))
	{
		if (line == "")
		{
			cocos2d::log("[IntervalSystem] loadIntervals() line was empty");
			continue;
		}

		rapidjson::Document d;
		if (d.Parse(line.c_str()).HasParseError())
		{
			cocos2d::log("[IntervalSystem] loadIntervals() Error parsing line: %s", line.c_str());
			continue;
		}

		if (d.HasMember("meleeattack"))
			intC->_constAttack = d["attack"].GetFloat();
		else if (d.HasMember("castspell"))
			intC->_constCastSpell = d["castspell"].GetFloat();
		else if (d.HasMember("use"))
			intC->_constUse = d["use"].GetFloat();
	}
}
