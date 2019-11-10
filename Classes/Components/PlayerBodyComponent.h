#ifndef __SPRITE_COMPONENT_H__
#define __SPRITE_COMPONENT_H__

#include "ECS/Components/Component.h"

enum Direction
{
	North = 0,
	East,
	South,
	West,
};

enum Genre
{
	Male = 0,
	Female
};

enum Race
{
	Human = 0,
	Dwarf,
	Gnome,
	Elf,
	DarkElf
};
enum Head
{
	Pirate = 0,
	None
};

class PlayerBodyComponent : public ECS::Component
{
public:
	PlayerBodyComponent(std::string bodySfn, std::string headSfn, int x, int y,
		Direction dir, Genre genre, Race race, Head head)
	{
		cocos2d::log("%s Constructor", "[PLAYERBODYCOMPONENT COMPONENT]");

		auto cache = cocos2d::SpriteFrameCache::getInstance();

		m_direction = dir;
		m_genre = genre;
		m_race = race;
		m_head = head;

		//body
		m_spriteBody = cocos2d::Sprite::createWithSpriteFrameName(bodySfn);
		if (!m_spriteBody)
			cocos2d::log("%s _sprite failed with file name: %s", "[PLAYERBODYCOMPONENT COMPONENT]", bodySfn);
		else
		{
			m_spriteBody->retain();

			m_spriteBody->setPosition(x * 32 + 16, y * 32);

			//m_spriteBody->setScale(2.0f);
			m_spriteBody->setAnchorPoint(cocos2d::Vec2(0.5f, 0.0f));
		}

		//Head
		m_spriteHead = cocos2d::Sprite::createWithSpriteFrameName(headSfn);
		if (!m_spriteHead)
			cocos2d::log("%s _sprite failed with file name: %s", "[PLAYERBODYCOMPONENT COMPONENT]", headSfn);
		else
		{
			m_spriteHead->retain();

			m_spriteBody->setAnchorPoint(cocos2d::Vec2(0.5f, 0.0f));
			m_spriteBody->addChild(m_spriteHead);
			m_spriteHead->setPosition(m_spriteBody->getContentSize().width / 2, m_spriteBody->getContentSize().height);
		}
	}
	~PlayerBodyComponent()
	{
		if (m_spriteBody)
			if (m_spriteBody->getReferenceCount() > 0)
				m_spriteBody->release();

		if (m_spriteHead)
			if (m_spriteHead->getReferenceCount() > 0)
				m_spriteHead->release();

		cocos2d::log("%s Destructor", "[PLAYERBODYCOMPONENT COMPONENT]");
	}

	virtual cocos2d::Sprite* getBodySpr() override
	{
		return m_spriteBody;
	}
	virtual void setBodySpr(cocos2d::Sprite* body) override
	{
		m_spriteBody = body;
	}

	virtual cocos2d::Sprite* getHeadSpr() override
	{
		return m_spriteHead;
	}
	virtual void setHeadSpr(cocos2d::Sprite* head) override
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

	virtual bool getCanWalk() override
	{
		return m_canWalk;
	}
	virtual void setCanWalk(bool w) override
	{
		m_canWalk = w;
	}

	virtual Direction getDirection() override
	{
		return m_direction;
	}
	virtual void setDirection(Direction dir) override
	{
		m_direction = dir;
	}

	virtual Race getRace() override
	{
		return m_race;
	}
	virtual void setRace(Race race) override
	{
		m_race = race;
	}

	virtual Genre getGenre() override
	{
		return m_genre;
	}
	virtual void setGenre(Genre genre) override
	{
		m_genre = genre;
	}

	virtual Head getHead() override
	{
		return m_head;
	}
	virtual void setHead(Head head) override
	{
		m_head = head;
	}

private:
	cocos2d::Sprite* m_spriteBody;
	cocos2d::Sprite* m_spriteHead; //child of body
	const ComponentType m_type = ComponentType::PLAYER_BODY;
	bool m_moving = false;
	bool m_canWalk = true;
	Direction m_direction = Direction::South;
	Race m_race;
	Genre m_genre;
	Head m_head;

private:

};

#endif // __SPRITE_COMPONENT_H__
