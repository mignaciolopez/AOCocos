#include "iSystem.h"

#include "cocos2d.h"

namespace ECS
{

	iSystem::iSystem()
	{
		cocos2d::log("[iSystem] Constructor");
	}

	iSystem::~iSystem()
	{
#if _DEBUG
		cocos2d::log("[iSystem] Destructor");
#endif
	}

}