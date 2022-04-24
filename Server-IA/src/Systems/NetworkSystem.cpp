#include "NetworkSystem.h"

#include <fstream>
#include <iostream>

NetworkSystem::NetworkSystem(entt::registry* registry)
	: m_registry(registry), m_peer(nullptr), m_signalsManager(nullptr)
{
	ECS_Log::s_consoleL->trace("[NetworkSystem] Constructor");

	m_signalsManager = ECS::SignalsManager::getSignalsManager();

	m_peer = nullptr;

	bool load = false;

	if (loadKeyPublic())
		if (loadKeyPrivate())
			load = true;

	if (!load)
		if (generateKeys())
		{
			writeKeyPublic();
			writeKeyPrivate();
		}

	m_peer = SLNet::RakPeerInterface::GetInstance();

	//m_peer->InitializeSecurity(m_public_key, m_private_key, false);

	SLNet::SocketDescriptor sd(6000, 0);
	SLNet::StartupResult result = m_peer->Startup(100, &sd, 1);

	if (result != SLNet::StartupResult::RAKNET_STARTED)
		ECS_Log::s_consoleL->error("[NetworkSystem] peer failed!");

	m_peer->SetMaximumIncomingConnections(100);

	m_online = false;

	m_signalsManager->connect<&NetworkSystem::broadcast>(Signals::NW_SEND_BROADCAST, this);
	m_signalsManager->connect<&NetworkSystem::sendClient>(Signals::NW_SEND_CLIENT, this);
}

NetworkSystem::~NetworkSystem()
{
	ECS_Log::s_consoleL->trace("[NetworkSystem] Destructor");

	int count = 0;
	for (auto& guid : m_clients)
	{
		if (guid.second)
		{
			count++;
			SLNet::BitStream bsOut;
			bsOut.Write((SLNet::MessageID)ID_DISCONNECTION_NOTIFICATION);
			bsOut.Write(guid.first);
			sendClient(guid.first, &bsOut);

			m_registry->destroy(guid.first);

			delete guid.second;
			guid.second = nullptr;
		}
	}

	ECS_Log::s_consoleL->debug("[NetworkSystem] Disconnected and cleanup: {} of {}", count, m_clients.size());

	m_signalsManager->disconnectAll(this);

	if (m_peer)
	{
		ECS_Log::s_consoleL->debug("[NetworkSystem] Shutingdown peer.");
		m_peer->Shutdown(10000);
		SLNet::RakPeerInterface::DestroyInstance(m_peer);
		m_peer = nullptr;
	}
}

void NetworkSystem::update(double dt)
{
	SLNet::Packet* packet = nullptr;
	if (m_peer)
		for (packet = m_peer->Receive(); packet; m_peer->DeallocatePacket(packet), packet = m_peer->Receive())
		{
			SLNet::BitStream bsIn(packet->data, packet->length, false);
			switch (packet->data[0])
			{
			case ID_NEW_INCOMING_CONNECTION:
				ECS_Log::s_consoleL->info("[NetworkSystem] ID_NEW_INCOMING_CONNECTION");
				requestENTT(packet);
				break;
			case ID_NO_FREE_INCOMING_CONNECTIONS:
				ECS_Log::s_consoleL->warn("[NetworkSystem] ID_NO_FREE_INCOMING_CONNECTIONS");
				break;
			case ID_DISCONNECTION_NOTIFICATION:
				ECS_Log::s_consoleL->info("[NetworkSystem] ID_DISCONNECTION_NOTIFICATION");
				disconected(packet);
				break;
			case ID_CONNECTION_LOST:
				ECS_Log::s_consoleL->info("[NetworkSystem] ID_CONNECTION_LOST");
				conectionLost(packet);
				break;
			case ID_REMOTE_DISCONNECTION_NOTIFICATION:
				ECS_Log::s_consoleL->info("[NetworkSystem] ID_REMOTE_DISCONNECTION_NOTIFICATION");
				disconected(packet);
				break;
			case ID_REMOTE_CONNECTION_LOST:
				ECS_Log::s_consoleL->info("[NetworkSystem] ID_REMOTE_CONNECTION_LOST");
				conectionLost(packet);
				break;
			case ID_REMOTE_NEW_INCOMING_CONNECTION:
				ECS_Log::s_consoleL->info("[NetworkSystem] ID_REMOTE_NEW_INCOMING_CONNECTION");
				requestENTT(packet);
				break;
			default:
				ECS_Log::s_consoleL->trace("\n=================================================");
				ECS_Log::s_consoleL->trace("[INFO] Message with identifier %i has arrived.", packet->data[0]);
				ECS_Log::s_consoleL->trace("=================================================\n");
				receive(static_cast<Signals>(packet->data[0]), &bsIn);
				break;
			}
		}
}

void NetworkSystem::broadcast(entt::entity entity, SLNet::BitStream* bsOut)
{
	if (!bsOut)
	{
		ECS_Log::s_consoleL->error("[NetworkSystem] broadcast() bsOut is nullptr. entt:{:d}", entity);
		return;
	}

	if (m_clients.find(entity) != m_clients.end())
		m_peer->Send(bsOut, MEDIUM_PRIORITY, RELIABLE_ORDERED, 0, *m_clients.at(entity), true);
}

void NetworkSystem::sendClient(entt::entity entity, SLNet::BitStream* bsOut)
{
	if (!bsOut)
	{
		ECS_Log::s_consoleL->error("[NetworkSystem] sendClient() bsOut is nullptr. entt:{:d}", entity);
		return;
	}

	if (m_clients.find(entity) != m_clients.end())
		m_peer->Send(bsOut, MEDIUM_PRIORITY, RELIABLE_ORDERED, 0, *m_clients.at(entity), false);
}


void NetworkSystem::requestENTT(SLNet::Packet* packet)
{
	entt::entity entity = entt::null;
	
	while (!m_registry->valid(entity))
		entity = m_registry->create();

	SLNet::RakNetGUID* clientGuid = nullptr;

	while (!clientGuid)
		clientGuid = new (std::nothrow) SLNet::RakNetGUID;

	*clientGuid = packet->guid;

	m_clients.emplace(entity, clientGuid);

	ECS_Log::s_consoleL->info("[NetworkSystem] NW_REQUEST_ENTT id: {:d}, guid: {}, {}:{:d}", entity, clientGuid->ToString(), packet->systemAddress.ToString(), packet->systemAddress.GetPortNetworkOrder());

	m_signalsManager->publish(Signals::NW_REQUEST_ENTT, entity);
}

void NetworkSystem::conectionLost(SLNet::Packet * packet)
{
	for (auto it = m_clients.cbegin(); it != m_clients.cend(); /*no auto increment*/)
	{
		if (it->second)
		{
			if (*it->second == packet->guid)
			{
				ECS_Log::s_consoleL->info("[NetworkSystem] NW_ENTT_LOST id: {:d}, guid: {}, {}:{:d}", it->first, it->second->ToString(), packet->systemAddress.ToString(), packet->systemAddress.GetPortNetworkOrder());
				m_signalsManager->publish(Signals::NW_ENTT_QUIT, it->first);

				delete it->second;

				it = m_clients.erase(it);
				break;
			}
		}
		else
		{
			ECS_Log::s_consoleL->warn("[NetworkSystem] conectionLost() it->second is nullptr. Erasing it from container.");
			it = m_clients.erase(it);
		}

		it++;
	}
}

void NetworkSystem::disconected(SLNet::Packet * packet)
{
	for (auto it = m_clients.cbegin(); it != m_clients.cend(); /*no auto increment*/)
	{
		if (it->second)
		{
			if (*it->second == packet->guid)
			{
				ECS_Log::s_consoleL->info("[NetworkSystem] NW_ENTT_QUIT id: {:d}, guid: {}, {}:{:d}", it->first, it->second->ToString(), packet->systemAddress.ToString(), packet->systemAddress.GetPortNetworkOrder());
				m_signalsManager->publish(Signals::NW_ENTT_QUIT, it->first);

				delete it->second;

				it = m_clients.erase(it);
				break;
			}
		}
		else
		{
			ECS_Log::s_consoleL->warn("[NetworkSystem] disconected() it->second is nullptr. Erasing it from container.");
			it = m_clients.erase(it);
		}

		it++;
	}
}

void NetworkSystem::receive(Signals signal, SLNet::BitStream* bsIn)
{
	if (!bsIn)
	{
		ECS_Log::s_consoleL->error("[NetworkSystem] receive() bsIn is nullptr. signal:{:d}", signal);
		return;
	}

	entt::entity entity = entt::null;

	bsIn->IgnoreBytes(sizeof(SLNet::MessageID));
	bsIn->Read(entity);

	if (m_registry->valid(entity))
		m_signalsManager->publish(signal, entity, bsIn);
	else
	{
		ECS_Log::s_consoleL->error("[NetworkSystem] receive() entity is not valid. entity:{:d}", entity);
	}
}

bool NetworkSystem::loadKeyPublic()
{
	std::ifstream is("public.key", std::ifstream::binary);
	if (is)
	{
		is.seekg(0, is.end);
		int length = is.tellg();
		is.seekg(0, is.beg);

		//char * buffer = new char[length];

		ECS_Log::s_consoleL->trace("[NetworkSystem] Reading public.key: {} characters... ", length);

		is.read(m_public_key, length);

		if (is)
			ECS_Log::s_consoleL->info("[NetworkSystem] public.key: All characters read successfully.");
		else
			ECS_Log::s_consoleL->error("[NetworkSystem] public.key: error: only {} could be read", is.gcount());
		is.close();

		// ...buffer contains the entire file...

		//delete[] buffer;
		return true;
	}

	return false;
}

bool NetworkSystem::loadKeyPrivate()
{
	std::ifstream is("private.key", std::ifstream::binary);
	if (is)
	{
		is.seekg(0, is.end);
		int length = is.tellg();
		is.seekg(0, is.beg);

		//char * buffer = new char[length];

		ECS_Log::s_consoleL->trace("[NetworkSystem] Reading private.key: {} characters... ", length);

		is.read(m_private_key, length);

		if (is)
			ECS_Log::s_consoleL->info("[NetworkSystem] private.key: All characters read successfully.");
		else
			ECS_Log::s_consoleL->error("[NetworkSystem] private.key: error: only {} could be read", is.gcount());
		is.close();

		// ...buffer contains the entire file...
		//delete[] buffer;
		return true;
	}

	return false;
}

bool NetworkSystem::generateKeys()
{
	cat::EasyHandshake::Initialize();
	cat::EasyHandshake handshake;

	if (!handshake.GenerateServerKey(m_public_key, m_private_key))
	{
		ECS_Log::s_consoleL->error("[NetworkSystem] generateKeys() Failed!");
		return false;
	}

	ECS_Log::s_consoleL->info("[NetworkSystem] generateKeys() Success.");

	return true;
}

bool NetworkSystem::writeKeyPublic()
{
	std::ofstream os("public.key", std::ofstream::binary);
	if (os)
	{
		os.write(m_public_key, sizeof(m_public_key));
		if (os)
		{
			ECS_Log::s_consoleL->info("[NetworkSystem] writeKeyPublic() Success.");
			os.close();
			return true;
		}
		else
			ECS_Log::s_consoleL->error("[NetworkSystem] writeKeyPublic() Error!");

		return false;
	}

	return false;
}

bool NetworkSystem::writeKeyPrivate()
{
	std::ofstream os("private.key", std::ofstream::binary);
	if (os)
	{
		os.write(m_private_key, sizeof(m_private_key));
		if (os)
		{
			ECS_Log::s_consoleL->info("[NetworkSystem] writeKeyPrivate() Success!");
			os.close();
			return true;
		}
		else
			ECS_Log::s_consoleL->error("[NetworkSystem] writeKeyPrivate() Error!");

		return false;
	}

	return false;
}

