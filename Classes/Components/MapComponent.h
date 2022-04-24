#ifndef MAP_COMPONENT_H__
#define MAP_COMPONENT_H__

#include "cocos2d.h"

class MapComponent final
{
public:
	MapComponent(int tag) : _tag(tag)
	{
#if _DEBUG
		cocos2d::log("[MapComponent] Constructor");
#endif
		
	}

	~MapComponent()
	{
#if _DEBUG
		cocos2d::log("[MapComponent] Destructor");
#endif
	}

	cocos2d::TMXTiledMap* _map;
	int _tag;
	std::string _mapName;
	std::string _path;

	//cocos2d::Vec2 _lastTouch;
	
};
#endif // !MAP_COMPONENT_H__
