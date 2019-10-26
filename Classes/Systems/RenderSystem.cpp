#include "RenderSystem.h"

#include "cocos2d.h"

#define LOGID "[RENDER SYSTEM]"

RenderSystem::RenderSystem()
{
	cocos2d::log("%s Constructor", LOGID);
}

RenderSystem::~RenderSystem()
{
	cocos2d::log("%s Destructor", LOGID);
}

void RenderSystem::Update()
{
	//cocos2d::log("%s Update", LOGID);
}