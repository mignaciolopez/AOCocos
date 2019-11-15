#include "CameraSystem.h"
#include "Scenes/DrawNode3D.h"

USING_NS_CC;

CameraSystem::CameraSystem(cocos2d::Scene* scene) : m_scene(scene)
{
	cocos2d::log("%s Constructor", "[CAMERA SYSTEM]");

	m_entityManager = ECS::ECS_Engine::getInstance()->getEntityManager();
	m_director = cocos2d::Director::getInstance();
	m_eventManager = ECS::ECS_Engine::getInstance()->getEventManager();

	m_eventManager->Subscribe(EVENTS::MY_EID, &CameraSystem::setLocalEntity, this);
	m_eventManager->Subscribe(EVENTS::CAMERA_LAYER_ADD, &CameraSystem::addLayerToEid, this);

	m_eventManager->Subscribe(EVENTS::CAMERA_ZOOM_IN, &CameraSystem::zoomIn, this);
	m_eventManager->Subscribe(EVENTS::CAMERA_ZOOM_OUT, &CameraSystem::zoomOut, this);

	//m_eventManager->Subscribe(EVENTS::MOVE_NORTH, &CameraSystem::moveNorth, this);
	//m_eventManager->Subscribe(EVENTS::MOVE_EAST, &CameraSystem::moveEast, this);
	//m_eventManager->Subscribe(EVENTS::MOVE_SOUTH, &CameraSystem::moveSouth, this);
	//m_eventManager->Subscribe(EVENTS::MOVE_WEST, &CameraSystem::moveWest, this);


	auto sizeInpixels = Director::getInstance()->getWinSizeInPixels();
	auto size = Director::getInstance()->getWinSize();
	auto fboSize = Size(544,416);
	auto fbo = experimental::FrameBuffer::create(1, fboSize.width, fboSize.height);

	auto rt = experimental::RenderTarget::create(fboSize.width, fboSize.height);
	auto rtDS = experimental::RenderTargetDepthStencil::create(fboSize.width, fboSize.height);
	fbo->attachRenderTarget(rt);
	fbo->attachDepthStencilTarget(rtDS);

	
	m_camera = Camera::create();
	auto sprite = Sprite::createWithTexture(fbo->getRenderTarget()->getTexture());
	sprite->setFlippedY(true);
	sprite->setPosition(10, 44);
	sprite->setAnchorPoint(Vec2(0.0f, 0.0f));
	sprite->setCameraMask(static_cast<int>(CameraFlag::USER1));
	scene->addChild(sprite, 3);

	
	//m_camera = Camera::createPerspective(60, (GLfloat)fboSize.width / fboSize.height, 0.0f, 3000.0f);
	//m_camera = Camera::createOrthographic(fboSize.width, fboSize.height, 1.0f, 1000.0f);
	//
	m_camera->setDepth(-1);
	m_camera->setFrameBufferObject(fbo);
	m_camera->setCameraFlag(CameraFlag::USER2);

	m_layer3D = new (std::nothrow) Layer3DComponent;
	m_layer3D->getLayer()->addChild(m_camera);
	m_layer3D->getLayer()->setCameraMask(static_cast<int>(CameraFlag::USER2));

	//experimental::Viewport vp = experimental::Viewport(0.0f, 0.0f, size.width, size.height / 2);
	//m_camera->setViewport(vp);

	m_camera->setPosition3D(Vec3(0.f, 0.f, 0.0f));
	m_camera->lookAt(Vec3::ZERO);
	m_camera->setRotation3D(Vec3::ZERO);

	m_scene->addChild(m_layer3D->getLayer(), 0);

	m_localeid = -1;
	m_Z = 350;
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
	m_layer3D->getLayer()->addChild(line);
	line->setCameraMask(static_cast<int>(CameraFlag::USER2));
	line->setPosition3D(cocos2d::Vec3(208.0f + 6, 416.0f / 2.0f + 32, 0.0f));
	line->setAnchorPoint(Vec2(0.0f, 0.0f));*/
	//just to debug camera, remove after////////////////////////////
}

CameraSystem::~CameraSystem()
{
	if (Director::getInstance())
	{
		if (Director::getInstance()->getRunningScene())
		{
			if (m_layer3D)
				if (m_layer3D->getLayer())
					if (Director::getInstance()->getRunningScene() == m_layer3D->getLayer()->getParent())
						Director::getInstance()->getRunningScene()->removeChild(m_layer3D->getLayer());
			if (m_camera)
			{
				if (Director::getInstance()->getRunningScene() == m_camera->getParent())
					Director::getInstance()->getRunningScene()->removeChild(m_camera);
				if (m_camera->getReferenceCount() > 0)
					m_camera->release();
			}
		}
	}

	if (m_entityManager)
		m_entityManager->removeComponent(m_localeid, LAYER3D);

	if (m_layer3D)
	{
		m_layer3D = nullptr;
	}
#if _DEBUG
	cocos2d::log("%s Destructor", "[CAMERA SYSTEM]");
#endif
}

void CameraSystem::Update()
{
	if (m_localeid != -1)
	{
		cocos2d::Vec2 pos = m_entityManager->getComp(m_localeid, ComponentType::PLAYER_BODY)
			->getBodySpr()->getPosition();

		m_camera->setPosition3D(Vec3(pos.x, pos.y, m_Z));
		m_camera->lookAt(Vec3(pos.x, pos.y, 0.f));
		m_camera->setRotation3D(Vec3::ZERO);
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

void CameraSystem::zoomIn(int eid, cocos2d::Event * ccevnt, SLNet::BitStream * bs)
{		
	if (m_Z > 10)
		m_Z--;
	log("[CAMERA SYSTEM] Zoom: %i", m_Z);
}

void CameraSystem::zoomOut(int eid, cocos2d::Event * ccevnt, SLNet::BitStream * bs)
{
	if (m_Z < 800)
		m_Z++;
	log("[CAMERA SYSTEM] Zoom: %i", m_Z);
}

/*
void CameraSystem::moveNorth(int eid, cocos2d::Event * ccevnt, SLNet::BitStream * bs)
{
	y += 0.5f;
	log("[CAMERA SYSTEM] %f, %f", x, y);
}

void CameraSystem::moveEast(int eid, cocos2d::Event * ccevnt, SLNet::BitStream * bs)
{
	x += 0.5f;
	log("[CAMERA SYSTEM] %f, %f", x, y);
}

void CameraSystem::moveSouth(int eid, cocos2d::Event * ccevnt, SLNet::BitStream * bs)
{
	y -= 0.5f;
	log("[CAMERA SYSTEM] %f, %f", x, y);
}

void CameraSystem::moveWest(int eid, cocos2d::Event * ccevnt, SLNet::BitStream * bs)
{
	x -= 0.5f;
	log("[CAMERA SYSTEM] %f, %f", x, y);
}
*/