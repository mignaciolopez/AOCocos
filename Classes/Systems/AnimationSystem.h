#ifndef __ANIMATION_SYSTEM_H__
#define __ANIMATION_SYSTEM_H__

#include "ECS/ECS_Engine.h"

#include "cocos2d.h"

class AnimationSystem : public ECS::System
{
public:
	AnimationSystem();
	~AnimationSystem();

	virtual void Update() override;

	void animate(int eid, cocos2d::Event*, SLNet::BitStream* bs);
	void loadAnimationInfo(int eid, cocos2d::Event*, SLNet::BitStream* bs);
	void removeInfo(int eid, cocos2d::Event*, SLNet::BitStream* bs);

private:
	int newTag();

	void constructDirectionName(Direction dir);
	void constructBodyName(int eid);
	void constructHeadName(int eid);
	void constructAnimationName(int eid);

	void setBody(int eid);
	void setHead(int eid);

public:

private:
	ECS::EntityManager* m_entityManager;
	ECS::EventManager* m_eventManager;
	cocos2d::Director* m_director;
	cocos2d::SpriteFrameCache* m_sfCache;

	struct animationInfo
	{
		int tag;
		std::string animationName;

		std::string m_bodyNameNorth;
		std::string m_bodyNameEast;
		std::string m_bodyNameSouth;
		std::string m_bodyNameWest;

		std::string m_headNameNorth;
		std::string m_headNameEast;
		std::string m_headNameSouth;
		std::string m_headNameWest;
	};

	std::map<int, animationInfo*> m_animations;

	const float m_NS = 0.04f;
	const float m_EW = 0.05f;

	std::string m_dirName;
	std::string m_bodyName;
	std::string m_headName;

};

#endif //__ANIMATION_SYSTEM_H__