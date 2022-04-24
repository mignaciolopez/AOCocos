#ifndef INPUT_SYSTEM_H__
#define INPUT_SYSTEM_H__

#include "BitStream.h"
#include "cocos2d.h"

#include "entt.hpp"

#include "ECS/iSystems/iSystem.h"

#include "ECS/SignalsManager.h"

#include "Graphics/Graphics.h"

class InputSystem : public ECS::iSystem
{
public:
	const ECS::iSystemTags _tag = ECS::iSystemTags::InputSystem_tag;
	InputSystem(cocos2d::Scene* scene, entt::registry* registry);
	~InputSystem();

	virtual void update(float dt) override;

	void setLocalEntity(entt::entity entity, SLNet::BitStream* bs);

private:
#if (CC_TARGET_PLATFORM == CC_PLATFORM_WIN32 || CC_TARGET_PLATFORM == CC_PLATFORM_LINUX || CC_TARGET_PLATFORM == CC_PLATFORM_MAC)
	void keyPressed(cocos2d::EventKeyboard::KeyCode keyCode);
	void keyReleased(cocos2d::EventKeyboard::KeyCode keyCode);

	void ReleaseKeyManually(cocos2d::EventKeyboard::KeyCode keyCode);
#endif // !Destop Platform



public:


private:
	cocos2d::Director* m_director;
	cocos2d::Scene* m_scene;
	entt::registry* m_registry;
	entt::entity m_localEntt = entt::null;

	ECS::SignalsManager* m_signalsManager;

#if (CC_TARGET_PLATFORM == CC_PLATFORM_WIN32 || CC_TARGET_PLATFORM == CC_PLATFORM_LINUX || CC_TARGET_PLATFORM == CC_PLATFORM_MAC)
	cocos2d::EventListenerKeyboard* m_kbListener;
	bool m_keyStates[256];
#endif // !Destop Platform

#if (CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID || CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
	
#endif // !Mobile Platform


	int animation = 0;
};

#endif // INPUT_SYSTEM_H__