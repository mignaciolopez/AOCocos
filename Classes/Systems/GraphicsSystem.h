#ifndef GRAPHICS_SYSTEM_H__
#define GRAPHICS_SYSTEM_H__

#include "cocos2d.h"

#include "ECS/SignalsManager.h"
#include "entt.hpp"

#include "ECS/iSystems/iSystem.h"

#include "Graphics/Graphics.h"

class GraphicsSystem : public ECS::iSystem
{
public:
	const ECS::iSystemTags _tag = ECS::iSystemTags::GraphicsSystem_tag;
	GraphicsSystem(entt::registry* registry);
	~GraphicsSystem();

	virtual void update(float dt) override;

	void onConstructPlayerC(entt::registry& registry, entt::entity entity);
	void onDestroyPlayerC(entt::registry& registry, entt::entity entity);

	void setLocalEntity(entt::entity entity, SLNet::BitStream* bs);
	void loadBody(entt::entity entity, SLNet::BitStream* bs);
	void loadHead(entt::entity entity, SLNet::BitStream* bs);

	void graphicsReload(entt::entity entity, SLNet::BitStream* bs);

private:
	ECS::SignalsManager* m_signalsManager;
	entt::registry* m_registry;

	entt::entity m_localEntt = entt::null;

	cocos2d::FileUtils* m_fileUtils;
	cocos2d::SpriteFrameCache* m_sfCache;

	Graphics* m_graphics;
};

#endif // !GRAPHICS_SYSTEM_H__