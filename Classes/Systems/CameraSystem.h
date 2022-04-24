#ifndef CAMERA_SYSTEM_H__
#define CAMERA_SYSTEM_H__

#include "cocos2d.h"

#include "ECS/SignalsManager.h"
#include "entt.hpp"

#include "ECS/iSystems/iSystem.h"

class CameraSystem : public ECS::iSystem
{
public:
	const ECS::iSystemTags _tag = ECS::iSystemTags::CameraSystem_tag;
	CameraSystem(entt::registry* registry);
	~CameraSystem();

	virtual void update(float dt) override;

	void onDestroyMapCameraC(entt::registry& registry, entt::entity entity);

	void setLocalEntity(entt::entity entity, SLNet::BitStream* bs);

	void zoomIn(entt::entity entity, SLNet::BitStream* bs);
	void zoomOut(entt::entity entity, SLNet::BitStream* bs);

private:
	ECS::SignalsManager* m_signalsManager;
	entt::registry* m_registry;

	cocos2d::Director* m_director;
	entt::entity m_localEntt = entt::null;

	int m_Z;

	float x = .0f, y = .0f;
};

#endif // !CAMERA_SYSTEM_H__