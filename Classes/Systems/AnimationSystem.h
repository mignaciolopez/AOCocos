#ifndef ANIMATION_SYSTEM_H__
#define ANIMATION_SYSTEM_H__

#include "cocos2d.h"

#include "ECS/SignalsManager.h"
#include "entt.hpp"

#include "ECS/iSystems/iSystem.h"

#include "Graphics/Graphics.h"

class AnimationSystem : public ECS::iSystem
{
public:
	const ECS::iSystemTags _tag = ECS::iSystemTags::AnimationSystem_tag;
	AnimationSystem(entt::registry* registry);
	~AnimationSystem();

	virtual void update(float dt) override;

	void setLocalEntity(entt::entity entity, SLNet::BitStream* bs);

	void animateWalk(entt::entity entity, SLNet::BitStream* bs);
	void setBodyAll(entt::entity entity, SLNet::BitStream* bs);
	void animateSpell(entt::entity entity, SLNet::BitStream* bs);
	void animateWeapon(entt::entity entity, SLNet::BitStream * bs);
	void animateShield(entt::entity entity, SLNet::BitStream * bs);

	void graphicsReload(entt::entity entity, SLNet::BitStream* bs);

	void setBody(entt::entity entity, SLNet::BitStream* bs);
	void setHead(entt::entity entity, SLNet::BitStream* bs);
	void setHelmet(entt::entity entity, SLNet::BitStream* bs);
	void setShield(entt::entity entity, SLNet::BitStream* bs);
	void setWeapon(entt::entity entity, SLNet::BitStream* bs);

private:
	int getNewAnimTag();

	void animEnd(entt::entity entity, int tag);

public:

private:
	ECS::SignalsManager* m_signalsManager;
	entt::registry* m_registry;

	cocos2d::SpriteFrameCache* m_sfCache;
	
	std::map<int, cocos2d::Sprite*> m_animsRunning;

	entt::entity m_localEntt = entt::null;

	Graphics* m_graphics;
};

#endif //!ANIMATION_SYSTEM_H__