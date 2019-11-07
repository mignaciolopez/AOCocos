#ifndef __ENTITY_H__
#define __ENTITY_H__

#include <map>
#include <vector>

#include "ECS/Components/Component.h"
#include "Components/IncludeComponents.h"

namespace ECS
{
	class Entity
	{
	public:
		Entity(int id);
		~Entity();

	private:

	public:

	private:
		int m_id;
	};
}
#endif // __ENTITY_H__