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
	//m_eventManager->Subscribe(EVENTS::ANIMATION_SWITCH_FACING, &AnimationSystem::setBodyCF, this);

	m_eventManager->Subscribe(EVENTS::ANIMATION_LOAD_INFO, &AnimationSystem::loadAnimationInfo, this);

	m_eventManager->Subscribe(EVENTS::ANIMATION_REMOVE_INFO, &AnimationSystem::removeInfo, this);
}

AnimationSystem::~AnimationSystem()
{
	for (auto a : m_animations)
	{
		if (a.second)
		{
			if (a.second->m_animationNorth)
				a.second->m_animationNorth->release();
			if (a.second->m_animationEast)
				a.second->m_animationEast->release();
			if (a.second->m_animationSouth)
				a.second->m_animationSouth->release();
			if (a.second->m_animationWest)
				a.second->m_animationWest->release();
			
			delete a.second;
			a.second = nullptr;
		}
	}

	cocos2d::log("%s Destructor", "[ANIMATION SYSTEM]");
}

void AnimationSystem::Update()
{
	for (auto e : *m_entityManager->getEntities())
	{
		if (!m_entityManager->getComp(e.first, PLAYER_BODY)->getMoving())
			setBodyCF(e.first);
	}
}

void AnimationSystem::animate(int eid, cocos2d::Event*, SLNet::BitStream* bs)
{
	if (m_animations.find(eid) == m_animations.end())
		return;

	setHead(eid);

	switch (m_entityManager->getComp(eid, ComponentType::PLAYER_BODY)->getDirection())
	{
	case Direction::North:
		m_entityManager->getComp(eid, ComponentType::PLAYER_BODY)->getBodySpr()->
			runAction(m_animations.at(eid)->m_animationNorth->clone());
		break;
	case Direction::East:
		m_entityManager->getComp(eid, ComponentType::PLAYER_BODY)->getBodySpr()->
			runAction(m_animations.at(eid)->m_animationEast->clone());
		break;
	case Direction::South:
		m_entityManager->getComp(eid, ComponentType::PLAYER_BODY)->getBodySpr()->
			runAction(m_animations.at(eid)->m_animationSouth->clone());
		break;
	case Direction::West:
		m_entityManager->getComp(eid, ComponentType::PLAYER_BODY)->getBodySpr()->
			runAction(m_animations.at(eid)->m_animationWest->clone());
		break;
	}
}

void AnimationSystem::setBodyCF(int eid)
{
	setBody(eid);
	setHead(eid);
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
	animInfo->tagN = newTag();
	animInfo->tagE = newTag();
	animInfo->tagS = newTag();
	animInfo->tagW = newTag();

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

		constructAnimation(eid, dir, animInfo);
	}

	animInfo->m_animationNorth->setTag(animInfo->tagN);
	animInfo->m_animationEast->setTag(animInfo->tagE);
	animInfo->m_animationSouth->setTag(animInfo->tagS);
	animInfo->m_animationWest->setTag(animInfo->tagW);

	animInfo->m_animationNorth->retain();
	animInfo->m_animationEast->retain();
	animInfo->m_animationSouth->retain();
	animInfo->m_animationWest->retain();

	m_animations.emplace(eid, animInfo);

}

void AnimationSystem::removeInfo(int eid, cocos2d::Event *, SLNet::BitStream * bs)
{
	if (m_animations.find(eid) == m_animations.end())
		return;
	
	if (m_animations.at(eid))
	{
		if (m_animations.at(eid)->m_animationNorth)
			m_animations.at(eid)->m_animationNorth->release();
		if (m_animations.at(eid)->m_animationEast)
			m_animations.at(eid)->m_animationEast->release();
		if (m_animations.at(eid)->m_animationSouth)
			m_animations.at(eid)->m_animationSouth->release();
		if (m_animations.at(eid)->m_animationWest)
			m_animations.at(eid)->m_animationWest->release();

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

void AnimationSystem::constructAnimation(int eid, Direction dir, animationInfo* animInfo)
{
	switch (dir)
	{
	case Direction::North:
		switch (m_entityManager->getComp(eid, PLAYER_BODY)->getGenre())
		{
		case Genre::Female:
			switch (m_entityManager->getComp(eid, PLAYER_BODY)->getRace())
			{
			case Race::DarkElf:
				animInfo->m_animationNorth = TP::Graphics::createPLAYER_BODY_DARKELF_FEMALE_NORTHAnimateAction(m_NS);
				break;
			case Race::Dwarf:
				animInfo->m_animationNorth = TP::Graphics::createPLAYER_BODY_DWARF_FEMALE_NORTHAnimateAction(m_NS);
				break;
			case Race::Elf:
				animInfo->m_animationNorth = TP::Graphics::createPLAYER_BODY_ELF_FEMALE_NORTHAnimateAction(m_NS);
				break;
			case Race::Gnome:
				animInfo->m_animationNorth = TP::Graphics::createPLAYER_BODY_GNOME_FEMALE_NORTHAnimateAction(m_NS);
				break;
			case Race::Human:
				animInfo->m_animationNorth = TP::Graphics::createPLAYER_BODY_HUMAN_FEMALE_NORTHAnimateAction(m_NS);
				break;
			default:
				break;
			}
			break;
		case Genre::Male:
			switch (m_entityManager->getComp(eid, PLAYER_BODY)->getRace())
			{
			case Race::DarkElf:
				animInfo->m_animationNorth = TP::Graphics::createPLAYER_BODY_DARKELF_MALE_NORTHAnimateAction(m_NS);
				break;
			case Race::Dwarf:
				animInfo->m_animationNorth = TP::Graphics::createPLAYER_BODY_DWARF_MALE_NORTHAnimateAction(m_NS);
				break;
			case Race::Elf:
				animInfo->m_animationNorth = TP::Graphics::createPLAYER_BODY_ELF_MALE_NORTHAnimateAction(m_NS);
				break;
			case Race::Gnome:
				animInfo->m_animationNorth = TP::Graphics::createPLAYER_BODY_GNOME_MALE_NORTHAnimateAction(m_NS);
				break;
			case Race::Human:
				animInfo->m_animationNorth = TP::Graphics::createPLAYER_BODY_HUMAN_MALE_NORTHAnimateAction(m_NS);
				break;
			default:
				break;
			}
			break;
		default:
			break;
		}
	case Direction::East:
		switch (m_entityManager->getComp(eid, PLAYER_BODY)->getGenre())
		{
		case Genre::Female:
			switch (m_entityManager->getComp(eid, PLAYER_BODY)->getRace())
			{
			case Race::DarkElf:
				animInfo->m_animationEast = TP::Graphics::createPLAYER_BODY_DARKELF_FEMALE_EASTAnimateAction(m_EW);
				break;
			case Race::Dwarf:
				animInfo->m_animationEast = TP::Graphics::createPLAYER_BODY_DWARF_FEMALE_EASTAnimateAction(m_EW);
				break;
			case Race::Elf:
				animInfo->m_animationEast = TP::Graphics::createPLAYER_BODY_ELF_FEMALE_EASTAnimateAction(m_EW);
				break;
			case Race::Gnome:
				animInfo->m_animationEast = TP::Graphics::createPLAYER_BODY_GNOME_FEMALE_EASTAnimateAction(m_EW);
				break;
			case Race::Human:
				animInfo->m_animationEast = TP::Graphics::createPLAYER_BODY_HUMAN_FEMALE_EASTAnimateAction(m_EW);
				break;
			default:
				break;
			}
			break;
		case Genre::Male:
			switch (m_entityManager->getComp(eid, PLAYER_BODY)->getRace())
			{
			case Race::DarkElf:
				animInfo->m_animationEast = TP::Graphics::createPLAYER_BODY_DARKELF_MALE_EASTAnimateAction(m_EW);
				break;
			case Race::Dwarf:
				animInfo->m_animationEast = TP::Graphics::createPLAYER_BODY_DWARF_MALE_EASTAnimateAction(m_EW);
				break;
			case Race::Elf:
				animInfo->m_animationEast = TP::Graphics::createPLAYER_BODY_ELF_MALE_EASTAnimateAction(m_EW);
				break;
			case Race::Gnome:
				animInfo->m_animationEast = TP::Graphics::createPLAYER_BODY_GNOME_MALE_EASTAnimateAction(m_EW);
				break;
			case Race::Human:
				animInfo->m_animationEast = TP::Graphics::createPLAYER_BODY_HUMAN_MALE_EASTAnimateAction(m_EW);
				break;
			default:
				break;
			}
			break;
		default:
			break;
		}
	case Direction::South:
		switch (m_entityManager->getComp(eid, PLAYER_BODY)->getGenre())
		{
		case Genre::Female:
			switch (m_entityManager->getComp(eid, PLAYER_BODY)->getRace())
			{
			case Race::DarkElf:
				animInfo->m_animationSouth = TP::Graphics::createPLAYER_BODY_DARKELF_FEMALE_SOUTHAnimateAction(m_NS);
				break;
			case Race::Dwarf:
				animInfo->m_animationSouth = TP::Graphics::createPLAYER_BODY_DWARF_FEMALE_SOUTHAnimateAction(m_NS);
				break;
			case Race::Elf:
				animInfo->m_animationSouth = TP::Graphics::createPLAYER_BODY_ELF_FEMALE_SOUTHAnimateAction(m_NS);
				break;
			case Race::Gnome:
				animInfo->m_animationSouth = TP::Graphics::createPLAYER_BODY_GNOME_FEMALE_SOUTHAnimateAction(m_NS);
				break;
			case Race::Human:
				animInfo->m_animationSouth = TP::Graphics::createPLAYER_BODY_HUMAN_FEMALE_SOUTHAnimateAction(m_NS);
				break;
			default:
				break;
			}
			break;
		case Genre::Male:
			switch (m_entityManager->getComp(eid, PLAYER_BODY)->getRace())
			{
			case Race::DarkElf:
				animInfo->m_animationSouth = TP::Graphics::createPLAYER_BODY_DARKELF_MALE_SOUTHAnimateAction(m_NS);
				break;
			case Race::Dwarf:
				animInfo->m_animationSouth = TP::Graphics::createPLAYER_BODY_DWARF_MALE_SOUTHAnimateAction(m_NS);
				break;
			case Race::Elf:
				animInfo->m_animationSouth = TP::Graphics::createPLAYER_BODY_ELF_MALE_SOUTHAnimateAction(m_NS);
				break;
			case Race::Gnome:
				animInfo->m_animationSouth = TP::Graphics::createPLAYER_BODY_GNOME_MALE_SOUTHAnimateAction(m_NS);
				break;
			case Race::Human:
				animInfo->m_animationSouth = TP::Graphics::createPLAYER_BODY_HUMAN_MALE_SOUTHAnimateAction(m_NS);
				break;
			default:
				break;
			}
			break;
		default:
			break;
		}
	case Direction::West:
		switch (m_entityManager->getComp(eid, PLAYER_BODY)->getGenre())
		{
		case Genre::Female:
			switch (m_entityManager->getComp(eid, PLAYER_BODY)->getRace())
			{
			case Race::DarkElf:
				animInfo->m_animationWest = TP::Graphics::createPLAYER_BODY_DARKELF_FEMALE_WESTAnimateAction(m_EW);
				break;
			case Race::Dwarf:
				animInfo->m_animationWest = TP::Graphics::createPLAYER_BODY_DWARF_FEMALE_WESTAnimateAction(m_EW);
				break;
			case Race::Elf:
				animInfo->m_animationWest = TP::Graphics::createPLAYER_BODY_ELF_FEMALE_WESTAnimateAction(m_EW);
				break;
			case Race::Gnome:
				animInfo->m_animationWest = TP::Graphics::createPLAYER_BODY_GNOME_FEMALE_WESTAnimateAction(m_EW);
				break;
			case Race::Human:
				animInfo->m_animationWest = TP::Graphics::createPLAYER_BODY_HUMAN_FEMALE_WESTAnimateAction(m_EW);
				break;
			default:
				break;
			}
			break;
		case Genre::Male:
			switch (m_entityManager->getComp(eid, PLAYER_BODY)->getRace())
			{
			case Race::DarkElf:
				animInfo->m_animationWest = TP::Graphics::createPLAYER_BODY_DARKELF_MALE_WESTAnimateAction(m_EW);
				break;
			case Race::Dwarf:
				animInfo->m_animationWest = TP::Graphics::createPLAYER_BODY_DWARF_MALE_WESTAnimateAction(m_EW);
				break;
			case Race::Elf:
				animInfo->m_animationWest = TP::Graphics::createPLAYER_BODY_ELF_MALE_WESTAnimateAction(m_EW);
				break;
			case Race::Gnome:
				animInfo->m_animationWest = TP::Graphics::createPLAYER_BODY_GNOME_MALE_WESTAnimateAction(m_EW);
				break;
			case Race::Human:
				animInfo->m_animationWest = TP::Graphics::createPLAYER_BODY_HUMAN_MALE_WESTAnimateAction(m_EW);
				break;
			default:
				break;
			}
			break;
		default:
			break;
		}
		break;
	default:
		break;
	}
}
