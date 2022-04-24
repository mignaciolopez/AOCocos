#include "AudioSystem.h"

USING_NS_CC;
#define USE_AUDIO_ENGINE 1
// #define USE_SIMPLE_AUDIO_ENGINE 1

#if USE_AUDIO_ENGINE && USE_SIMPLE_AUDIO_ENGINE
#error "Don't use AudioEngine and SimpleAudioEngine at the same time. Please just select one in your game!"
#endif

#if USE_AUDIO_ENGINE
#include "audio/include/AudioEngine.h"
using namespace cocos2d::experimental;
#elif USE_SIMPLE_AUDIO_ENGINE
#include "audio/include/SimpleAudioEngine.h"
using namespace CocosDenshion;
#endif

AudioSystem::AudioSystem(entt::registry* registry) : m_registry(registry)
{
#if _DEBUG
	cocos2d::log("[AudioSystem] Constructor");
#endif

#if USE_AUDIO_ENGINE
	AudioEngine::lazyInit();
#elif USE_SIMPLE_AUDIO_ENGINE
	SimpleAudioEngine::end();
#endif

	m_localEntt = entt::null;
	m_trackAEID = -1;

	m_fUtils = FileUtils::getInstance();

	m_signalsManager = ECS::SignalsManager::getInstance();

	m_registry->on_replace<FXComponent>().connect<&AudioSystem::onUpdateFXC>(this);

	m_signalsManager->connect<&AudioSystem::setLocalEntity>(Signals::NW_MY_ENTT, this);

	m_signalsManager->connect<&AudioSystem::appDidEnterBG>(Signals::APP_DID_ENTER_BG, this);
	m_signalsManager->connect<&AudioSystem::apWillEnterFG>(Signals::APP_WILL_ENTER_FG, this);

	m_signalsManager->connect<&AudioSystem::toggleFX>(Signals::AUDIO_TOGGLE_FX, this);
	m_signalsManager->connect<&AudioSystem::toggleMusic>(Signals::AUDIO_TOGGLE_MUSIC, this);

	m_signalsManager->connect<&AudioSystem::setMusicTrack>(Signals::AUDIO_SET_MUSIC_TRACK, this);

	m_musicOn = false;
	m_FXOn = true;
}

AudioSystem::~AudioSystem()
{
#if _DEBUG
	cocos2d::log("[AudioSystem] Destructor");
#endif

#if USE_AUDIO_ENGINE
	//AudioEngine::stopAll();
	//AudioEngine::uncacheAll();
	//AudioEngine::end();
#elif USE_SIMPLE_AUDIO_ENGINE
	SimpleAudioEngine::end();
#endif

	m_registry->on_replace<FXComponent>().disconnect<&AudioSystem::onUpdateFXC>(this);

	ECS::SignalsManager::getInstance()->disconnectAll(this);

	auto view = m_registry->view<FXComponent>();

	view.each([=](entt::entity entity, FXComponent& fxC)
	{
		fxC._FXs.clear();
		m_registry->remove<FXComponent>(entity);
	});

	m_fUtils = nullptr;
	m_registry = nullptr;
	m_signalsManager = nullptr;
	m_localEntt = entt::null;
}

void AudioSystem::update(float dt)
{
	//auto view = m_registry->view<FXComponent>();

	for (auto& e : m_entitiesToUpdate)
	{
		auto fxC = m_registry->try_get<FXComponent>(e.first);

		for (auto& fxID : fxC->_FXs) //m_FXs is std::vector<int> _FXs;
		{
			playFX(fxID);
		}
		fxC->_FXs.clear();
	}

	m_entitiesToUpdate.clear();
}

void AudioSystem::onUpdateFXC(entt::registry & registry, entt::entity entity)
{
	if (m_entitiesToUpdate.find(entity) == m_entitiesToUpdate.end())
		m_entitiesToUpdate.emplace(entity, entity);
	
	/*auto fxC = m_registry->try_get<FXComponent>(entity);

	for (auto& fxID : fxC->_FXs) //m_FXs is std::vector<int> _FXs;
	{
		playFX(fxID);
	}
	fxC->_FXs.clear();*/
}

void AudioSystem::setLocalEntity(entt::entity entity, SLNet::BitStream* bs)
{
	m_localEntt = entity;
}

void AudioSystem::appDidEnterBG(entt::entity entity,  SLNet::BitStream* bs)
{
#if USE_AUDIO_ENGINE
	AudioEngine::pauseAll();
#elif USE_SIMPLE_AUDIO_ENGINE
	SimpleAudioEngine::getInstance()->pauseBackgroundMusic();
	SimpleAudioEngine::getInstance()->pauseAllEffects();
#endif
}

void AudioSystem::apWillEnterFG(entt::entity entity,  SLNet::BitStream* bs)
{
#if USE_AUDIO_ENGINE
	AudioEngine::resumeAll();
#elif USE_SIMPLE_AUDIO_ENGINE
	SimpleAudioEngine::getInstance()->resumeBackgroundMusic();
	SimpleAudioEngine::getInstance()->resumeAllEffects();
#endif
}

void AudioSystem::toggleFX(entt::entity entity,  SLNet::BitStream* bs)
{
	m_FXOn = !m_FXOn;
	/*auto view = m_registry->view<FXComponent>();

	view.each([=](entt::entity entity, FXComponent& fxC)
	{
		fxC._FXOn = m_FXOn;
	});*/

	if (!m_FXOn)
	{
		m_registry->clear<FXComponent>();
		m_entitiesToUpdate.clear();
	}
	else
	{
		auto view = m_registry->view<PlayerComponent>();

		view.each([=](entt::entity entity, PlayerComponent& playerC)
		{
			m_registry->assign<FXComponent>(entity, true);
		});
	}
}

void AudioSystem::toggleMusic(entt::entity entity,  SLNet::BitStream* bs)
{
	m_musicOn = !m_musicOn;

	if (!m_musicOn)
		AudioEngine::stop(m_trackAEID);
	else
		playMusic(m_track);
}

void AudioSystem::setMusicTrack(entt::entity entity,  SLNet::BitStream* bs)
{
	if (!bs)
		return;

	TRACKS track;
	bs->Read(track);
	playMusic(track);
	m_trackAEID = track;
}

void AudioSystem::playFX(FXS fx)
{
	if (!m_FXOn)
		return;

	std::string path = std::to_string(fx) + ".ogg";
	path = m_fUtils->fullPathForFilename(path);
	AudioEngine::play2d(path, false);
}

void AudioSystem::playMusic(TRACKS track)
{
	if (!m_musicOn)
		return;

	std::string path = std::to_string(track) + ".mp3";
	path = m_fUtils->fullPathForFilename(path);
	m_trackAEID = AudioEngine::play2d(path, true);
}
