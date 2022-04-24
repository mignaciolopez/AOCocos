#ifndef PLAYER_COMPONENT_H__
#define PLAYER_COMPONENT_H__

#include "Components/Enums.h"

#include "cocos2d.h"

class PlayerComponent
{
public:
	PlayerComponent(int x, int y,
		Directions dir, Genres genre, Races race, Bodies body, Heads head, 
		Shields shield, Helmets helmet, Weapons weapon)
	{
#if _DEBUG
		cocos2d::log("[PlayerComponent] Constructor");
#endif
		_bodyStandingFrame[0] = 0;
		_bodyStandingFrame[1] = 0;
		_bodyStandingFrame[2] = 0;
		_bodyStandingFrame[3] = 0;

		_headFrame[0] = 0;
		_headFrame[1] = 0;
		_headFrame[2] = 0;
		_headFrame[3] = 0;

		_helmetFrame[0] = 0;
		_helmetFrame[1] = 0;
		_helmetFrame[2] = 0;
		_helmetFrame[3] = 0;

		_shieldFrame[0] = 0;
		_shieldFrame[1] = 0;
		_shieldFrame[2] = 0;
		_shieldFrame[3] = 0;

		_weaponFrame[0] = 0;
		_weaponFrame[1] = 0;
		_weaponFrame[2] = 0;
		_weaponFrame[3] = 0;

		_animBody[0] = nullptr;
		_animBody[1] = nullptr;
		_animBody[2] = nullptr;
		_animBody[3] = nullptr;

		_animShield[0] = nullptr;
		_animShield[1] = nullptr;
		_animShield[2] = nullptr;
		_animShield[3] = nullptr;
		
		_animWeapon[0] = nullptr;
		_animWeapon[1] = nullptr;
		_animWeapon[2] = nullptr;
		_animWeapon[3] = nullptr;

		_x = x;
		_y = y;
		_direction = dir;
		_genre = genre;
		_race = race;
		_body = body;
		_head = head;
		_helmet = helmet;
		_shield = shield;
		_weapon = weapon;
	}

	~PlayerComponent()
	{
#if _DEBUG
		cocos2d::log("[PlayerComponent] Destructor");
#endif		
	}

	cocos2d::Sprite* _spriteBody = nullptr;
	cocos2d::Sprite* _spriteHead = nullptr; //child of body
	cocos2d::Sprite* _spriteShield = nullptr; //child of body
	cocos2d::Sprite* _spriteHelmet = nullptr; //child of body
	cocos2d::Sprite* _spriteWeapon = nullptr; //child of body

	bool _isAlive = true;

	int _x = 0;
	int _y = 0;

	Directions _direction = Directions::South;
	Races _race = Races::Human;
	Genres _genre = Genres::Male;
	Bodies _body = Bodies::Body_Casper_White;
	Heads _head = Heads::Head_Human_Male_Brown;
	Helmets _helmet = Helmets::NoHelmet;
	Shields _shield = Shields::NoShield;
	Weapons _weapon = Weapons::NoWeapon;

	uint32_t _bodyStandingFrame[4];
	uint32_t _headFrame[4];
	uint32_t _helmetFrame[4];
	uint32_t _shieldFrame[4];
	uint32_t _weaponFrame[4];

	cocos2d::Animate* _animBody[4];
	cocos2d::Animate* _animShield[4];
	cocos2d::Animate* _animWeapon[4];

	Bodies _lastBody = Bodies::Body_Casper_White;
	Heads _lastHead = Heads::Head_Human_Male_Brown;
};

#endif // !PLAYER_COMPONENT_H__
