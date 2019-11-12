#ifndef __UI_SYSTEM_H__
#define __UI_SYSTEM_H__

#include "ECS/ECS_Engine.h"

#include "Graphics/Interface.h"

#include "cocos2d.h"

class UISystem : public ECS::System
{
public:
	UISystem(cocos2d::Scene* scene);
	~UISystem();

	virtual void Update() override;

	void clicked(int eid, cocos2d::Event* ccevnt, SLNet::BitStream* bs);
	void scroll(int eid, cocos2d::Event* ccevnt, SLNet::BitStream* bs);
	void toogleFullscreen(int eid, cocos2d::Event* ccevnt, SLNet::BitStream* bs);

private:
	std::vector<ComponentType> m_compatibleComponents;

	ECS::EventManager* m_eventManager;
	cocos2d::Director* m_director;
	cocos2d::SpriteFrameCache* sfCache;

	cocos2d::Scene* m_scene;

	const cocos2d::Size m_windowSize = cocos2d::Size(800, 600);
};

#endif // __UI_SYSTEM_H__