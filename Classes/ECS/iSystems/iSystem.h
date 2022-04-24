#ifndef __SYSTEM_H__
#define __SYSTEM_H__

#include <vector>

#include "ECS/iSystems/iSystemTags.h"
#include "Components/IncludeComponents.h"

namespace ECS
{
	class iSystem
	{
	public:
		iSystem();
		virtual ~iSystem();

		virtual void update(float dt) = 0;
	};
}
#endif // __SYSTEM_H__