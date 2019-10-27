#ifndef __SYSTEM_H__
#define __SYSTEM_H__

#include <vector>

#include "Components/ComponentsList.h"

namespace ECS
{

	class System
	{
	public:
		System();
		virtual ~System();

		virtual void Update() = 0;

	private:
		std::vector<ComponentType> m_compatibleComponents;
	};
}
#endif // __SYSTEM_H__