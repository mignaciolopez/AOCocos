#include "AnimationSystem.h"

#include "Components/PlayerBodyComponent.h"

#include "Graphics/Graphics.h"

AnimationSystem::AnimationSystem()
{
	cocos2d::log("%s Constructor", "[ANIMATION SYSTEM]");

	m_director = cocos2d::Director::getInstance();
	m_entityManager = ECS::ECS_Engine::getInstance()->getEntityManager();
	m_eventManager = ECS::ECS_Engine::getInstance()->getEventManager();
	m_sfCache = cocos2d::SpriteFrameCache::getInstance();

	m_eventManager->Subscribe(EVENTS::ANIMATE, &AnimationSystem::animate, this);

	m_eventManager->Subscribe(EVENTS::LOAD_ANIMATION_INFO, &AnimationSystem::loadAnimationInfo, this);

	m_eventManager->Subscribe(EVENTS::EID_QUIT, &AnimationSystem::removeInfo, this);
}

AnimationSystem::~AnimationSystem()
{
	for (auto a : m_animations)
	{
		if (a.second)
		{
			delete a.second;
			a.second = nullptr;
		}
	}

	cocos2d::log("%s Destructor", "[ANIMATION SYSTEM]");
}

void AnimationSystem::Update()
{
	for (auto it : *m_entityManager->getEntities())
	{
		if (!m_entityManager->getComp(it.first, PLAYER_BODY)->getMoving())
		{
			if (m_animations.find(it.first) == m_animations.end())
				return;

			//stop animation
			//and set sprites of current direction
		}
	}
}

void AnimationSystem::animate(int eid, cocos2d::Event *, SLNet::BitStream* bs)
{
	if (m_animations.find(eid) == m_animations.end())
		return;

	setBody(eid);
	setHead(eid);

	//animate here
	
}

void AnimationSystem::setBody(int eid)
{
	switch (m_entityManager->getComp(eid, PLAYER_BODY)->getDirection())
	{
	case Direction::North:
		m_entityManager->getComp(eid, PLAYER_BODY)->getBodySpr()->setSpriteFrame(
			m_sfCache->getSpriteFrameByName(m_animations.at(eid)->m_bodyNameNorth));
		break;
	case Direction::East:
		m_entityManager->getComp(eid, PLAYER_BODY)->getBodySpr()->setSpriteFrame(
			m_sfCache->getSpriteFrameByName(m_animations.at(eid)->m_bodyNameEast));
		break;
	case Direction::South:
		m_entityManager->getComp(eid, PLAYER_BODY)->getBodySpr()->setSpriteFrame(
			m_sfCache->getSpriteFrameByName(m_animations.at(eid)->m_bodyNameSouth));
		break;
	case Direction::West:
		m_entityManager->getComp(eid, PLAYER_BODY)->getBodySpr()->setSpriteFrame(
			m_sfCache->getSpriteFrameByName(m_animations.at(eid)->m_bodyNameWest));
		break;
	}
}

void AnimationSystem::setHead(int eid)
{
	switch (m_entityManager->getComp(eid, PLAYER_BODY)->getDirection())
	{
	case Direction::North:
		m_entityManager->getComp(eid, PLAYER_BODY)->getHeadSpr()->setSpriteFrame(
			m_sfCache->getSpriteFrameByName(m_animations.at(eid)->m_headNameNorth));
		break;
	case Direction::East:
		m_entityManager->getComp(eid, PLAYER_BODY)->getHeadSpr()->setSpriteFrame(
			m_sfCache->getSpriteFrameByName(m_animations.at(eid)->m_headNameEast));
		break;
	case Direction::South:
		m_entityManager->getComp(eid, PLAYER_BODY)->getHeadSpr()->setSpriteFrame(
			m_sfCache->getSpriteFrameByName(m_animations.at(eid)->m_headNameSouth));
		break;
	case Direction::West:
		m_entityManager->getComp(eid, PLAYER_BODY)->getHeadSpr()->setSpriteFrame(
			m_sfCache->getSpriteFrameByName(m_animations.at(eid)->m_headNameWest));
		break;
	}
}

void AnimationSystem::loadAnimationInfo(int eid, cocos2d::Event *, SLNet::BitStream * bs)
{
	animationInfo* animInfo = new (std::nothrow) animationInfo;
	animInfo->tag = newTag();

	for (int i = 0; i <= Direction::West; i++)
	{
		Direction dir = static_cast<Direction>(i);

		m_dirName = "";
		constructDirectionName(dir);

		m_bodyName = "Player-Body-";
		constructBodyName(eid);

		m_headName = "Heads/Player-Head-";
		constructHeadName(eid);

		m_bodyName.append("Standing-" + m_dirName + ".png");
		m_headName.append(m_dirName + ".png");

		switch (dir)
		{
		case Direction::North:
			animInfo->m_bodyNameNorth = m_bodyName;
			animInfo->m_headNameNorth = m_headName;
			break;
		case Direction::East:
			animInfo->m_bodyNameEast = m_bodyName;
			animInfo->m_headNameEast = m_headName;
			break;
		case Direction::South:
			animInfo->m_bodyNameSouth = m_bodyName;
			animInfo->m_headNameSouth = m_headName;
			break;
		case Direction::West:
			animInfo->m_bodyNameWest = m_bodyName;
			animInfo->m_headNameWest = m_headName;
			break;
		default:
			break;
		}

		//void constructAnimationName(int eid);
	}

	m_animations.emplace(eid, animInfo);

}

void AnimationSystem::removeInfo(int eid, cocos2d::Event *, SLNet::BitStream * bs)
{
	if (m_animations.find(eid) == m_animations.end())
		return;
	
	if (m_animations.at(eid))
	{
		delete m_animations.at(eid);
		m_animations.at(eid) = nullptr;
	}
	
	m_animations.erase(eid);
}

int AnimationSystem::newTag()
{
	int tag = 0;

	if (m_animations.find(tag) != m_animations.end())
		tag++;

	return tag;
}

void AnimationSystem::constructDirectionName(Direction dir)
{
	switch (dir)
	{
	case Direction::North:
		m_dirName = "North";
		break;
	case Direction::East:
		m_dirName = "East";
		break;
	case Direction::South:
		m_dirName = "South";
		break;
	case Direction::West:
		m_dirName = "West";
		break;
	default:
		break;
	}
}

void AnimationSystem::constructBodyName(int eid)
{
	switch (m_entityManager->getComp(eid, PLAYER_BODY)->getRace())
	{
	case Race::Human:
		m_bodyName.append("Human-");
		break;
	case Race::Dwarf:
		m_bodyName.append("Dwarf-");
		break;
	case Race::Gnome:
		m_bodyName.append("Gnome-");
		break;
	case Race::Elf:
		m_bodyName.append("Elf-");
		break;
	case Race::DarkElf:
		m_bodyName.append("DarkElf-");
		break;
	default:
		break;
	}

	switch (m_entityManager->getComp(eid, PLAYER_BODY)->getGenre())
	{
	case Genre::Male:
		m_bodyName.append("Male-");
		break;
	case Genre::Female:
		m_bodyName.append("Female-");
		break;
	default:
		break;
	}
}

void AnimationSystem::constructHeadName(int eid)
{
	switch (m_entityManager->getComp(eid, PLAYER_BODY)->getHead())
	{
	case Head::Pirate:
		m_headName.append("Pirate-");
		break;
	default:
		break;
	}
}

void AnimationSystem::constructAnimationName(int eid)
{
	
}
