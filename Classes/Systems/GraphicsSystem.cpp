#include "GraphicsSystem.h"

USING_NS_CC;

GraphicsSystem::GraphicsSystem()
{
#if _DEBUG
	cocos2d::log("[GRAPHICS SYSTEM] Constructor");
#endif

	m_entityManager = ECS::ECS_Engine::getInstance()->getEntityManager();
	m_eventManager = ECS::ECS_Engine::getInstance()->getEventManager();

	m_fileUtils = FileUtils::getInstance();
	m_sfCache = SpriteFrameCache::getInstance();

	m_eventManager->Subscribe(EVENTS::MY_EID, &GraphicsSystem::setLocaleid, this);
	m_eventManager->Subscribe(EVENTS::GRAPHICS_LOAD_PLAYER, &GraphicsSystem::setGraphicsForPlayer, this);
	m_eventManager->Subscribe(EVENTS::GRAPHICS_LOAD_BODY, &GraphicsSystem::loadBody, this);
	m_eventManager->Subscribe(EVENTS::GRAPHICS_LOAD_HEAD, &GraphicsSystem::loadHead, this);
	m_eventManager->Subscribe(EVENTS::GRAPHICS_LOAD_SHIELD, &GraphicsSystem::loadShield, this);
	m_eventManager->Subscribe(EVENTS::GRAPHICS_LOAD_HELMET, &GraphicsSystem::loadHelmet, this);
	m_eventManager->Subscribe(EVENTS::GRAPHICS_LOAD_WEAPON, &GraphicsSystem::loadWeapon, this);

	m_localeid = -1;

	loadGraphicsIndex();
	loadTextures();
	loadAnimations();
}

GraphicsSystem::~GraphicsSystem()
{
	for (auto dat : m_graphicsData)
	{
		if (dat.second)
		{
			delete dat.second;
			dat.second = nullptr;
		}
	}

#if _DEBUG
	cocos2d::log("[GRAPHICS SYSTEM] Destructor");
#endif
}

void GraphicsSystem::update(float dt)
{
}

void GraphicsSystem::setLocaleid(int eid, cocos2d::Event * ccEvent, SLNet::BitStream * bs)
{
	m_localeid = eid;
}

void GraphicsSystem::setGraphicsForPlayer(int eid, cocos2d::Event * ccEvent, SLNet::BitStream * bs)
{
	loadBody(eid, nullptr, nullptr);
	loadHead(eid, nullptr, nullptr);
	loadShield(eid, nullptr, nullptr);
	loadHelmet(eid, nullptr, nullptr);
	loadWeapon(eid, nullptr, nullptr);

	//Blood Animation
	//265 tiene de la 260 a la 264
	Vector<SpriteFrame*> spriteFrames;
	for (auto f : m_graphicsData.at(265)->frames)
	{
		spriteFrames.pushBack(m_sfCache->getSpriteFrameByName(std::to_string(f)));
	}
	auto anim = Animate::create(Animation::createWithSpriteFrames(spriteFrames, 0.04f));

	anim->retain();
	m_entityManager->getComp(eid, ComponentType::PLAYER_BODY)->setAnimBlood(anim);

	//ApocalipsisAnimation
	//index 259
	spriteFrames.clear();
	for (auto f : m_graphicsData.at(259)->frames)
	{
		auto frame = m_sfCache->getSpriteFrameByName(std::to_string(f));
		frame->setAnchorPoint(Vec2(0.5f, 0.5f));
		spriteFrames.pushBack(frame);
	}
	anim = Animate::create(Animation::createWithSpriteFrames(spriteFrames, 0.04f));

	anim->retain();
	m_entityManager->getComp(eid, ComponentType::PLAYER_BODY)->setAnimApocaipsis(anim);
}

void GraphicsSystem::loadBody(int eid, cocos2d::Event * ccEvent, SLNet::BitStream * bs)
{
	if (bs)
	{
		Body body;
		bs->Read(body);
		m_entityManager->getComp(eid, ComponentType::PLAYER_BODY)->setBody(body);
	}

	auto bodySpr = m_entityManager->getComp(eid, ComponentType::PLAYER_BODY)->getBodySpr();
	int body = m_entityManager->getComp(eid, ComponentType::PLAYER_BODY)->getBody();
	typedef std::multimap<int, std::pair< unsigned int, Direction>>::iterator MMAPIterator;
	std::pair<MMAPIterator, MMAPIterator> resultBody = m_animationsBody.equal_range(body);
	//int countBodies = std::distance(resultBody.first, resultBody.second); // count should be 4

	for (MMAPIterator it = resultBody.first; it != resultBody.second; it++)
		m_entityManager->getComp(eid, ComponentType::PLAYER_BODY)->setBodyGs(it->second.second, it->second.first);

	Direction dir = m_entityManager->getComp(eid, ComponentType::PLAYER_BODY)->getDirection();
	bodySpr->setSpriteFrame(m_sfCache->getSpriteFrameByName(std::to_string(m_entityManager->getComp(eid, ComponentType::PLAYER_BODY)->getBodyGs(dir))));

	Vector<SpriteFrame*> spriteFrames;
	for (MMAPIterator it = resultBody.first; it != resultBody.second; it++)
	{
		for (auto f : m_graphicsData.at(it->second.first)->frames)
		{
			spriteFrames.pushBack(m_sfCache->getSpriteFrameByName(std::to_string(f)));
		}
		Animate* anim;

		if (it->second.second == Direction::North || it->second.second == Direction::South)
			anim = Animate::create(Animation::createWithSpriteFrames(spriteFrames, m_NS));
		else
			anim = Animate::create(Animation::createWithSpriteFrames(spriteFrames, m_EW));

		anim->retain();
		m_entityManager->getComp(eid, ComponentType::PLAYER_BODY)->setAnimBody(it->second.second, anim);
		spriteFrames.clear();
	}
}

void GraphicsSystem::loadHead(int eid, cocos2d::Event * ccEvent, SLNet::BitStream * bs)
{
	auto bodySpr = m_entityManager->getComp(eid, ComponentType::PLAYER_BODY)->getBodySpr();

	auto headSpr = m_entityManager->getComp(eid, ComponentType::PLAYER_BODY)->getHeadSpr();
	int head = m_entityManager->getComp(eid, ComponentType::PLAYER_BODY)->getHead();
	typedef std::multimap<int, std::pair< unsigned int, Direction>>::iterator MMAPIterator;
	std::pair<MMAPIterator, MMAPIterator> resultHead = m_animationsHead.equal_range(head);
	//int countHeads = std::distance(resultHead.first, resultHead.second); // count should be 4

	for (MMAPIterator it = resultHead.first; it != resultHead.second; it++)
		m_entityManager->getComp(eid, ComponentType::PLAYER_BODY)->setHeadGs(it->second.second, it->second.first);

	Direction dir = m_entityManager->getComp(eid, ComponentType::PLAYER_BODY)->getDirection();
	headSpr->setSpriteFrame(m_sfCache->getSpriteFrameByName(std::to_string(m_entityManager->getComp(eid, ComponentType::PLAYER_BODY)->getHeadGs(dir))));

	headSpr->setPosition(bodySpr->getContentSize().width / 2, bodySpr->getContentSize().height);
}

void GraphicsSystem::loadShield(int eid, cocos2d::Event * ccEvent, SLNet::BitStream * bs)
{
	auto bodySpr = m_entityManager->getComp(eid, ComponentType::PLAYER_BODY)->getBodySpr();

	auto shieldSpr = m_entityManager->getComp(eid, ComponentType::PLAYER_BODY)->getShieldSpr();
	int shield = m_entityManager->getComp(eid, ComponentType::PLAYER_BODY)->getShield();
	typedef std::multimap<int, std::pair< unsigned int, Direction>>::iterator MMAPIterator;
	std::pair<MMAPIterator, MMAPIterator> resultShield = m_animationsShield.equal_range(shield);
	//int countShields = std::distance(resultShield.first, resultShield.second); // count should be 4

	for (MMAPIterator it = resultShield.first; it != resultShield.second; it++)
		m_entityManager->getComp(eid, ComponentType::PLAYER_BODY)->setShieldGs(it->second.second, it->second.first);

	Direction dir = m_entityManager->getComp(eid, ComponentType::PLAYER_BODY)->getDirection();
	shieldSpr->setSpriteFrame(m_sfCache->getSpriteFrameByName(std::to_string(m_entityManager->getComp(eid, ComponentType::PLAYER_BODY)->getShieldGs(dir))));

	shieldSpr->setPosition(bodySpr->getContentSize().width / 2, bodySpr->getContentSize().height);

	Vector<SpriteFrame*> spriteFrames;
	for (MMAPIterator it = resultShield.first; it != resultShield.second; it++)
	{
		for (auto f : m_graphicsData.at(it->second.first)->frames)
		{
			spriteFrames.pushBack(m_sfCache->getSpriteFrameByName(std::to_string(f)));
		}
		Animate* anim;

		if (it->second.second == Direction::North || it->second.second == Direction::South)
			anim = Animate::create(Animation::createWithSpriteFrames(spriteFrames, m_NS));
		else
			anim = Animate::create(Animation::createWithSpriteFrames(spriteFrames, m_EW));

		anim->retain();
		m_entityManager->getComp(eid, ComponentType::PLAYER_BODY)->setAnimShield(it->second.second, anim);
		spriteFrames.clear();
	}
}

void GraphicsSystem::loadHelmet(int eid, cocos2d::Event * ccEvent, SLNet::BitStream * bs)
{
	auto bodySpr = m_entityManager->getComp(eid, ComponentType::PLAYER_BODY)->getBodySpr();

	auto helmetSpr = m_entityManager->getComp(eid, ComponentType::PLAYER_BODY)->getHelmetSpr();
	int helmet = m_entityManager->getComp(eid, ComponentType::PLAYER_BODY)->getHelmet();
	typedef std::multimap<int, std::pair< unsigned int, Direction>>::iterator MMAPIterator;
	std::pair<MMAPIterator, MMAPIterator> resultHelmet = m_animationsHelmet.equal_range(helmet);
	//int countHelmets = std::distance(resultHelmet.first, resultHelmet.second); // count should be 4

	for (MMAPIterator it = resultHelmet.first; it != resultHelmet.second; it++)
		m_entityManager->getComp(eid, ComponentType::PLAYER_BODY)->setHelmetGs(it->second.second, it->second.first);

	Direction dir = m_entityManager->getComp(eid, ComponentType::PLAYER_BODY)->getDirection();
	helmetSpr->setSpriteFrame(m_sfCache->getSpriteFrameByName(std::to_string(m_entityManager->getComp(eid, ComponentType::PLAYER_BODY)->getHelmetGs(dir))));

	helmetSpr->setPosition(bodySpr->getContentSize().width / 2, bodySpr->getContentSize().height);
}

void GraphicsSystem::loadWeapon(int eid, cocos2d::Event * ccEvent, SLNet::BitStream * bs)
{
	auto bodySpr = m_entityManager->getComp(eid, ComponentType::PLAYER_BODY)->getBodySpr();

	auto weaponSpr = m_entityManager->getComp(eid, ComponentType::PLAYER_BODY)->getWeaponSpr();
	int weapon = m_entityManager->getComp(eid, ComponentType::PLAYER_BODY)->getWeapon();
	typedef std::multimap<int, std::pair< unsigned int, Direction>>::iterator MMAPIterator;
	std::pair<MMAPIterator, MMAPIterator> resultWeapon = m_animationsWeapon.equal_range(weapon);
	//int countWeapons = std::distance(resultWeapon.first, resultWeapon.second); // count should be 4

	for (MMAPIterator it = resultWeapon.first; it != resultWeapon.second; it++)
		m_entityManager->getComp(eid, ComponentType::PLAYER_BODY)->setWeaponGs(it->second.second, it->second.first);

	Direction dir = m_entityManager->getComp(eid, ComponentType::PLAYER_BODY)->getDirection();
	weaponSpr->setSpriteFrame(m_sfCache->getSpriteFrameByName(std::to_string(m_entityManager->getComp(eid, ComponentType::PLAYER_BODY)->getWeaponGs(dir))));

	weaponSpr->setPosition(bodySpr->getContentSize().width / 2, bodySpr->getContentSize().height);

	Vector<SpriteFrame*> spriteFrames;
	for (MMAPIterator it = resultWeapon.first; it != resultWeapon.second; it++)
	{
		for (auto f : m_graphicsData.at(it->second.first)->frames)
		{
			spriteFrames.pushBack(m_sfCache->getSpriteFrameByName(std::to_string(f)));
		}
		Animate* anim;

		if (it->second.second == Direction::North || it->second.second == Direction::South)
			 anim = Animate::create(Animation::createWithSpriteFrames(spriteFrames, m_NS));
		else
			anim = Animate::create(Animation::createWithSpriteFrames(spriteFrames, m_EW));

		anim->retain();
		m_entityManager->getComp(eid, ComponentType::PLAYER_BODY)->setAnimWeapon(it->second.second, anim);
		spriteFrames.clear();
	}
}

void GraphicsSystem::loadGraphicsIndex()
{
	std::string graphicsIndPath = m_fileUtils->fullPathForFilename("Graphics.ind");
	auto graphicsIndData = m_fileUtils->getDataFromFile(graphicsIndPath);
	cocos2d::log("[GRAPHICS SYSTEM] File: %s", graphicsIndPath.c_str());

	ssize_t bufferSize;
	BufferedFile bFile;
	bFile.buffer = graphicsIndData.takeBuffer(&bufferSize);

	int fileVersion = bFile.read(&fileVersion);
	cocos2d::log("[GRAPHICS SYSTEM] FileVersion: %d", fileVersion);
	unsigned int graphicsCount = bFile.read(&graphicsCount);
	cocos2d::log("[GRAPHICS SYSTEM] graphicsCount: %d", graphicsCount);

	unsigned int index = 0;

	while (index != graphicsCount)
	{
		auto dat = new (std::nothrow) GraphicData;

		index = bFile.read(&index);

		dat->framesCount = bFile.read(&dat->framesCount);

		if (dat->framesCount > 1)
		{
			dat->frames.reserve(dat->framesCount);

			for (unsigned int j = 0; j < dat->framesCount; j++)
			{
				uint32_t f = bFile.read(&f);
				dat->frames.push_back(f);
			}

			dat->id = m_graphicsData.at(dat->frames[0])->id;
			dat->speed = bFile.read(&dat->speed);
			dat->startX = m_graphicsData.at(dat->frames[0])->startX;
			dat->startY = m_graphicsData.at(dat->frames[0])->startY;
			dat->width = m_graphicsData.at(dat->frames[0])->width;
			dat->height = m_graphicsData.at(dat->frames[0])->height;
			dat->tileWidth = m_graphicsData.at(dat->frames[0])->tileWidth;
			dat->tileHeight = m_graphicsData.at(dat->frames[0])->tileHeight;
		}
		else
		{
			dat->id = bFile.read(&dat->id);
			dat->startX = bFile.read(&dat->startX);
			dat->startY = bFile.read(&dat->startY);
			dat->width = bFile.read(&dat->width);
			dat->height = bFile.read(&dat->height);

			dat->tileWidth = dat->width / 32;
			dat->tileHeight = dat->height / 32;

			dat->frames.push_back(index);
			dat->speed = 0.0f;
		}

		m_graphicsData.emplace(index, dat);
		/*cocos2d::log("===========================");
		cocos2d::log("Graphic Data:");
		cocos2d::log("index: %i", index);
		cocos2d::log("ID: %i", dat->id);
		cocos2d::log("startX: %i", dat->startX);
		cocos2d::log("startY: %i", dat->startY);
		cocos2d::log("width: %i", dat->width);
		cocos2d::log("height: %i", dat->height);
		cocos2d::log("tileWidth: %f", dat->tileWidth);
		cocos2d::log("tileHeight: %f", dat->tileHeight);
		//cocos2d::log("frames: %i", dat->frames.size());
		cocos2d::log("framesCount: %i", dat->framesCount);
		cocos2d::log("speed: %f", dat->speed);
		cocos2d::log("===========================");
		cocos2d::log("");*/

	}
}

void GraphicsSystem::loadTextures()
{
	std::string f;
	for (auto g : m_graphicsData)
	{
		f = m_fileUtils->fullPathForFilename(std::to_string(g.second->id) + ".png");
		auto sprFrame = SpriteFrame::create(f, Rect(g.second->startX, g.second->startY, g.second->width, g.second->height));
		m_sfCache->addSpriteFrame(sprFrame, std::to_string(g.first));
	}

	//for (auto g : m_graphicsData)
	//	cocos2d::log("[GRAPHICS SYSTEM] Loaded Frames to Cache: %i %i",
	//		g.first, m_sfCache->getSpriteFrameByName(std::to_string(g.first))->_ID);
}

void GraphicsSystem::loadAnimations()
{
	loadHeads();
	loadBodies();
	loadHelmets();
	loadWeapons();
	loadShields();
}

void GraphicsSystem::loadHeads()
{
	std::string graphicsIndPath = m_fileUtils->fullPathForFilename("Heads.ini");
	auto graphicsIndData = m_fileUtils->getStringFromFile(graphicsIndPath);
	cocos2d::log("[GRAPHICS SYSTEM] File: %s", graphicsIndPath.c_str());

	std::vector<std::string> lines;
	std::string line = "";
	for (auto c : graphicsIndData)
	{
		if (c == '\n' || c == '\r')
		{
			lines.push_back(line);
			line = "";
		}
		else
			line.push_back(c);
	}

	int count = 0;

	for (auto l : lines)
	{
		if (!l.find("NumHeads"))
		{
			count = std::stoi(l.substr(l.find("=") + 1));
			break;
		}
	}

	unsigned int i = 1;
	for (auto l : lines)
	{
		if (!l.find("Head1"))
		{
			m_animationsHead.emplace(i,
				std::make_pair(std::stoi(l.substr(l.find("=") + 1)), Direction::North));
		}
		else if (!l.find("Head2"))
		{
			m_animationsHead.emplace(i,
				std::make_pair(std::stoi(l.substr(l.find("=") + 1)), Direction::East));
		}
		else if (!l.find("Head3"))
		{
			m_animationsHead.emplace(i,
				std::make_pair(std::stoi(l.substr(l.find("=") + 1)), Direction::South));
		}
		else if (!l.find("Head4"))
		{
			m_animationsHead.emplace(i,
				std::make_pair(std::stoi(l.substr(l.find("=") + 1)), Direction::West));
			i++;
		}
	}
}

void GraphicsSystem::loadBodies()
{
	std::string graphicsIndPath = m_fileUtils->fullPathForFilename("Bodies.ini");
	auto graphicsIndData = m_fileUtils->getStringFromFile(graphicsIndPath);
	cocos2d::log("[GRAPHICS SYSTEM] File: %s", graphicsIndPath.c_str());

	std::vector<std::string> lines;
	std::string line = "";
	for (auto c : graphicsIndData)
	{
		if (c == '\n' || c == '\r')
		{
			lines.push_back(line);
			line = "";
		}
		else
			line.push_back(c);
	}

	int count = 0;

	for (auto l : lines)
	{
		if (!l.find("NumBodies"))
		{
			count = std::stoi(l.substr(l.find("=") + 1));
			break;
		}
	}

	unsigned int i = 1;
	for (auto l : lines)
	{
		if (!l.find("WALK1"))
		{
			m_animationsBody.emplace(i,
				std::make_pair(std::stoi(l.substr(l.find("=") + 1)), Direction::North));
		}
		else if (!l.find("WALK2"))
		{
			m_animationsBody.emplace(i,
				std::make_pair(std::stoi(l.substr(l.find("=") + 1)), Direction::East));
		}
		else if (!l.find("WALK3"))
		{
			m_animationsBody.emplace(i,
				std::make_pair(std::stoi(l.substr(l.find("=") + 1)), Direction::South));
		}
		else if (!l.find("WALK4"))
		{
			m_animationsBody.emplace(i,
				std::make_pair(std::stoi(l.substr(l.find("=") + 1)), Direction::West));
			i++;
		}
	}
}

void GraphicsSystem::loadHelmets()
{
	std::string graphicsIndPath = m_fileUtils->fullPathForFilename("Helmets.ini");
	auto graphicsIndData = m_fileUtils->getStringFromFile(graphicsIndPath);
	cocos2d::log("[GRAPHICS SYSTEM] File: %s", graphicsIndPath.c_str());

	std::vector<std::string> lines;
	std::string line = "";
	for (auto c : graphicsIndData)
	{
		if (c == '\n' || c == '\r')
		{
			lines.push_back(line);
			line = "";
		}
		else
			line.push_back(c);
	}

	int count = 0;

	for (auto l : lines)
	{
		if (!l.find("NumCascos"))
		{
			count = std::stoi(l.substr(l.find("=") + 1));
			break;
		}
	}

	unsigned int i = 1;
	for (auto l : lines)
	{
		if (!l.find("Head1"))
		{
			m_animationsHelmet.emplace(i,
				std::make_pair(std::stoi(l.substr(l.find("=") + 1)), Direction::North));
		}
		else if (!l.find("Head2"))
		{
			m_animationsHelmet.emplace(i,
				std::make_pair(std::stoi(l.substr(l.find("=") + 1)), Direction::East));
		}
		else if (!l.find("Head3"))
		{
			m_animationsHelmet.emplace(i,
				std::make_pair(std::stoi(l.substr(l.find("=") + 1)), Direction::South));
		}
		else if (!l.find("Head4"))
		{
			m_animationsHelmet.emplace(i,
				std::make_pair(std::stoi(l.substr(l.find("=") + 1)), Direction::West));
			i++;
		}
	}
}

void GraphicsSystem::loadWeapons()
{
	std::string graphicsIndPath = m_fileUtils->fullPathForFilename("Weapons.ini");
	auto graphicsIndData = m_fileUtils->getStringFromFile(graphicsIndPath);
	cocos2d::log("[GRAPHICS SYSTEM] File: %s", graphicsIndPath.c_str());

	std::vector<std::string> lines;
	std::string line = "";
	for (auto c : graphicsIndData)
	{
		if (c == '\n' || c == '\r')
		{
			lines.push_back(line);
			line = "";
		}
		else
			line.push_back(c);
	}

	int count = 0;

	for (auto l : lines)
	{
		if (!l.find("NumArmas"))
		{
			count = std::stoi(l.substr(l.find("=") + 1));
			break;
		}
	}

	unsigned int i = 1;
	for (auto l : lines)
	{
		if (!l.find("Dir1"))
		{
			m_animationsWeapon.emplace(i,
				std::make_pair(std::stoi(l.substr(l.find("=") + 1)), Direction::North));
		}
		else if (!l.find("Dir2"))
		{
			m_animationsWeapon.emplace(i,
				std::make_pair(std::stoi(l.substr(l.find("=") + 1)), Direction::East));
		}
		else if (!l.find("Dir3"))
		{
			m_animationsWeapon.emplace(i,
				std::make_pair(std::stoi(l.substr(l.find("=") + 1)), Direction::South));
		}
		else if (!l.find("Dir4"))
		{
			m_animationsWeapon.emplace(i,
				std::make_pair(std::stoi(l.substr(l.find("=") + 1)), Direction::West));
			i++;
		}
	}
}

void GraphicsSystem::loadShields()
{
	std::string graphicsIndPath = m_fileUtils->fullPathForFilename("Shields.ini");
	auto graphicsIndData = m_fileUtils->getStringFromFile(graphicsIndPath);
	cocos2d::log("[GRAPHICS SYSTEM] File: %s", graphicsIndPath.c_str());

	std::vector<std::string> lines;
	std::string line = "";
	for (auto c : graphicsIndData)
	{
		if (c == '\n' || c == '\r')
		{
			lines.push_back(line);
			line = "";
		}
		else
			line.push_back(c);
	}

	int count = 0;

	for (auto l : lines)
	{
		if (!l.find("NumEscudos"))
		{
			count = std::stoi(l.substr(l.find("=") + 1));
			break;
		}
	}

	unsigned int i = 1;
	for (auto l : lines)
	{
		if (!l.find("Dir1"))
		{
			m_animationsShield.emplace(i,
				std::make_pair(std::stoi(l.substr(l.find("=") + 1)), Direction::North));
		}
		else if (!l.find("Dir2"))
		{
			m_animationsShield.emplace(i,
				std::make_pair(std::stoi(l.substr(l.find("=") + 1)), Direction::East));
		}
		else if (!l.find("Dir3"))
		{
			m_animationsShield.emplace(i,
				std::make_pair(std::stoi(l.substr(l.find("=") + 1)), Direction::South));
		}
		else if (!l.find("Dir4"))
		{
			m_animationsShield.emplace(i,
				std::make_pair(std::stoi(l.substr(l.find("=") + 1)), Direction::West));
			i++;
		}
	}
}
