#ifndef __MAP_COMPONENT_H__
#define __MAP_COMPONENT_H__

#include "ECS/Components/Component.h"

#include "cocos2d.h"

class MapComponent : public ECS::Component
{
public:
	MapComponent()
	{
		cocos2d::log("%s Constructor", "[MAP COMPONENT]");

		m_map = nullptr;
	}
	~MapComponent()
	{
		if (m_map)
		{
			if (m_map->getReferenceCount() > 0)
				m_map->release();
		}
#if _DEBUG
		cocos2d::log("%s Destructor", "[MAP COMPONENT]");
#endif
	}

	virtual ComponentType getType() override
	{
		return m_type;
	}

	virtual cocos2d::TMXTiledMap* getMap() override
	{
		return m_map;
	}

	virtual void setMap(cocos2d::TMXTiledMap* map) override
	{
		m_map = map;
	}

private:
	const ComponentType m_type = ComponentType::MAP;

	cocos2d::TMXTiledMap* m_map;

	int m_tag;
	
};
#endif // !__MAP_COMPONENT_H__
