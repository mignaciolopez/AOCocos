#include "Entity.h"

#include "cocos2d.h"

namespace ECS
{

#define LOGID "[ENTITY]"

	Entity::Entity(int id)
	{
		cocos2d::log("%s Constructor", LOGID);

		m_id = id;
	}

	Entity::~Entity()
	{
#if _DEBUG
		cocos2d::log("%s Destructor", LOGID);
#endif
	}
}