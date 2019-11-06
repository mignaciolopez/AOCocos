#ifndef __SPRITE_COMPONENT_H__
#define __SPRITE_COMPONENT_H__

#include "ECS/Components/Component.h"

enum Direction
{
	North,
	East,
	South,
	West
};


class PlayerBodyComponent : public ECS::Component
{
public:
	PlayerBodyComponent(std::string bodySfn, float x, float y, std::string headSfn)
	{
		cocos2d::log("%s Constructor", "[PLAYERBODYCOMPONENT COMPONENT]");

		auto cache = cocos2d::SpriteFrameCache::getInstance();


		//body
		_sprite = cocos2d::Sprite::createWithSpriteFrameName(bodySfn);
		if (!_sprite)
			cocos2d::log("%s _sprite failed with file name: %s", "[PLAYERBODYCOMPONENT COMPONENT]", bodySfn);
		else
		{
			_sprite->retain();

			_sprite->setPosition(x, x);
		}

		//Head
		_spriteHead = cocos2d::Sprite::createWithSpriteFrameName(headSfn);
		if (!_spriteHead)
			cocos2d::log("%s _sprite failed with file name: %s", "[PLAYERBODYCOMPONENT COMPONENT]", headSfn);
		else
		{
			_spriteHead->retain();

			_spriteHead->setPosition(x, x);
		}

		_sprite->addChild(_spriteHead);
		_spriteHead->setPosition(12.5f, 46.0f);

	}
	~PlayerBodyComponent()
	{
		auto runningScene = cocos2d::Director::getInstance()->getRunningScene();
		if (runningScene && _sprite)
		{
			if (_sprite->getParent() == runningScene)
				runningScene->removeChild(_sprite);

			_sprite->release();
		}

		if (runningScene && _spriteHead)
		{
			if (_spriteHead->getParent() == runningScene)
				runningScene->removeChild(_spriteHead);

			_spriteHead->release();
		}
		cocos2d::log("%s Destructor", "[PLAYERBODYCOMPONENT COMPONENT]");
	}

	cocos2d::Sprite* _sprite;
	cocos2d::Sprite* _spriteHead; //child of body
	const ComponentType _type = ComponentType::PLAYER_BODY;
	bool  _moving = false;
	Direction _direction = Direction::South;

private:

};

#endif // __SPRITE_COMPONENT_H__
