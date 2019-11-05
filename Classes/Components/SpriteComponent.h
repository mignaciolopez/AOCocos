#ifndef __SPRITE_COMPONENT_H__
#define __SPRITE_COMPONENT_H__

#include "ECS/Components/Component.h"

class SpriteComponent : public ECS::Component
{
public:
	SpriteComponent(std::string sfn, float x, float y)
	{
		cocos2d::log("%s Constructor", "[SPRITE COMPONENT]");

		auto cache = cocos2d::SpriteFrameCache::getInstance();

		_sprite = cocos2d::Sprite::createWithSpriteFrameName(sfn);

		if (!_sprite)
			cocos2d::log("%s _sprite failed with file name: %s", "[SPRITE COMPONENT]", sfn);
		else
		{
			_sprite->retain();

			_sprite->setPosition(x, x);
		}
	}
	~SpriteComponent()
	{
		auto runningScene = cocos2d::Director::getInstance()->getRunningScene();
		if (runningScene && _sprite)
		{
			if (_sprite->getParent() == runningScene)
				runningScene->removeChild(_sprite);

			_sprite->release();
		}
		cocos2d::log("%s Destructor", "[SPRITE COMPONENT]");
	}

	cocos2d::Sprite* _sprite;
	const ComponentType _type = ComponentType::SPRITE;
	bool  _moving = false;
};

#endif // __SPRITE_COMPONENT_H__
