#ifndef __CAMERA_SYSTEM_H__
#define __CAMERA_SYSTEM_H__

#include "ECS/ECS_Engine.h"

//#include "Components/Layer3DComponent.h"

#include "cocos2d.h"

class CameraSystem : public ECS::System
{
public:
	CameraSystem(cocos2d::Scene* scene);
	~CameraSystem();

	virtual void update(float dt) override;

	void setLocalEntity(int eid, cocos2d::Event* ccevnt, SLNet::BitStream* bs);
	void addLayerToEid(int eid, cocos2d::Event* ccevnt, SLNet::BitStream* bs);
	void zoomIn(int eid, cocos2d::Event* ccevnt, SLNet::BitStream* bs);
	void zoomOut(int eid, cocos2d::Event* ccevnt, SLNet::BitStream* bs);


	//void moveNorth(int eid, cocos2d::Event* ccevnt, SLNet::BitStream* bs);
	//void moveEast(int eid, cocos2d::Event* ccevnt, SLNet::BitStream* bs);
	//void moveSouth(int eid, cocos2d::Event* ccevnt, SLNet::BitStream* bs);
	//void moveWest(int eid, cocos2d::Event* ccevnt, SLNet::BitStream* bs);

private:
	ECS::EntityManager* m_entityManager;
	ECS::EventManager* m_eventManager;
	cocos2d::Director* m_director;

	int m_localeid;
	cocos2d::Camera* m_camera;
	Layer3DComponent* m_layer3D;
	cocos2d::Scene* m_scene;
	int m_Z;

	
	float x = .0f, y = .0f;
};

#endif // __CAMERA_SYSTEM_H__