#ifndef __UI_SYSTEM_H__
#define __UI_SYSTEM_H__

#include "ECS/ECSEngine.h"

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

	void clicked(unsigned int eid, unsigned int cid, cocos2d::Event* ccevent);
	void toogleFullscreen(unsigned int eid, unsigned int cid, cocos2d::Event* ccevent);

private:
	std::vector<ComponentType> m_compatibleComponents;

	ECS::ComponentManager* m_componentManager;
	ECS::EventManager* m_eventManager;
	cocos2d::Director* m_director;

	const cocos2d::Size m_windowSize = cocos2d::Size(800, 600);
};

#endif // __RENDER_SYSTEM_H__