#ifndef __SYSTEM_H__
#define __SYSTEM_H__

#include <vector>

#include "ECS/iSystems/iSystemTags.h"

#include "ECS/ECS_Log.h"

namespace ECS
{
	class iSystem
	{
	public:
		iSystem();
		virtual ~iSystem();

		virtual void update(double dt) = 0;
	};
}
#endif // __SYSTEM_H__