#include "BodyComponent.h"

#define LOGID "[BODY COMPONENT]"

BodyComponent::BodyComponent()
{
	cocos2d::log("%s Constructor", LOGID);
	_bodySprite = cocos2d::Sprite::create("HelloWorld.png");
	if (!_bodySprite)
		cocos2d::log("%s _bodySprite failed with HelloWorld.png", LOGID);
}

BodyComponent::~BodyComponent()
{
	cocos2d::log("%s Destructor", LOGID);
}
