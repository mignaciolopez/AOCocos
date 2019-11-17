#ifndef __INPUT_SYSTEM_H__
#define __INPUT_SYSTEM_H__

#include "ECS/ECS_Engine.h"

namespace cocos2d
{
	class Director;
	class Scene;
}

class InputSystem : public ECS::System
{
public:
	InputSystem(cocos2d::Scene* scene);
	~InputSystem();

	virtual void Update() override;
	void setLocalEntity(int eid, cocos2d::Event* ccevent, SLNet::BitStream* bs);

private:
	void keyPressed(cocos2d::EventKeyboard::KeyCode keyCode);
	void keyReleased(cocos2d::EventKeyboard::KeyCode keyCode);

	void ReleaseKeyManually(cocos2d::EventKeyboard::KeyCode keyCode);

	void onMouseDown(cocos2d::Event* event);
	void onMouseMove(cocos2d::Event  *evnt);
	void onMouseScroll(cocos2d::Event  *evnt);
	void onMouseUp(cocos2d::Event  *evnt);

public:


private:
	std::vector<ComponentType> m_compatibleComponents;

	ECS::EventManager* m_eventManager;
	ECS::EntityManager* m_entityManager;
	cocos2d::Director* m_director;
	cocos2d::Scene* m_scene;

	cocos2d::EventListenerKeyboard* m_kbListener;
	bool m_keyStates[256];

	
	cocos2d::EventListenerMouse* m_mouseListener;

	int m_localeid;

};

#endif // __INPUT_SYSTEM_H__