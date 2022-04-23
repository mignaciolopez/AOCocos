#ifndef __SPRITE_COMPONENT_H__
#define __SPRITE_COMPONENT_H__

#include "Components/Enums.h"

#include "ECS/ECS_Log.h"

class PlayerComponent
{
public:
	PlayerComponent(
		Directions dir, Genres genre, Races race, Bodies body, Heads head, 
		Shields shield, Helmets helmet, Weapons weapon)
	{
		ECS_Log::s_consoleL->trace("[PlayerComponent] Constructor");

		_direction = dir;
		_genre = genre;
		_race = race;
		_body = body;
		_head = head;
		_shield = shield;
		_helmet = helmet;
		_weapon = weapon;
	}
	~PlayerComponent()
	{
		ECS_Log::s_consoleL->trace("[PlayerComponent] Destructor");	
	}

	bool _attacking = false;
	bool _isAlive = true;

	Directions _direction = Directions::South;
	Races _race;
	Genres _genre;
	Bodies _body;
	Heads _head;
	Shields _shield;
	Helmets _helmet;
	Weapons _weapon;
};

#endif // __SPRITE_COMPONENT_H__
