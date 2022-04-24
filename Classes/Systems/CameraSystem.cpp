#include "CameraSystem.h"

USING_NS_CC;

CameraSystem::CameraSystem(entt::registry* registry)
	: m_registry(registry)
{
#if _DEBUG
	cocos2d::log("[CameraSystem] Constructor");
#endif

	m_director = cocos2d::Director::getInstance();
	m_signalsManager = ECS::SignalsManager::getInstance();

	m_signalsManager->connect<&CameraSystem::setLocalEntity>(Signals::NW_MY_ENTT, this);

	m_signalsManager->connect<&CameraSystem::zoomIn>(Signals::CAMERA_ZOOM_IN, this);
	m_signalsManager->connect<&CameraSystem::zoomOut>(Signals::CAMERA_ZOOM_OUT, this);

	m_localEntt = entt::null;

	m_registry->on_destroy<MapCameraComponent>().connect<&CameraSystem::onDestroyMapCameraC>(this);
}

CameraSystem::~CameraSystem()
{
#if _DEBUG
	cocos2d::log("[CameraSystem] Destructor");
#endif
	
	
	ECS::SignalsManager::getInstance()->disconnectAll(this);

	if (m_registry->valid(m_localEntt))
	{
		m_registry->remove_if_exists<MapCameraComponent>(m_localEntt);
		m_localEntt = entt::null;
	}

	m_registry->on_destroy<MapCameraComponent>().disconnect<&CameraSystem::onDestroyMapCameraC>(this);
}

void CameraSystem::update(float dt)
{
	if (!m_registry->valid(m_localEntt))
		return;

	auto playerC = m_registry->try_get<PlayerComponent>(m_localEntt);
	auto mapCameraC = m_registry->try_get<MapCameraComponent>(m_localEntt);

	if (!playerC || !mapCameraC)
		return;

	float x = playerC->_spriteBody->getPosition().x - mapCameraC->_cameraOffset.x;
	float y = playerC->_spriteBody->getPosition().y - mapCameraC->_cameraOffset.y;

	mapCameraC->_camera->setPosition3D(Vec3(x, y, mapCameraC->_zoom));
	mapCameraC->_camera->lookAt(Vec3(x, y, 0.0f));
	mapCameraC->_camera->setRotation3D(Vec3::ZERO);
}

void CameraSystem::onDestroyMapCameraC(entt::registry & registry, entt::entity entity)
{
	if (!cocos2d::Director::getInstance()->getRunningScene())
		return;

	if (!cocos2d::Director::getInstance()->getRunningScene()->getUserData())
		return;

	auto mapCameraC = m_registry->try_get<MapCameraComponent>(m_localEntt);

	if (mapCameraC->_camera)
	{
		mapCameraC->_camera->removeAllChildren();

		if (mapCameraC->_camera->getParent())
			mapCameraC->_camera->getParent()->removeChild(mapCameraC->_camera);
	}
}

void CameraSystem::setLocalEntity(entt::entity entity,  SLNet::BitStream* bs)
{
	m_localEntt = entity;
}

void CameraSystem::zoomIn(entt::entity entity,  SLNet::BitStream* bs)
{		
	if (!m_registry->valid(m_localEntt))
		return;

	auto mapCameraC = m_registry->try_get<MapCameraComponent>(m_localEntt);

	if (!mapCameraC)
		return;

	if (mapCameraC->_zoom > 10)
		mapCameraC->_zoom--;

#if _DEBUG
	log("[CameraSystem] Zoom: %f", mapCameraC->_zoom);
#endif
}

void CameraSystem::zoomOut(entt::entity entity,  SLNet::BitStream* bs)
{
	if (!m_registry->valid(m_localEntt))
		return;

	auto mapCameraC = m_registry->try_get<MapCameraComponent>(m_localEntt);

	if (!mapCameraC)
		return;

	if (mapCameraC->_zoom < 800)
		mapCameraC->_zoom++;

#if _DEBUG
	log("[CameraSystem] Zoom: %f", mapCameraC->_zoom);
#endif
}
