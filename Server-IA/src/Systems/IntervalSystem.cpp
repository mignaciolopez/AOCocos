#include "IntervalSystem.h"

IntervalSystem::IntervalSystem(entt::registry* registry)
	: m_registry(registry)
{
	ECS_Log::s_consoleL->trace("[IntervalSystem] Constructor");

	m_signalsManager = ECS::SignalsManager::getSignalsManager();

	loadIntervals();
}

IntervalSystem::~IntervalSystem()
{
	ECS_Log::s_consoleL->trace("[IntervalSystem] Destructor");

	m_signalsManager->disconnectAll(this);
}

void IntervalSystem::update(double dt)
{
	auto view = m_registry->view<IntervalComponent>();

	for (auto e : view)
	{
		auto intC = m_registry->try_get<IntervalComponent>(e);

		intC->_dtLastAttack += dt;
		intC->_dtLastCastSpell += dt;
		intC->_dtLastUse += dt;
	}	
}

void IntervalSystem::loadIntervals()
{
	/*auto intC = m_registry->try_get<IntervalComponent>(entity);

	if (!intC)
		return;

	auto fileUtils = FileUtils::getInstance();

	std::string framesBodiesPath = fileUtils->fullPathForFilename("intervals.json");
	auto framesBodiesJason = fileUtils->getStringFromFile(framesBodiesPath);
	ECS_Log::s_consoleL->trace("[IntervalSystem] File: %s", framesBodiesPath.c_str());

	std::stringstream ss(framesBodiesJason);
	std::string line;

	while (std::getline(ss, line))
	{
		if (line == "")
		{
			ECS_Log::s_consoleL->trace("[IntervalSystem] loadIntervals() line was empty");
			continue;
		}

		rapidjson::Document d;
		if (d.Parse(line.c_str()).HasParseError())
		{
			ECS_Log::s_consoleL->trace("[IntervalSystem] loadIntervals() Error parsing line: %s", line.c_str());
			continue;
		}

		if (d.HasMember("meleeattack"))
			intC->_constMeleeAttack = d["meleeattack"].GetFloat();
		else if (d.HasMember("magicattack"))
			intC->_constMagicAttack = d["magicattack"].GetFloat();
		else if (d.HasMember("castspell"))
			intC->_constCastSpell = d["castspell"].GetFloat();
		else if (d.HasMember("use"))
			intC->_constUse = d["use"].GetFloat();
	}*/
}
