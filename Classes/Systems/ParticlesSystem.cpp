#include "ParticlesSystem.h"

USING_NS_CC;

ParticlesSystem::ParticlesSystem(cocos2d::Scene* scene, entt::registry* registry)
	: m_scene(scene), m_registry(registry)
{
#if _DEBUG
	cocos2d::log("[ParticlesSystem] Constructor");
#endif

	m_signalsManager = ECS::SignalsManager::getInstance();

	m_signalsManager->connect<&ParticlesSystem::setLocalEntity>(Signals::NW_MY_ENTT, this);
	m_signalsManager->connect<&ParticlesSystem::AnimSpawn>(Signals::PARTICLES_ANIM_SPAWN, this);
	m_signalsManager->connect<&ParticlesSystem::AnimUnSpawn>(Signals::PARTICLES_ANIM_UNSPAWN, this);
}

ParticlesSystem::~ParticlesSystem()
{
#if _DEBUG
	cocos2d::log("[ParticlesSystem] Destructor");
#endif

	ECS::SignalsManager::getInstance()->disconnectAll(this);

	/*for (auto& it : m_animsRunning)
	{
		if (it.second)
		{
			if (it.second->getReferenceCount() > 0)
				it.second->release();

			if (it.second->getParent())
				it.second->getParent()->removeChild(it.second);
		}
	}*/
}

void ParticlesSystem::update(float dt)
{

}

void ParticlesSystem::setLocalEntity(entt::entity entity, SLNet::BitStream * bs)
{
	m_localEntt = entity;
}

void ParticlesSystem::AnimSpawn(entt::entity entity, SLNet::BitStream * bs)
{
	if (!m_registry->valid(m_localEntt))
		return;

	if (!bs)
	{
#if _DEBUG
		cocos2d::log("[ParticlesSystem] AnimSpawn() bs is nullptr.");
#endif
		return;
	}

	auto playerC = m_registry->try_get<PlayerComponent>(entity);

	if (!playerC)
	{
#if _DEBUG
		cocos2d::log("[ParticlesSystem] AnimSpawn() playerC is nullptr.");
#endif
		return;
	}

	ParticleAnims animTag;
	bs->Read(animTag);

	if (!animTag)
		return;

	std::string fileName;
	ParticleSystemQuad* emitter = nullptr;
	Texture2D* texture;

	switch (animTag)
	{
	case ParticleAnims::ExplodingRing:
		fileName = "Particles/ExplodingRing.plist";
		emitter = ParticleSystemQuad::create(fileName);
		emitter->setPositionType(ParticleSystem::PositionType::RELATIVE);
		break;
	case ParticleAnims::MeditationFlowers:
		emitter = ParticleFlower::create();
		texture = Director::getInstance()->getTextureCache()->addImage("stars.png");
		emitter->setTexture(texture);
		emitter->setPosition(Vec2::ZERO);
		m_meditations.emplace(entity, emitter);
		emitter->setPositionType(ParticleSystem::PositionType::FREE);
		break;
	default:
		return;
	}

	emitter->setCameraMask(static_cast<int>(CameraFlag::USER1));
	emitter->setTag(animTag);
	emitter->setPositionX(emitter->getPositionX() + playerC->_spriteBody->getContentSize().width / 2.0f);
	emitter->setPositionY(emitter->getPositionY() + playerC->_spriteBody->getContentSize().height / 2.0f);
	emitter->setAutoRemoveOnFinish(true);

	playerC->_spriteBody->addChild(emitter, 11);
}

void ParticlesSystem::AnimUnSpawn(entt::entity entity, SLNet::BitStream * bs)
{
	if (m_meditations.find(entity) != m_meditations.end())
	{
		m_meditations.at(entity)->setDuration(0.01f);
		m_meditations.erase(entity);
	}
}
