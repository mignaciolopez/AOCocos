#ifndef __SPRITE_COMPONENT_H__
#define __SPRITE_COMPONENT_H__

#include "ECS/Components/Component.h"

class PlayerBodyComponent : public ECS::Component
{
public:
	PlayerBodyComponent(int x, int y,
		Direction dir, Genre genre, Race race, Body body, Head head, 
		Shield shield, Helmet helmet, Weapon weapon)
	{
		cocos2d::log("%s Constructor", "[PLAYERBODYCOMPONENT COMPONENT]");

		auto cache = cocos2d::SpriteFrameCache::getInstance();

		m_direction = dir;
		m_genre = genre;
		m_race = race;
		m_body = body;
		m_head = head;
		m_shield = shield;
		m_helmet = helmet;
		m_weapon = weapon;

		//body
		m_spriteBody = cocos2d::Sprite::create();
		m_spriteBody->retain();
		m_spriteBody->setCameraMask(static_cast<int>(cocos2d::CameraFlag::USER2));
		m_spriteBody->setPosition(x * 32 + 16, y * 32 + 4);
		m_spriteBody->setAnchorPoint(cocos2d::Vec2(0.5f, 0.0f));

		//Head
		m_spriteHead = cocos2d::Sprite::create();
		m_spriteHead->retain();
		m_spriteHead->setCameraMask(static_cast<int>(cocos2d::CameraFlag::USER2));
		m_spriteHead->setAnchorPoint(cocos2d::Vec2(0.5f, 0.85f));
		m_spriteBody->addChild(m_spriteHead);
		//m_spriteHead->setPosition(m_spriteBody->getContentSize().width / 2, m_spriteBody->getContentSize().height);

		//Shield
		m_spriteShield = cocos2d::Sprite::create();
		m_spriteShield->retain();
		m_spriteShield->setCameraMask(static_cast<int>(cocos2d::CameraFlag::USER2));
		m_spriteShield->setAnchorPoint(cocos2d::Vec2(0.5f, 1.0f));
		m_spriteBody->addChild(m_spriteShield);

		//Helmet
		m_spriteHelmet = cocos2d::Sprite::create();
		m_spriteHelmet->retain();
		m_spriteHelmet->setCameraMask(static_cast<int>(cocos2d::CameraFlag::USER2));
		m_spriteHelmet->setAnchorPoint(cocos2d::Vec2(0.5f, 0.5f));
		m_spriteBody->addChild(m_spriteHelmet);

		//Weapon
		m_spriteWeapon = cocos2d::Sprite::create();
		m_spriteWeapon->retain();
		m_spriteWeapon->setCameraMask(static_cast<int>(cocos2d::CameraFlag::USER2));
		m_spriteWeapon->setAnchorPoint(cocos2d::Vec2(0.5f, 1.0f));
		m_spriteBody->addChild(m_spriteWeapon);
	}
	~PlayerBodyComponent()
	{
		if (m_spriteBody)
			if (m_spriteBody->getReferenceCount() > 0)
				m_spriteBody->release();

		if (m_spriteHead)
			if (m_spriteHead->getReferenceCount() > 0)
				m_spriteHead->release();

		if (m_spriteShield)
			if (m_spriteShield->getReferenceCount() > 0)
				m_spriteShield->release();

		if (m_spriteHelmet)
			if (m_spriteHelmet->getReferenceCount() > 0)
				m_spriteHelmet->release();

		if (m_spriteWeapon)
			if (m_spriteWeapon->getReferenceCount() > 0)
				m_spriteWeapon->release();

#if _DEBUG
		cocos2d::log("%s Destructor", "[PLAYERBODYCOMPONENT COMPONENT]");
#endif
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

	virtual cocos2d::Sprite* getShieldSpr() override
	{
		return m_spriteShield;
	}
	virtual void setShieldSpr(cocos2d::Sprite* shield) override
	{
		m_spriteShield = shield;
	}

	virtual cocos2d::Sprite* getHelmetSpr() override
	{
		return m_spriteHelmet;
	}
	virtual void setHelmetSpr(cocos2d::Sprite* helmet) override
	{
		m_spriteHelmet = helmet;
	}

	virtual cocos2d::Sprite* getWeaponSpr() override
	{
		return m_spriteWeapon;
	}
	virtual void setWeaponSpr(cocos2d::Sprite* weapon) override
	{
		m_spriteWeapon = weapon;
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

	virtual bool getAttacking() override
	{
		return m_attacking;
	}
	virtual void setAttacking(bool a) override
	{
		m_attacking = a;
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

	virtual Body getBody() override
	{
		return m_body;
	}
	virtual void setBody(Body body) override
	{
		m_body = body;
	}

	virtual Head getHead() override
	{
		return m_head;
	}
	virtual void setHead(Head head) override
	{
		m_head = head;
	}

	virtual Shield getShield() override
	{
		return m_shield;
	}
	virtual void setShield(Shield shield) override
	{
		m_shield = shield;
	}

	virtual Helmet getHelmet() override
	{
		return m_helmet;
	}
	virtual void setHelmet(Helmet helmet) override
	{
		m_helmet = helmet;
	}

	virtual Weapon getWeapon() override
	{
		return m_weapon;
	}
	virtual void setWeapon(Weapon weapon) override
	{
		m_weapon = weapon;
	}



	virtual unsigned int getBodyGs(Direction dir) override
	{
		return m_bodyGs[dir];
	}
	virtual void setBodyGs(Direction dir, unsigned int gid) override
	{
		m_bodyGs[dir] = gid;
	}

	virtual unsigned int getHeadGs(Direction dir) override
	{
		return m_headGs[dir];
	}
	virtual void setHeadGs(Direction dir, unsigned int gid) override
	{
		m_headGs[dir] = gid;
	}

	virtual unsigned int getShieldGs(Direction dir) override
	{
		return m_shieldGs[dir];
	}
	virtual void setShieldGs(Direction dir, unsigned int gid) override
	{
		m_shieldGs[dir] = gid;
	}

	virtual unsigned int getHelmetGs(Direction dir) override
	{
		return m_helmetGs[dir];
	}
	virtual void setHelmetGs(Direction dir, unsigned int gid) override
	{
		m_helmetGs[dir] = gid;
	}

	virtual unsigned int getWeaponGs(Direction dir) override
	{
		return m_weaponGs[dir];
	}
	virtual void setWeaponGs(Direction dir, unsigned int gid) override
	{
		m_weaponGs[dir] = gid;
	}

	virtual cocos2d::Animate* getAnimBody() override
	{
		return m_animBody[m_direction];
	}
	virtual void setAnimBody(Direction dir, cocos2d::Animate* anim) override
	{
		m_animBody[dir] = anim;
	}

	virtual cocos2d::Animate* getAnimShield() override
	{
		return m_animShield[m_direction];
	}
	virtual void setAnimShield(Direction dir, cocos2d::Animate* anim) override
	{
		m_animShield[dir] = anim;
	}

	virtual cocos2d::Animate* getAnimWeapon() override
	{
		return m_animWeapon[m_direction];
	}
	virtual void setAnimWeapon(Direction dir, cocos2d::Animate* anim) override
	{
		m_animWeapon[dir] = anim;
	}

	virtual cocos2d::Animate* getAnimBlood() override
	{
		return m_animBlood;
	}
	virtual void setAnimBlood(cocos2d::Animate* anim) override
	{
		m_animBlood = anim;
	}

	virtual cocos2d::Animate* getAnimApocalipsis() override
	{
		return m_animApocalipsis;
	}
	virtual void setAnimApocaipsis(cocos2d::Animate* anim) override
	{
		m_animApocalipsis = anim;
	}

private:
	cocos2d::Sprite* m_spriteBody;
	cocos2d::Sprite* m_spriteHead; //child of body
	cocos2d::Sprite* m_spriteShield; //child of body
	cocos2d::Sprite* m_spriteHelmet; //child of body
	cocos2d::Sprite* m_spriteWeapon; //child of body
	const ComponentType m_type = ComponentType::PLAYER_BODY;
	bool m_moving = false;
	bool m_canWalk = true;
	bool m_attacking = false;
	Direction m_direction = Direction::South;
	Race m_race;
	Genre m_genre;
	Body m_body;
	Head m_head;
	Shield m_shield;
	Helmet m_helmet;
	Weapon m_weapon;

	unsigned int m_bodyGs[4];
	unsigned int m_headGs[4];
	unsigned int m_shieldGs[4];
	unsigned int m_helmetGs[4];
	unsigned int m_weaponGs[4];

	cocos2d::Animate* m_animBody[4];
	cocos2d::Animate* m_animShield[4];
	cocos2d::Animate* m_animWeapon[4];
	cocos2d::Animate* m_animBlood;
	cocos2d::Animate* m_animApocalipsis;
};

#endif // __SPRITE_COMPONENT_H__
