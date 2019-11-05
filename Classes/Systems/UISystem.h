#ifndef __UI_SYSTEM_H__
#define __UI_SYSTEM_H__

#include "ECS/ECS_Engine.h"

namespace cocos2d
{
	class Director;
}

class UISystem : public ECS::System
{
public:
	UISystem();
	~UISystem();

	virtual void Update() override;

	void clicked(int eid, cocos2d::Event* ccevent, SLNet::BitStream* bs);
	void toogleFullscreen(int eid, cocos2d::Event* ccevent, SLNet::BitStream* bs);

private:
	std::vector<ComponentType> m_compatibleComponents;

	ECS::EventManager* m_eventManager;
	cocos2d::Director* m_director;

	const cocos2d::Size m_windowSize = cocos2d::Size(800, 600);
};

#endif // __UI_SYSTEM_H__