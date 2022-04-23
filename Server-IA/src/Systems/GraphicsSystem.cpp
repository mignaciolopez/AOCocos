#include "GraphicsSystem.h"

GraphicsSystem::GraphicsSystem(entt::registry* registry)
	: m_registry(registry), m_signalsManager(nullptr)
{
	ECS_Log::s_consoleL->trace("[GraphicsSystem] Constructor");
	
	m_signalsManager = ECS::SignalsManager::getSignalsManager();

	m_signalsManager->connect<&GraphicsSystem::loadBody>(Signals::GRAPHICS_LOAD_BODY, this);
	m_signalsManager->connect<&GraphicsSystem::loadHead>(Signals::GRAPHICS_LOAD_HEAD, this);
	m_signalsManager->connect<&GraphicsSystem::loadHelmet>(Signals::GRAPHICS_LOAD_HELMET, this);
	m_signalsManager->connect<&GraphicsSystem::loadShield>(Signals::GRAPHICS_LOAD_SHIELD, this);
	m_signalsManager->connect<&GraphicsSystem::loadWeapon>(Signals::GRAPHICS_LOAD_WEAPON, this);

	m_signalsManager->connect<&GraphicsSystem::animateSpell>(Signals::ANIMATE_SPELL, this);
	m_signalsManager->connect<&GraphicsSystem::animateWeapon>(Signals::ANIMATE_WEAPON, this);
	m_signalsManager->connect<&GraphicsSystem::animateShield>(Signals::ANIMATE_SHIELD, this);

}

GraphicsSystem::~GraphicsSystem()
{
	ECS_Log::s_consoleL->trace("[GraphicsSystem] Destructor");

	m_signalsManager->disconnectAll(this);
}

void GraphicsSystem::update(double dt)
{
}

void GraphicsSystem::loadBody(entt::entity entity, SLNet::BitStream * bs)
{
	if (!bs)
	{
		return;
	}
	Bodies body;
	bs->Read(body);

	auto playerC = m_registry->try_get<PlayerComponent>(entity);
	if (!playerC)
	{
		return;
	}

	playerC->_body = body;

	SLNet::BitStream bsOut;
	bsOut.Write((SLNet::MessageID)Signals::GRAPHICS_LOAD_BODY);
	bsOut.Write(entity);
	bsOut.Write(body);
	m_signalsManager->publish(Signals::NW_SEND_BROADCAST, entity, &bsOut);
}

void GraphicsSystem::loadHead(entt::entity entity, SLNet::BitStream * bs)
{
	if (!bs)
	{
		return;
	}
	Heads head;
	bs->Read(head);

	auto playerC = m_registry->try_get<PlayerComponent>(entity);
	if (!playerC)
	{
		return;
	}

	playerC->_head = head;

	SLNet::BitStream bsOut;
	bsOut.Write((SLNet::MessageID)Signals::GRAPHICS_LOAD_HEAD);
	bsOut.Write(entity);
	bsOut.Write(head);
	m_signalsManager->publish(Signals::NW_SEND_BROADCAST, entity, &bsOut);
}

void GraphicsSystem::loadHelmet(entt::entity entity, SLNet::BitStream * bs)
{
	if (!bs)
	{
		return;
	}
	Helmets helmet;
	bs->Read(helmet);

	auto playerC = m_registry->try_get<PlayerComponent>(entity);
	if (!playerC)
	{
		return;
	}

	playerC->_helmet = helmet;

	SLNet::BitStream bsOut;
	bsOut.Write((SLNet::MessageID)Signals::GRAPHICS_LOAD_HELMET);
	bsOut.Write(entity);
	bsOut.Write(helmet);
	m_signalsManager->publish(Signals::NW_SEND_BROADCAST, entity, &bsOut);
}

void GraphicsSystem::loadShield(entt::entity entity, SLNet::BitStream * bs)
{
	if (!bs)
	{
		return;
	}
	Shields shield;
	bs->Read(shield);

	auto playerC = m_registry->try_get<PlayerComponent>(entity);
	if (!playerC)
	{
		return;
	}

	playerC->_shield = shield;

	SLNet::BitStream bsOut;
	bsOut.Write((SLNet::MessageID)Signals::GRAPHICS_LOAD_SHIELD);
	bsOut.Write(entity);
	bsOut.Write(shield);
	m_signalsManager->publish(Signals::NW_SEND_BROADCAST, entity, &bsOut);
}

void GraphicsSystem::loadWeapon(entt::entity entity, SLNet::BitStream * bs)
{
	if (!bs)
	{
		return;
	}
	Weapons weapon;
	bs->Read(weapon);

	auto playerC = m_registry->try_get<PlayerComponent>(entity);
	if (!playerC)
	{
		return;
	}

	playerC->_weapon = weapon;

	SLNet::BitStream bsOut;
	bsOut.Write((SLNet::MessageID)Signals::GRAPHICS_LOAD_WEAPON);
	bsOut.Write(entity);
	bsOut.Write(weapon);
	m_signalsManager->publish(Signals::NW_SEND_BROADCAST, entity, &bsOut);
}

void GraphicsSystem::animateSpell(entt::entity entity, SLNet::BitStream * bs)
{
	if (!bs)
	{
		return;
	}
	Animations anim;
	bs->Read(anim);

	SLNet::BitStream bsOut;
	bsOut.Write((SLNet::MessageID)Signals::ANIMATE_SPELL);
	bsOut.Write(entity);
	bsOut.Write(anim);
	m_signalsManager->publish(Signals::NW_SEND_BROADCAST, entity, &bsOut);
}

void GraphicsSystem::animateWeapon(entt::entity entity, SLNet::BitStream * bs)
{
	SLNet::BitStream bsOut;
	bsOut.Write((SLNet::MessageID)Signals::ANIMATE_WEAPON);
	bsOut.Write(entity);
	m_signalsManager->publish(Signals::NW_SEND_BROADCAST, entity, &bsOut);
}

void GraphicsSystem::animateShield(entt::entity entity, SLNet::BitStream * bs)
{
	SLNet::BitStream bsOut;
	bsOut.Write((SLNet::MessageID)Signals::ANIMATE_SHIELD);
	bsOut.Write(entity);
	m_signalsManager->publish(Signals::NW_SEND_BROADCAST, entity, &bsOut);
}
