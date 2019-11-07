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
		m_sprite = cocos2d::Sprite::createWithSpriteFrameName(bodySfn);
		if (!m_sprite)
			cocos2d::log("%s _sprite failed with file name: %s", "[PLAYERBODYCOMPONENT COMPONENT]", bodySfn);
		else
		{
			m_sprite->retain();

			m_sprite->setPosition(x, y);
		}

		//Head
		m_spriteHead = cocos2d::Sprite::createWithSpriteFrameName(headSfn);
		if (!m_spriteHead)
			cocos2d::log("%s _sprite failed with file name: %s", "[PLAYERBODYCOMPONENT COMPONENT]", headSfn);
		else
		{
			m_spriteHead->retain();

			m_sprite->addChild(m_spriteHead);
			m_spriteHead->setPosition(12.5f, 46.0f);
		}
	}
	~PlayerBodyComponent()
	{
		auto runningScene = cocos2d::Director::getInstance()->getRunningScene();
		if (runningScene && m_sprite)
		{
			if (m_sprite->getParent() == runningScene)
				runningScene->removeChild(m_sprite);

			m_sprite->release();
		}

		if (runningScene && m_spriteHead)
		{
			if (m_spriteHead->getParent() == runningScene)
				runningScene->removeChild(m_spriteHead);

			m_spriteHead->release();
		}
		cocos2d::log("%s Destructor", "[PLAYERBODYCOMPONENT COMPONENT]");
	}

	virtual cocos2d::Sprite* getBody() override
	{
		return m_sprite;
	}
	virtual void setBody(cocos2d::Sprite* body) override
	{
		m_sprite = body;
	}

	virtual cocos2d::Sprite* getHead() override
	{
		return m_spriteHead;
	}
	virtual void setHead(cocos2d::Sprite* head) override
	{
		m_spriteHead = head;
	}

	virtual ComponentType getType() override
	{
		return m_type;
	}
	virtual bool getMoving() override
	{
		return m_moving;
	}
	virtual void setMoving(bool m) override
	{
		m_moving = m;
	}
	virtual Direction getDirection() override
	{
		return m_direction;
	}
	virtual void setDirection(Direction dir) override
	{
		m_direction = dir;
	}

private:
	cocos2d::Sprite* m_sprite;
	cocos2d::Sprite* m_spriteHead; //child of body
	const ComponentType m_type = ComponentType::PLAYER_BODY;
	bool  m_moving = false;
	Direction m_direction = Direction::South;

private:

};

#endif // __SPRITE_COMPONENT_H__
