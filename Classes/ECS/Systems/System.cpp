#include "System.h"

#include "cocos2d.h"

namespace ECS
{

#define LOGID "[SYSTEM]"

	System::System()
	{
		cocos2d::log("%s Constructor", LOGID);
	}

	System::~System()
	{
		cocos2d::log("%s Destructor", LOGID);
	}

}