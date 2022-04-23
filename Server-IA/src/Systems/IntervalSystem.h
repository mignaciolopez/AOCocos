#ifndef INTERVAL_SYSTEM_H__
#define INTERVAL_SYSTEM_H__

#include "ECS/SignalsManager.h"
#include "ECS/SignalsList.h"
#include "entt.hpp"

#include "ECS/iSystems/iSystem.h"

#include "Components/IncludeComponents.h"

#include "ECS/ECS_Log.h"

class IntervalSystem : public ECS::iSystem
{
public:
	const ECS::iSystemTags _tag = ECS::iSystemTags::IntervalSystem_tag;
	IntervalSystem(entt::registry* registry);
	~IntervalSystem();

	virtual void update(double dt) override;

	void loadIntervals();

private:
	std::shared_ptr<ECS::SignalsManager> m_signalsManager;
	entt::registry* m_registry;

};

#endif // !INTERVAL_SYSTEM_H__
