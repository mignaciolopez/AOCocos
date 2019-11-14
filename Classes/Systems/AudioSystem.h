#ifndef __AUDIO_SYSTEM_H__
#define __AUDIO_SYSTEM_H__

#include "ECS/ECS_Engine.h"

#include "cocos2d.h"
#include "audio/include/AudioEngine.h"
#include "audio/include/SimpleAudioEngine.h"

class AudioSystem : public ECS::System
{
public:
	AudioSystem();
	~AudioSystem();

	virtual void Update() override;
	
	void setLocaleid(int eid, cocos2d::Event* ccevnt, SLNet::BitStream* bs);
	void createComponent(int eid, cocos2d::Event* ccevnt, SLNet::BitStream* bs);
	void removeComponent(int eid, cocos2d::Event* ccevnt, SLNet::BitStream* bs);
	void musicToggle(int eid, cocos2d::Event* ccevnt, SLNet::BitStream* bs);

private:
	void preloadSounds();
	void preloadMusic();

	void playSound(int i);
	void playMusic(int id);
	void stopMusic(int aeid);

private:
	ECS::EntityManager* m_entityManager;
	ECS::EventManager* m_eventManager;

	const int m_wavCount = 199;
	const int m_mp3Count = 52;

	int m_localeid;
	CocosDenshion::SimpleAudioEngine* m_SAE;

	bool m_musicOn;
};

#endif // __AUDIO_SYSTEM_H__