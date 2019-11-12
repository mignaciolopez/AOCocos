#ifndef __AUDIO_COMPONENT_H__
#define __AUDIO_COMPONENT_H__

#include "ECS/Components/Component.h"

#include "cocos2d.h"

class AudioComponent : public ECS::Component
{
public:
	AudioComponent()
	{
		cocos2d::log("%s Constructor", "[AUDIO COMPONENT]");

		m_prevMusic = 0;
		m_music = 1;
	}
	~AudioComponent()
	{

		cocos2d::log("%s Destructor", "[AUDIO COMPONENT]");
	}

	virtual ComponentType getType() override
	{
		return m_type;
	}

	virtual int getMusic() override
	{
		return m_music;
	}
	virtual void setMusic(int musicID) override
	{
		m_music = musicID;
	}
	virtual int getPrevMusic() override
	{
		return m_prevMusic;
	}
	virtual void setPrevMusic(int musicID) override
	{
		m_prevMusic = musicID;
	}

	virtual void addAudio(int audioID) override
	{
		m_audios.emplace(audioID, audioID);
	}

	virtual void removeAudio(int audioID) override
	{
		m_audios.erase(audioID);
	}

	virtual std::map<int, int>* getAudios() override
	{
		return &m_audios;
	}

private:
	const ComponentType m_type = ComponentType::AUDIO;

	int m_music;
	int m_prevMusic;
	std::map<int, int> m_audios;

};
#endif // !__AUDIO_COMPONENT_H__
