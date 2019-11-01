#ifndef __SPRITE_COMPONENT_H__
#define __SPRITE_COMPONENT_H__

#include "ECS/Components/Component.h"

#include <random>

class SpriteComponent : public ECS::Component
{
public:
	SpriteComponent(const char* spriteFileName)
	{
		cocos2d::log("%s Constructor", "[SPRITE COMPONENT]");

		_sprite = cocos2d::Sprite::create(spriteFileName);

		if (!_sprite)
			cocos2d::log("%s _sprite failed with file name: %s", "[SPRITE COMPONENT]", spriteFileName);
		else
		{
			_sprite->retain();

			std::random_device dev;
			std::mt19937 rng(dev());
			std::uniform_int_distribution<std::mt19937::result_type> distW(100, 700);
			std::uniform_int_distribution<std::mt19937::result_type> distH(100, 500);

			_sprite->setPosition(distW(rng), distH(rng));
		}
	}
	~SpriteComponent()
	{
		auto runningScene = cocos2d::Director::getInstance()->getRunningScene();
		if (runningScene && _sprite)
		{
			cocos2d::Director::getInstance()->getRunningScene()->removeChild(_sprite);
			_sprite->release();
		}
		cocos2d::log("%s Destructor", "[SPRITE COMPONENT]");
	}

	cocos2d::Sprite* _sprite;
	const ComponentType _type = ComponentType::SPRITE;
	bool  _moving = false;
};

#endif // __SPRITE_COMPONENT_H__
