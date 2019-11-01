#ifndef __EVENT_LIST_H__
#define __EVENT_LIST_H__

#include "SlikeNet/MessageIdentifiers.h"

enum EVENTS
{
	FIRST = ID_USER_PACKET_ENUM + 1,	//USED for iteration DO NOT REMOVE
	MOVE_NORTH,
	MOVE_EAST,
	MOVE_SOUTH,
	MOVE_WEST,
	MOUSE_PRESSED,
	MOUSE_RELEASED,
	MOUSE_SCROLL,
	MOUSE_MOVE,
	LAST		//USED for iteration DO NOT REMOVE
};

#endif // __EVENT_LIST_H__