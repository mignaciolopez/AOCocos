#ifndef AUDIO_SYSTEM_H__
#define AUDIO_SYSTEM_H__

#include "BitStream.h"
#include "cocos2d.h"

#include "entt.hpp"

#include "ECS/iSystems/iSystem.h"

#include "ECS/SignalsManager.h"

class AudioSystem : public ECS::iSystem
{
public:
	const ECS::iSystemTags _tag = ECS::iSystemTags::AudioSystem_tag;
	AudioSystem(entt::registry* registry);
	~AudioSystem();

	virtual void update(float dt) override;

	void onUpdateFXC(entt::registry& registry, entt::entity entity);
	
	void setLocalEntity(entt::entity entity, SLNet::BitStream* bs);

	void appDidEnterBG(entt::entity entity, SLNet::BitStream* bs);
	void apWillEnterFG(entt::entity entity, SLNet::BitStream* bs);

	void toggleFX(entt::entity entity, SLNet::BitStream* bs);
	void toggleMusic(entt::entity entity, SLNet::BitStream* bs);

	void setMusicTrack(entt::entity entity, SLNet::BitStream* bs);

private:
	void playFX(FXS fx);
	void playMusic(TRACKS track);

private:
	cocos2d::FileUtils* m_fUtils;

	entt::registry* m_registry;

	ECS::SignalsManager* m_signalsManager;

	entt::entity m_localEntt = entt::null;

	std::map<entt::entity, entt::entity> m_entitiesToUpdate;

	bool m_musicOn;
	bool m_FXOn;

	int m_trackAEID;
	TRACKS m_track;
};

#endif // !AUDIO_SYSTEM_H__