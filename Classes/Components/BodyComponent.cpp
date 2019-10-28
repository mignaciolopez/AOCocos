#include "BodyComponent.h"

#define LOGID "[BODY COMPONENT]"

BodyComponent::BodyComponent()
{
	cocos2d::log("%s Constructor", LOGID);

	_bodySprite = cocos2d::Sprite::create("HelloWorld.png");

	if (!_bodySprite)
		cocos2d::log("%s _bodySprite failed with HelloWorld.png", LOGID);
	else
		_bodySprite->retain();
}

BodyComponent::~BodyComponent()
{
	auto runningScene = cocos2d::Director::getInstance()->getRunningScene();
	if(runningScene && _bodySprite)
		cocos2d::Director::getInstance()->getRunningScene()->removeChild(_bodySprite);
	
	_bodySprite->release();
	cocos2d::log("%s Destructor", LOGID);
}
