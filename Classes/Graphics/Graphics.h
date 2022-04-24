#ifndef GRAPHICS_H__
#define GRAPHICS_H__

#include "cocos2d.h"
#include "..\Components\Enums.h"

#include "json/document.h"
#include "json/writer.h"
#include "json/stringbuffer.h"

struct jsonFrame
{
	uint32_t _id = 0;
	std::string _resource = "";
	uint16_t _rect[4] = { 0, 0, 0, 0 };
	float _tilesWidth = 0.0f;
	float _tilesHeight = 0.0f;
};

struct jsonAnimation
{
	uint32_t _id = 0;
	uint32_t _item = 0;
	uint32_t _rawAnimationId = 0;
	std::string _resource = "";
	uint16_t _rect[4] = { 0, 0, 0, 0 };
	std::vector<uint32_t> _frames;
	float _speed = 0.0f;
	float _tilesWidth = 0.0f;
	float _tilesHeight = 0.0f;
	float _offset[2] = { 0, 0 };

	//info extra not in jason file
	Directions _dir;
};

struct jsonBodyStanding
{
	uint32_t _id;
	Bodies _body;
	Directions _dir;
	uint32_t _rect[4];
};

struct jsonHead
{
	uint32_t _id;
	Heads _head;
	Directions _dir;
	uint32_t _rect[4];
};

struct jsonItem
{
	uint32_t _id;
	uint32_t _frameid;
	Items _item;
	std::string _displayName;
	std::string _affectedComponent;
	float _value;
};

class Graphics
{
public:
	Graphics();
	~Graphics();

	static Graphics* getInstance();
	static void destroyInstance();

	jsonFrame* getFrame(uint32_t id);
	std::vector<jsonBodyStanding*> getBodyStanding(Bodies id);
	std::vector<jsonAnimation*> getBodyAnimationsFrames(Bodies id);
	jsonAnimation* getAnimationsFrames(Animations id);
	std::vector<jsonHead*> getHeads(Heads id);
	cocos2d::Animate* getccAnimation(Animations id);
	cocos2d::Sprite* getItemSprite(Items id);
	jsonItem* getItemJson(Items id);


	void loadFrames();
	void loadBodyStanding(std::string line);
	void loadJsonHead(std::string line);
	void loadAnimations();
	void loadTextures();
	void loadJsonItems();
	
private:
	std::map<uint32_t, jsonFrame*> m_frames;

	using jsonBodyStandingMM = std::multimap<Bodies, jsonBodyStanding*>;
	jsonBodyStandingMM m_bodiesStanding;

	using jsonAnimationBodyMM = std::multimap<Bodies, jsonAnimation*>;
	jsonAnimationBodyMM m_animationsBodies;

	std::map<Animations, jsonAnimation*> m_animations;

	using jsonHeadMM = std::multimap<Heads, jsonHead*>;
	jsonHeadMM m_heads;

	std::map<Animations, cocos2d::Animate*> m_ccAnimations;

	std::map<Items, jsonItem*> m_items;
};

#endif // !GRAPHICS_H__