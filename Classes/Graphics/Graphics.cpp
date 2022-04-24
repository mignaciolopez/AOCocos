#include "Graphics.h"

USING_NS_CC;

Graphics::Graphics()
{
#if _DEBUG
	cocos2d::log("[Graphics] Constructor");
#endif

	loadFrames();
	loadTextures();
	loadAnimations();
	loadJsonItems();
}

Graphics::~Graphics()
{
#if _DEBUG
	cocos2d::log("[Graphics] Destructor");
#endif

	for (auto& it : m_frames)
	{
		if (it.second)
		{
			delete it.second;
			it.second = nullptr;
		}
	}

	for (auto& it : m_bodiesStanding)
	{
		if (it.second)
		{
			delete it.second;
			it.second = nullptr;
		}
	}

	for (auto& it : m_animationsBodies)
	{
		if (it.second)
		{
			delete it.second;
			it.second = nullptr;
		}
	}

	for (auto& it : m_animations)
	{
		if (it.second)
		{
			delete it.second;
			it.second = nullptr;
		}
	}

	for (auto& it : m_heads)
	{
		if (it.second)
		{
			delete it.second;
			it.second = nullptr;
		}
	}

	for (auto& it : m_items)
	{
		if (it.second)
		{
			delete it.second;
			it.second = nullptr;
		}
	}

	for (auto& it : m_ccAnimations)
	{
		if (it.second)
		{
			if (it.second->getReferenceCount() > 0)
				it.second->release();
		}
	}
}

static Graphics* s_graphics = nullptr;

Graphics* Graphics::getInstance()
{
	if (!s_graphics)
	{
		s_graphics = new (std::nothrow) Graphics;
	}

	return s_graphics;
}

void Graphics::destroyInstance()
{
	if (s_graphics)
	{
		delete s_graphics;
		s_graphics = nullptr;
	}
}

jsonFrame * Graphics::getFrame(uint32_t id)
{
	return m_frames.at(id);
}

std::vector<jsonBodyStanding*> Graphics::getBodyStanding(Bodies id)
{
	std::vector<jsonBodyStanding*> bodies;

	typedef jsonBodyStandingMM::iterator MMIT;
	std::pair<MMIT, MMIT> result = m_bodiesStanding.equal_range(id);
	int count = std::distance(result.first, result.second);

#if _DEBUG
	cocos2d::log("[Graphics] getBodyStanding() Body: %i result: %i", id, count);
#endif

	for (MMIT it = result.first; it != result.second; it++)
	{
		bodies.push_back(it->second);
	}

	return bodies;
}

std::vector<jsonAnimation*> Graphics::getBodyAnimationsFrames(Bodies id)
{
	std::vector<jsonAnimation*> animationFrames;

	typedef jsonAnimationBodyMM::iterator MMIT;
	std::pair<MMIT, MMIT> result = m_animationsBodies.equal_range(id);
	int count = std::distance(result.first, result.second);

#if _DEBUG
	cocos2d::log("[Graphics] getBodyAnimationsFrames() Body: %i result: %i", id, count);
#endif

	for (MMIT it = result.first; it != result.second; it++)
	{
		animationFrames.push_back(it->second);
	}

	return animationFrames;
}

jsonAnimation* Graphics::getAnimationsFrames(Animations id)
{
	if (m_animations.find(id) != m_animations.end())
		return m_animations.at(id);

	return nullptr;
}

std::vector<jsonHead*> Graphics::getHeads(Heads id)
{
	std::vector<jsonHead*> heads;

	typedef jsonHeadMM::iterator MMIT;
	std::pair<MMIT, MMIT> result = m_heads.equal_range(id);
	int count = std::distance(result.first, result.second);

#if _DEBUG
	cocos2d::log("[Graphics] getHeads() Head: %i result: %i", id, count);
#endif

	for (MMIT it = result.first; it != result.second; it++)
	{
		heads.push_back(it->second);
	}

	return heads;
}

cocos2d::Animate * Graphics::getccAnimation(Animations id)
{
	if (m_ccAnimations.find(id) != m_ccAnimations.end())
		return m_ccAnimations.at(id);

	return nullptr;
}

cocos2d::Sprite * Graphics::getItemSprite(Items id)
{
	auto cache = SpriteFrameCache::getInstance();

	if (m_items.find(id) != m_items.end())
	{
		auto frame = m_frames.at(m_items.at(id)->_frameid);

		if (frame)
		{
			std::string name = std::to_string(frame->_id);
			auto sprite = Sprite::createWithSpriteFrame(cache->getSpriteFrameByName(name));

			return sprite;
		}
	}

	return nullptr;
}

jsonItem * Graphics::getItemJson(Items id)
{
	if (m_items.find(id) != m_items.end())
		return m_items.at(id);

	return nullptr;
}

void Graphics::loadFrames()
{
	auto fileUtils = FileUtils::getInstance();

	std::string framesBodiesPath = fileUtils->fullPathForFilename("frames.json");
	auto framesBodiesJason = fileUtils->getStringFromFile(framesBodiesPath);
	cocos2d::log("[GraphicsSystem] File: %s", framesBodiesPath.c_str());

	std::stringstream ss(framesBodiesJason);
	std::string line;

	while (std::getline(ss, line))
	{
		if (line == "")
		{
			cocos2d::log("[GraphicsSystem] loadFrames() line was empty");
			continue;
		}

		rapidjson::Document d;
		if (d.Parse(line.c_str()).HasParseError())
		{
			cocos2d::log("[GraphicsSystem] loadFrames() Error parsing line: %s", line.c_str());
			continue;
		}

		if (d.HasMember("frames")) //its an animation
		{
			jsonAnimation* jsonAnim = new (std::nothrow) jsonAnimation;
			if (!jsonAnim)
			{
				cocos2d::MessageBox("Error allocation memory for jsonAnim", "[GraphicsSystem]");
				exit(-3);
			}

			jsonAnim->_id = d["id"].GetUint();
			jsonAnim->_item = d["item"].GetUint();

			const rapidjson::Value& frames = d["frames"];
			for (rapidjson::SizeType i = 0; i < frames.Size(); i++)
				jsonAnim->_frames.push_back(frames[i].GetUint());

			const rapidjson::Value& rect = d["rect"];
			for (rapidjson::SizeType i = 0; i < rect.Size(); i++)
				jsonAnim->_rect[i] = rect[i].GetUint();

			jsonAnim->_speed = d["speed"].GetFloat();
			jsonAnim->_speed = (jsonAnim->_speed / 1900.0f) / jsonAnim->_frames.size();
			jsonAnim->_tilesWidth = d["tilesWidth"].GetFloat();
			jsonAnim->_tilesHeight = d["tilesHeight"].GetFloat();

			if (d.HasMember("animations"))
			{
				jsonAnim->_rawAnimationId = d["animations"].GetInt();
				Animations animid = static_cast<Animations>(jsonAnim->_rawAnimationId);

				const rapidjson::Value& offset = d["offset"];
				for (rapidjson::SizeType i = 0; i < offset.Size(); i++)
					jsonAnim->_offset[i] = offset[i].GetFloat();

				if (m_animations.find(animid) == m_animations.end())
					m_animations.emplace(animid, jsonAnim);
				else
				{
					delete jsonAnim;
					jsonAnim = nullptr;
				}
			}
			else if (d.HasMember("bodies"))
			{
				jsonAnim->_rawAnimationId = d["bodies"].GetInt();

				Bodies body = static_cast<Bodies>(jsonAnim->_rawAnimationId);

				typedef jsonAnimationBodyMM::iterator MMITAnim;
				std::pair<MMITAnim, MMITAnim> rAnim = m_animationsBodies.equal_range(body);
				int count = std::distance(rAnim.first, rAnim.second); // count should be 4

				switch (jsonAnim->_rect[1])
				{
					//for tall bodies
				case 0: //south
					jsonAnim->_dir = Directions::South;
					break;
				case 45: //north
					jsonAnim->_dir = Directions::North;
					break;
				case 90: //west
					jsonAnim->_dir = Directions::West;
					break;
				case 135: //east
					jsonAnim->_dir = Directions::East;
					break;

					//for casper bodie

				case 32: //north
					jsonAnim->_dir = Directions::North;
					break;
				case 64: //west
					jsonAnim->_dir = Directions::West;
					break;
				case 96: //east
					jsonAnim->_dir = Directions::East;
					break;
				}

				if (count < 4)
					m_animationsBodies.emplace(body, jsonAnim);
				else
				{
					delete jsonAnim;
					jsonAnim = nullptr;
				}
			}
		}
		else
		{
			jsonFrame* frame = new (std::nothrow) jsonFrame;
			if (!frame)
			{
				cocos2d::MessageBox("Error allocation memory for frame", "[GraphicsSystem]");
				exit(-3);
			}

			frame->_id = d["id"].GetUint();
			frame->_resource = d["resource"].GetString();

			const rapidjson::Value& rect = d["rect"];
			for (rapidjson::SizeType i = 0; i < rect.Size(); i++)
				frame->_rect[i] = rect[i].GetUint();

			frame->_tilesWidth = d["tilesWidth"].GetFloat();
			frame->_tilesHeight = d["tilesHeight"].GetFloat();

			if (m_frames.find(frame->_id) == m_frames.end())
				m_frames.emplace(frame->_id, frame);
			else
			{
				delete frame;
				frame = nullptr;
			}

			if (d.HasMember("bodies"))
			{
				loadBodyStanding(line);
			}
			else if (d.HasMember("heads"))
			{
				loadJsonHead(line);
			}
		}
	}

	cocos2d::log("[GraphicsSystem] Frames: %d", m_frames.size());
	cocos2d::log("[GraphicsSystem] Bodies Standing %f", m_bodiesStanding.size() / 4.0f);
	cocos2d::log("[GraphicsSystem] Body Animations: %f", m_animationsBodies.size() / 4.0f);
	cocos2d::log("[GraphicsSystem] Animations: %d", m_animations.size());
	cocos2d::log("[GraphicsSystem] Heads: %f", m_heads.size() / 4.0f);
}

void Graphics::loadTextures()
{
	auto fileUtils = FileUtils::getInstance();
	auto sfc = SpriteFrameCache::getInstance();

	for (auto& frame : m_frames)
	{
		std::string path = fileUtils->fullPathForFilename(frame.second->_resource);
		auto sprFrame = SpriteFrame::create(path,
			Rect(frame.second->_rect[0], frame.second->_rect[1], frame.second->_rect[2], frame.second->_rect[3]),
			false, Vec2::ZERO,
			Size(frame.second->_rect[2], frame.second->_rect[3]));

		sfc->addSpriteFrame(sprFrame, std::to_string(frame.second->_id));

		/*cocos2d::log("[GraphicsSystem] id: %i", frame.second->_id);
		cocos2d::log("[GraphicsSystem] startX: %i", frame.second->_rect[0]);
		cocos2d::log("[GraphicsSystem] startY: %i", frame.second->_rect[1]);
		cocos2d::log("[GraphicsSystem] width: %i", frame.second->_rect[2]);
		cocos2d::log("[GraphicsSystem] height: %i", frame.second->_rect[3]);*/
	}
}

void Graphics::loadJsonItems()
{
	auto fileUtils = FileUtils::getInstance();

	std::string framesBodiesPath = fileUtils->fullPathForFilename("items.json");
	auto framesBodiesJason = fileUtils->getStringFromFile(framesBodiesPath);
	cocos2d::log("[GraphicsSystem] File: %s", framesBodiesPath.c_str());

	std::stringstream ss(framesBodiesJason);
	std::string line;

	while (std::getline(ss, line))
	{
		if (line == "")
		{
			cocos2d::log("[GraphicsSystem] loadJsonItems() line was empty");
			continue;
		}

		rapidjson::Document d;
		if (d.Parse(line.c_str()).HasParseError())
		{
			cocos2d::log("[GraphicsSystem] loadJsonItems() Error parsing line: %s", line.c_str());
			continue;
		}

		jsonItem* item = new (std::nothrow) jsonItem;
		if (!item)
		{
			cocos2d::MessageBox("Error allocation memory for item", "[GraphicsSystem]");
			exit(-3);
		}

		item->_id = d["id"].GetUint();
		item->_frameid = d["itemframe"].GetUint();
		item->_item = static_cast<Items>(item->_id);
		//check local and load corresponding just english for now
		item->_displayName = d["english"].GetString();
		item->_affectedComponent = d["affectedC"].GetString();
		item->_value = d["value"].GetFloat();

		if (m_items.find(item->_item) == m_items.end())
			m_items.emplace(item->_item, item);
		else
		{
			cocos2d::log("[GraphicsSystem] loadJsonItems() Error delete were called for this: %s", line.c_str());
			delete item;
			item = nullptr;
		}
	}
}

void Graphics::loadBodyStanding(std::string line)
{
	if (line == "")
	{
		cocos2d::log("[GraphicsSystem] loadBodiesStanding() line was empty");
		return;
	}

	rapidjson::Document d;
	if (d.Parse(line.c_str()).HasParseError())
	{
		cocos2d::log("[GraphicsSystem] loadBodiesStanding() Error parsing line: %s", line.c_str());
		return;
	}

	jsonBodyStanding* bodyStanding = new (std::nothrow) jsonBodyStanding;
	if (!bodyStanding)
	{
		cocos2d::MessageBox("Error allocation memory for bodyStanding", "[GraphicsSystem]");
		exit(-3);
	}

	bodyStanding->_id = d["id"].GetUint();
	bodyStanding->_body = static_cast<Bodies>(d["bodies"].GetInt());

	const rapidjson::Value& rect = d["rect"];

	for (rapidjson::SizeType i = 0; i < rect.Size(); i++)
		bodyStanding->_rect[i] = rect[i].GetUint();

	if (bodyStanding->_rect[0] == 0)
	{
		switch (bodyStanding->_rect[1])
		{
			//for tall bodies
		case 45:	//North
			bodyStanding->_dir = Directions::North;
			break;
		case 135:	//East
			bodyStanding->_dir = Directions::East;
			break;
		case 0:		//South
			bodyStanding->_dir = Directions::South;
			break;
		case 90:	//West
			bodyStanding->_dir = Directions::West;
			break;

			//for short bodies
		case 32:	//North
			bodyStanding->_dir = Directions::North;
			break;
		case 96:	//East
			bodyStanding->_dir = Directions::East;
			break;
		case 64:	//West
			bodyStanding->_dir = Directions::West;
			break;

		default:
			delete bodyStanding;
			bodyStanding = nullptr;
			return;
		}


		typedef jsonBodyStandingMM::iterator MMITStanding;
		std::pair<MMITStanding, MMITStanding> rStanding = m_bodiesStanding.equal_range(bodyStanding->_body);
		int count = std::distance(rStanding.first, rStanding.second);

		if (count < 4)
			m_bodiesStanding.emplace(bodyStanding->_body, bodyStanding);
		else
		{
			cocos2d::log("[GraphicsSystem] loadBodiesStanding() Error delete were called for this: %s", line.c_str());
			delete bodyStanding;
			bodyStanding = nullptr;
		}
	}
	else
	{
		delete bodyStanding;
		bodyStanding = nullptr;
	}
}

void Graphics::loadJsonHead(std::string line)
{
	if (line == "")
	{
		cocos2d::log("[GraphicsSystem] loadHead() line was empty");
		return;
	}

	rapidjson::Document d;
	if (d.Parse(line.c_str()).HasParseError())
	{
		cocos2d::log("[GraphicsSystem] loadHead() Error parsing line: %s", line.c_str());
		return;
	}

	jsonHead* head = new (std::nothrow) jsonHead;
	if (!head)
	{
		cocos2d::MessageBox("loadHead() Error allocation memory for head", "[GraphicsSystem]");
		exit(-3);
	}

	head->_id = d["id"].GetUint();
	head->_head = static_cast<Heads>(d["heads"].GetInt());

	const rapidjson::Value& rect = d["rect"];

	for (rapidjson::SizeType i = 0; i < rect.Size(); i++)
		head->_rect[i] = rect[i].GetUint();

	switch (head->_rect[0])
	{
	case 51:	//North
		head->_dir = Directions::North;
		break;
	case 17:	//East
		head->_dir = Directions::East;
		break;
	case 0:		//South
		head->_dir = Directions::South;
		break;
	case 34:	//West
		head->_dir = Directions::West;
		break;
	default:
		cocos2d::log("[GraphicsSystem] loadHead() Error delete were called for this: %s", line.c_str());
		delete head;
		head = nullptr;
		return;
	}


	typedef jsonHeadMM::iterator MMITHead;
	std::pair<MMITHead, MMITHead> rHead = m_heads.equal_range(head->_head);
	int count = std::distance(rHead.first, rHead.second);

	if (count < 4)
		m_heads.emplace(head->_head, head);
	else
	{
		cocos2d::log("[GraphicsSystem] loadHead() Error delete were called for this: %s", line.c_str());
		delete head;
		head = nullptr;
	}
}

void Graphics::loadAnimations()
{
	auto cache = SpriteFrameCache::getInstance();

	for (auto& it : m_animations)
	{
		Vector<SpriteFrame*> spriteFrames;
		for (auto& frame : it.second->_frames)
		{
			spriteFrames.pushBack(cache->getSpriteFrameByName(std::to_string(frame)));
		}
		Animation* animation = Animation::createWithSpriteFrames(spriteFrames, it.second->_speed);

		if (animation)
		{
			auto animate = Animate::create(animation);
			if (animate)
			{
				animate->retain();
				m_ccAnimations.emplace(static_cast<Animations>(it.second->_rawAnimationId), animate);
			}
		}
	}
}