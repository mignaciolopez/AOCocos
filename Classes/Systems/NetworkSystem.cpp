#include "NetworkSystem.h"

#include "Components/SpriteComponent.h"

#include "cocos2d.h"

NetworkSystem::NetworkSystem()
{
	cocos2d::log("%s Constructor", "[NETWORK SYSTEM]");

	//m_componentManager = ECS::ECS_Engine::getInstance()->GetComponentManager();
	m_director = cocos2d::Director::getInstance();
	m_eventManager = ECS::ECS_Engine::getInstance()->getEventManager();

	m_peer = nullptr;

	m_peer = SLNet::RakPeerInterface::GetInstance();
	SLNet::StartupResult result = m_peer->Startup(1, &m_sd, 1);

	if (result != SLNet::StartupResult::RAKNET_STARTED)
		cocos2d::log("%s peer failed!", "[NETWORK SYSTEM]");

	m_online = false;

	if (SLNet::CONNECTION_ATTEMPT_STARTED != m_peer->Connect(SERVER_ADDRESS, SERVER_PORT, 0, 0))
	{
		cocos2d::log("%s Conection attempt failed!", "[NETWORK SYSTEM]");
	}
	else
	{
		cocos2d::log("%s Conection attempt started.", "[NETWORK SYSTEM]");
	}

	m_eventManager->Subscribe(EVENTS::SEND_SERVER, &NetworkSystem::send, this);
}

NetworkSystem::~NetworkSystem()
{
	if (m_online && m_peer)
	{
		SLNet::BitStream bsOut;
		bsOut.Write((SLNet::MessageID)ID_DISCONNECTION_NOTIFICATION);
		m_peer->Send(&bsOut, LOW_PRIORITY, RELIABLE_ORDERED, 0, m_serverGUID, false);
	}

	if (m_peer)
	{
		m_peer->Shutdown(10000);
	}
	cocos2d::log("%s Destructor", "[NETWORK SYSTEM]");
}

void NetworkSystem::Update()
{
	SLNet::Packet* packet;
	if (m_peer)
		for (packet = m_peer->Receive(); packet; m_peer->DeallocatePacket(packet), packet = m_peer->Receive())
		{
			SLNet::BitStream bsIn(packet->data, packet->length, false);
			switch (packet->data[0])
			{
			case ID_PUBLIC_KEY_MISMATCH:
				cocos2d::log("%s ID_PUBLIC_KEY_MISMATCH", "[NETWORK SYSTEM]");
				break;
			case ID_CONNECTION_REQUEST_ACCEPTED:
				conectionAccepted(packet);
				break;
			case ID_NO_FREE_INCOMING_CONNECTIONS:
				cocos2d::log("%s ID_NO_FREE_INCOMING_CONNECTIONS", "[NETWORK SYSTEM]");
				break;
			case ID_DISCONNECTION_NOTIFICATION:
				cocos2d::log("%s ID_DISCONNECTION_NOTIFICATION", "[NETWORK SYSTEM]");
				break;
			case ID_CONNECTION_LOST:
				cocos2d::log("%s ID_CONNECTION_LOST", "[NETWORK SYSTEM]");
				//Go Back to LOGIN SCENE
				break;
			case ID_CONNECTION_ATTEMPT_FAILED:
				cocos2d::log("%s ID_CONNECTION_ATTEMPT_FAILED", "[NETWORK SYSTEM]");
				break;
			default:
				//cocos2d::log("%s Message with identifier %i has arrived.", "[NETWORK SYSTEM]", packet->data[0]);
				receive(packet->data[0], &bsIn);
				break;
			}
		}
}

void NetworkSystem::send(int eid, cocos2d::Event* ccevnt, SLNet::BitStream* bs)
{
	if (m_online && m_peer)
	{
		m_peer->Send(bs, HIGH_PRIORITY, RELIABLE_ORDERED, 0, m_serverGUID, false);
	}
}

void NetworkSystem::receive(int evntid, SLNet::BitStream* bsIn)
{
	int eid = -1;

	bsIn->IgnoreBytes(sizeof(SLNet::MessageID));
	bsIn->Read(eid);
	m_eventManager->execute(static_cast<EVENTS>(evntid), eid, nullptr, bsIn);
}

void NetworkSystem::conectionAccepted(SLNet::Packet* packet)
{
	m_serverGUID = packet->guid;
	m_online = true;

	SLNet::BitStream bsOut;
	bsOut.Write((SLNet::MessageID)EVENTS::REQUEST_EID);
	m_peer->Send(&bsOut, HIGH_PRIORITY, RELIABLE_ORDERED, 0, m_serverGUID, false);
}
