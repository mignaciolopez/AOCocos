#ifndef __EVENT_LIST_H__
#define __EVENT_LIST_H__

#include "SlikeNet/MessageIdentifiers.h"

enum EVENTS
{
	FIRST = ID_USER_PACKET_ENUM + 1,	//USED for iteration DO NOT REMOVE

	SEND_CLIENT,				//Used by Server
	SEND_BROADCAST,

	SEND_SERVER,				//Used by client

	REQUEST_EID,
	MY_EID,
	EID_JOINED,
	EID_QUIT,
	SYNC_PLAYERS,

	MOVE_NORTH,					//Movements
	MOVE_EAST,
	MOVE_SOUTH,
	MOVE_WEST,

	ANIMATE,
	LOAD_ANIMATION_INFO,

	MOUSE_PRESSED,				//Mouse Events
	MOUSE_RELEASED,
	MOUSE_SCROLL,
	MOUSE_MOVE,

	UI_TOGGLE_FULLSCREEN,		// UI Events

	LAST		//USED for iteration DO NOT REMOVE
};

#endif // __EVENT_LIST_H__