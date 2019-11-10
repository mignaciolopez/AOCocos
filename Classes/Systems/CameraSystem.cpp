#include "CameraSystem.h"
#include "Scenes/DrawNode3D.h"

USING_NS_CC;

CameraSystem::CameraSystem(cocos2d::Scene* scene)
{
	cocos2d::log("%s Constructor", "[CAMERA SYSTEM]");

	m_scene = scene;

	m_entityManager = ECS::ECS_Engine::getInstance()->getEntityManager();
	m_director = cocos2d::Director::getInstance();
	m_eventManager = ECS::ECS_Engine::getInstance()->getEventManager();

	m_eventManager->Subscribe(EVENTS::MY_EID, &CameraSystem::setLocalEntity, this);
	m_eventManager->Subscribe(EVENTS::CAMERA_LAYER_ADD, &CameraSystem::addLayerToEid, this);


	auto s = m_director->getWinSize();

	m_layer3D = new (std::nothrow) Layer3DComponent;

	//m_camera = Camera::createPerspective(60, (GLfloat)s.width / s.height, 1, 1000);
	m_camera = Camera::createOrthographic(s.width, s.height, 1, 1000);
	m_camera->retain();
	m_camera->setCameraFlag(CameraFlag::USER1);
	m_layer3D->getLayer()->addChild(m_camera);
	m_layer3D->getLayer()->setCameraMask(2);
	m_scene->addChild(m_layer3D->getLayer(), 0);

	m_localeid = -1;

	//just to debug camera, remove after////////////////////////////
	/*cocos2d::DrawNode3D* line = cocos2d::DrawNode3D::create();
	//draw x
	for (int j = -20; j <= 20; j++)
	{
		line->drawLine(Vec3(-100, 0, 5 * j), Vec3(100, 0, 5 * j), Color4F(1, 0, 0, 1));
	}
	//draw z
	for (int j = -20; j <= 20; j++)
	{
		line->drawLine(Vec3(5 * j, 0, -100), Vec3(5 * j, 0, 100), Color4F(0, 0, 1, 1));
	}
	//draw y
	line->drawLine(Vec3(0, -50, 0), Vec3(0, 0, 0), Color4F(0, 0.5, 0, 1));
	line->drawLine(Vec3(0, 0, 0), Vec3(0, 50, 0), Color4F(0, 1, 0, 1));
	m_layer3D->getLayer()->addChild(line);*/
	//just to debug camera, remove after////////////////////////////
}

CameraSystem::~CameraSystem()
{
	m_entityManager->removeComponent(m_localeid, LAYER3D);

	if (m_layer3D)
	{
		//delete m_layer3D;
		m_layer3D = nullptr;
	}

	if (m_camera)
		if (m_camera->getReferenceCount() > 0)
			m_camera->release();

	cocos2d::log("%s Destructor", "[CAMERA SYSTEM]");
}

void CameraSystem::Update()
{
	if (m_localeid != -1)
	{
		cocos2d::Vec2 pos = m_entityManager->getComp(m_localeid, ComponentType::PLAYER_BODY)
			->getBodySpr()->getPosition();

		for (auto cam : m_director->getRunningScene()->getCameras())
		{
			cam->setPosition3D(cocos2d::Vec3(pos.x, pos.y, 300));
			cam->lookAt(cocos2d::Vec3(pos.x, pos.y, 10));
			cam->setRotation3D(cocos2d::Vec3::ZERO);
		}
	}
}

void CameraSystem::setLocalEntity(int eid, cocos2d::Event * ccevnt, SLNet::BitStream * bs)
{
	m_localeid = eid;
}

void CameraSystem::addLayerToEid(int eid, cocos2d::Event * ccevnt, SLNet::BitStream * bs)
{
	m_entityManager->AddComponentToEntity(eid, m_layer3D);
}
