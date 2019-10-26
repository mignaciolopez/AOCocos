#ifndef __COMPONENT_H__
#define __COMPONENT_H__

#include "Components/ComponentsList.h"

namespace ECS
{

	class Component
	{
	public:
		Component();
		virtual ~Component();

		const ComponentType _type = ComponentType::NONE;

	};

}
#endif // __COMPONENT_H__
