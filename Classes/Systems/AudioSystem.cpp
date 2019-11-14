#include "AudioSystem.h"

USING_NS_CC;
using namespace CocosDenshion;

AudioSystem::AudioSystem()
{
	cocos2d::log("[AUDIO SYSTEM] Constructor");

	m_localeid = -1;

	m_SAE = SimpleAudioEngine::getInstance();

	if (!experimental::AudioEngine::lazyInit())
		cocos2d::log("[AUDIO SYSTEM] experimental::AudioEngine::lazyInit() Failed!");

	m_entityManager = ECS::ECS_Engine::getInstance()->getEntityManager();
	m_eventManager = ECS::ECS_Engine::getInstance()->getEventManager();

	m_eventManager->Subscribe(EVENTS::MY_EID, &AudioSystem::setLocaleid, this);
	m_eventManager->Subscribe(EVENTS::AUDIO_C_CREATE, &AudioSystem::createComponent, this);
	m_eventManager->Subscribe(EVENTS::AUDIO_C_REMOVE, &AudioSystem::removeComponent, this);
	m_eventManager->Subscribe(EVENTS::AUDIO_MUSIC_TOGGLE, &AudioSystem::musicToggle, this);

	m_musicOn = false;

	preloadSounds();
	//preloadMusic();
}

AudioSystem::~AudioSystem()
{
	experimental::AudioEngine::uncacheAll();
	experimental::AudioEngine::end();

	if (m_entityManager)
	{
		for (auto e : *m_entityManager->getEntities())
		{
			m_entityManager->removeComponent(e.first, AUDIO);
		}
	}

	if (m_SAE)
	{
		m_SAE->end();
		m_SAE = nullptr;
	}

	cocos2d::log("[AUDIO SYSTEM] Destructor");
}

void AudioSystem::Update()
{
	if (m_localeid == -1)
		return;

	for (auto e : *m_entityManager->getEntities())
	{
		if (!m_entityManager->getComp(e.first, AUDIO))
			continue;

		if (m_entityManager->getComp(e.first, AUDIO)->getAudios()->size() < 1)
			continue;

		for (auto a : *m_entityManager->getComp(e.first, AUDIO)->getAudios())
		{
			playSound(a.first);
			m_entityManager->getComp(e.first, AUDIO)->removeAudio(a.first);
			break;
		}
	}

	if (!m_entityManager->getComp(m_localeid, AUDIO))
		return;

	if (m_entityManager->getComp(m_localeid, AUDIO)->getMusic() !=
		m_entityManager->getComp(m_localeid, AUDIO)->getPrevMusic())
	{
		stopMusic(m_entityManager->getComp(m_localeid, AUDIO)->getAeid());
		playMusic(m_entityManager->getComp(m_localeid, AUDIO)->getMusic());
	}
}

void AudioSystem::setLocaleid(int eid, cocos2d::Event * ccevnt, SLNet::BitStream * bs)
{
	m_localeid = eid;
}

void AudioSystem::createComponent(int eid, cocos2d::Event * ccevnt, SLNet::BitStream * bs)
{
	AudioComponent* ac = new (std::nothrow) AudioComponent;

	m_entityManager->AddComponentToEntity(eid, ac);
	ac->addAudio(3);
}

void AudioSystem::removeComponent(int eid, cocos2d::Event * ccevnt, SLNet::BitStream * bs)
{
	m_entityManager->removeComponent(eid, AUDIO);
}

void AudioSystem::musicToggle(int eid, cocos2d::Event * ccevnt, SLNet::BitStream * bs)
{
	if (m_musicOn)
		stopMusic(m_entityManager->getComp(eid, AUDIO)->getAeid());
	else
		playMusic(m_entityManager->getComp(eid, AUDIO)->getAeid());
}

void AudioSystem::preloadSounds()
{
	for (int i = 1; i <= m_wavCount; i++)
	{
		std::string path = "wav/" + std::to_string(i) + ".wav";
		m_SAE->preloadEffect(path.c_str());
	}
}

void AudioSystem::preloadMusic()
{
	for (int i = 1; i <= m_mp3Count; i++)
	{
		std::string path = "mp3/" + std::to_string(i) + ".mp3";
		m_SAE->preloadBackgroundMusic(path.c_str());
	}
}

void AudioSystem::playSound(int i)
{
	std::string path = "wav/" + std::to_string(i) + ".wav";
	m_SAE->playEffect(path.c_str());
}

void AudioSystem::playMusic(int id)
{
	int aeid = -1;
	std::string path = "mp3/" + std::to_string(id) + ".mp3";
	aeid = experimental::AudioEngine::play2d(path.c_str(), true);
	experimental::AudioEngine::setVolume(aeid, 0.4f);
	m_musicOn = true;
	m_entityManager->getComp(m_localeid, AUDIO)->setAeid(aeid);
	m_entityManager->getComp(m_localeid, AUDIO)->setPrevMusic(id);
}

void AudioSystem::stopMusic(int aeid)
{
	experimental::AudioEngine::stop(aeid);
	m_musicOn = false;
}
