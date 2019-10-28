#ifndef __HEAD_COMPONENT_H__
#define __HEAD_COMPONENT_H__

#include "ECS/Components/Component.h"

class HeadComponent : public ECS::Component
{

#define LOGID "[HEAD COMPONENT]"

public:
	HeadComponent()
	{
		cocos2d::log("%s Constructor", LOGID);

		_sprite = cocos2d::Sprite::create("HelloWorld.png");

		if (!_sprite)
			cocos2d::log("%s _bodySprite failed with HelloWorld.png", LOGID);
		else
		{
			_sprite->retain();
			_sprite->setPosition(400.0f, 300.0f);
		}
	}
	~HeadComponent()
	{
		auto runningScene = cocos2d::Director::getInstance()->getRunningScene();
		if (runningScene && _sprite)
			cocos2d::Director::getInstance()->getRunningScene()->removeChild(_sprite);

		_sprite->release();
		cocos2d::log("%s Destructor", LOGID);
	}

	cocos2d::Sprite* _sprite;
	const ComponentType _type = ComponentType::HEADCOMPONENT;
};

#endif // __HEAD_COMPONENT_H__
