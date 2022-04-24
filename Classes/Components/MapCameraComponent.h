#ifndef MAP_CAMERA_COMPONENT_H__
#define MAP_CAMERA_COMPONENT_H__

#include "cocos2d.h"

class MapCameraComponent final
{
public:
	MapCameraComponent(cocos2d::Scene* scene)
	{
#if _DEBUG
		cocos2d::log("[MapCameraComponent] Constructor");
#endif
		m_viewSize = cocos2d::Director::getInstance()->getVisibleSize();
		float csf = cocos2d::Director::getInstance()->getContentScaleFactor();
		_cameraOffset = cocos2d::Vec2(9 * 32 - 6, 8 * 32 - 19);
		//_cameraOffset = cocos2d::Vec2(_cameraOffset.x * csf, _cameraOffset.y * csf);

		//MAP CAMERA
		//_camera = cocos2d::Camera::create();
		//_camera = cocos2d::Camera::createPerspective(60, (GLfloat)m_viewSize.width / m_viewSize.height, 0.0f, 3000.0f);
		_camera = cocos2d::Camera::createOrthographic(m_viewSize.width, m_viewSize.height, 0.0f, 900.0f);
		_camera->setPosition3D(cocos2d::Vec3::ZERO);
		_camera->lookAt(cocos2d::Vec3::ZERO);
		_camera->setRotation3D(cocos2d::Vec3::ZERO);
		_camera->setDepth(-1);
		scene->addChild(_camera, 3);
		_camera->setCameraFlag(cocos2d::CameraFlag::USER1);
	}

	~MapCameraComponent()
	{
#if _DEBUG
		cocos2d::log("[MapCameraComponent] Destructor");
#endif
	}

	cocos2d::Camera* _camera;
	cocos2d::Vec2 _cameraOffset;
	float _zoom = 0;

private:
	cocos2d::Size m_viewSize;
	

};
#endif // !MAP_LAYER_COMPONENT_H__
