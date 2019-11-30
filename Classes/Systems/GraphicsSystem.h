#ifndef __GRAPHICS_SYSTEM_H__
#define __GRAPHICS_SYSTEM_H__

#include "ECS/ECS_Engine.h"

#include "cocos2d.h"

class GraphicsSystem : public ECS::System
{
public:
	GraphicsSystem();
	~GraphicsSystem();

	virtual void Update() override;
	void setLocaleid(int eid, cocos2d::Event* ccEvent, SLNet::BitStream* bs);
	void setGraphicsForPlayer(int eid, cocos2d::Event* ccEvent, SLNet::BitStream* bs);
	void loadBody(int eid, cocos2d::Event* ccEvent, SLNet::BitStream* bs);
	void loadHead(int eid, cocos2d::Event* ccEvent, SLNet::BitStream* bs);
	void loadShield(int eid, cocos2d::Event* ccEvent, SLNet::BitStream* bs);
	void loadHelmet(int eid, cocos2d::Event* ccEvent, SLNet::BitStream* bs);
	void loadWeapon(int eid, cocos2d::Event* ccEvent, SLNet::BitStream* bs);

private:
	void loadGraphicsIndex();
	void loadTextures();
	void loadAnimations();

	void loadHeads();
	void loadBodies();
	void loadShields();
	void loadHelmets();
	void loadWeapons();

public:

private:
	int m_localeid;

	struct BufferedFile
	{
		unsigned char* buffer;
		int position = 0;

		template <typename T>
		T read(T* buff)
		{
			*buff = *((T*)((unsigned char*)buffer + position));
			position += sizeof(T);

			return *buff;
		}
	};

	struct GraphicData
	{
		uint32_t id;

		uint16_t startX;
		uint16_t startY;
		uint16_t width;
		uint16_t height;
		float tileWidth;
		float tileHeight;

		std::vector<uint32_t> frames;
		uint16_t framesCount;
		float speed;
	};

	ECS::EntityManager* m_entityManager;
	ECS::EventManager* m_eventManager;
	cocos2d::FileUtils* m_fileUtils;
	cocos2d::SpriteFrameCache* m_sfCache;

	std::map<unsigned int, GraphicData*> m_graphicsData;

	std::multimap<int, std::pair< unsigned int, Direction>> m_animationsHead;
	std::multimap<int, std::pair< unsigned int, Direction>> m_animationsBody;
	std::multimap<int, std::pair< unsigned int, Direction>> m_animationsHelmet;
	std::multimap<int, std::pair< unsigned int, Direction>> m_animationsWeapon;
	std::multimap<int, std::pair< unsigned int, Direction>> m_animationsShield;

	const float m_NS = 0.04f;
	const float m_EW = 0.05f;
};

#endif // !__GRAPHICS_SYSTEM_H__