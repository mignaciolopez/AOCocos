#ifndef UI_SYSTEM_H__
#define UI_SYSTEM_H__

#include "cocos2d.h"

#include "ECS/SignalsManager.h"
#include "entt.hpp"

#include "ECS/iSystems/iSystem.h"

#include "Graphics/Graphics.h"

class UISystem : public ECS::iSystem
{
public:
	const ECS::iSystemTags _tag = ECS::iSystemTags::UISystem_tag;
	UISystem(cocos2d::Scene* scene, entt::registry* registry);
	~UISystem();

	virtual void update(float dt) override;

	void onConstructHudDebugC(entt::registry& registry, entt::entity entity);

	void onDestroyTableSpellsC(entt::registry& registry, entt::entity entity);
	void onDestroyHudDebugC(entt::registry& registry, entt::entity entity);
	void onDestroyHudC(entt::registry& registry, entt::entity entity);

	void setLocalEntity(entt::entity entity, SLNet::BitStream* bs);

	void graphicsReload(entt::entity entity, SLNet::BitStream* bs);

#if (CC_TARGET_PLATFORM == CC_PLATFORM_WIN32 || CC_TARGET_PLATFORM == CC_PLATFORM_LINUX || CC_TARGET_PLATFORM == CC_PLATFORM_MAC)
	void mouseReleased(entt::entity entity, SLNet::BitStream* bs);

	void toogleFullscreen(entt::entity entity, SLNet::BitStream* bs);
	void toggleVSync(entt::entity entity, SLNet::BitStream* bs);
#endif // !Desktop Platform

	void toggleDebugInfo(entt::entity entity, SLNet::BitStream* bs);
	void setlblNetwork(entt::entity entity, SLNet::BitStream* bs);
	void updateDebugInfo(entt::entity entity, SLNet::BitStream* bs);

	bool onTouchBegan(const cocos2d::Touch* touch, cocos2d::Event* ccEvnt);
	void onTouchMoved(const cocos2d::Touch* touch, cocos2d::Event* ccEvnt);
	void onTouchEnded(const cocos2d::Touch* touch, cocos2d::Event* ccEvnt);
	void onTouchCancelled(const cocos2d::Touch* touch, cocos2d::Event* ccEvnt);

private:
	void updatelblPosition();

	void toggleInventory(float x, float y);
	void castSpell(float x, float y);


private:
	ECS::SignalsManager* m_signalsManager;
	entt::registry* m_registry;
	
	cocos2d::Director* m_director;
	cocos2d::SpriteFrameCache* sfCache;

	cocos2d::Scene* m_scene;

	entt::entity m_localEntt = entt::null;
	Graphics* m_graphics;

	cocos2d::EventListenerTouchOneByOne* m_touchListener;

	bool m_showDebug;
	bool m_vsync;
	
	bool m_spellCasted;

};

#endif // !UI_SYSTEM_H__