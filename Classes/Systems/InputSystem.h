#ifndef __INPUT_SYSTEM_H__
#define __INPUT_SYSTEM_H__

#include "ECS/ECSEngine.h"

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

private:
	bool IsKeyPressed(cocos2d::EventKeyboard::KeyCode keyCode);

	void ReleaseKeyManually(cocos2d::EventKeyboard::KeyCode keyCode);

public:


private:
	std::vector<ComponentType> m_compatibleComponents;

	ECS::ComponentManager* m_componentManager;
	ECS::EventManager* m_eventManager;
	cocos2d::Director* m_director;

	cocos2d::EventListenerKeyboard* m_kbListener;
	std::map<cocos2d::EventKeyboard::KeyCode, bool> m_keys;

};

#endif // __INPUT_SYSTEM_H__