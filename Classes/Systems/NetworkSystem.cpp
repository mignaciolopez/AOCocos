#include "NetworkSystem.h"

#include "Components/SpriteComponent.h"

#include "cocos2d.h"

NetworkSystem::NetworkSystem()
{
	cocos2d::log("%s Constructor", "[NETWORK SYSTEM]");

	m_componentManager = ECS::ECSEngine::GetInstance()->GetComponentManager();
	m_director = cocos2d::Director::getInstance();
	m_eventManager = ECS::ECSEngine::GetInstance()->getEventManager();

	m_peer = nullptr;

	m_peer = SLNet::RakPeerInterface::GetInstance();
	SLNet::StartupResult result = m_peer->Startup(1, &m_sd, 1);

	if (result != SLNet::StartupResult::RAKNET_STARTED)
		cocos2d::log("%s peer failed!", "[NETWORK SYSTEM]");

	m_online = false;

	if (SLNet::CONNECTION_ATTEMPT_STARTED != m_peer->Connect("127.0.0.1", 6000, 0, 0))
	{
		cocos2d::log("%s Conection attempt failed!", "[NETWORK SYSTEM]");
	}
	else
	{
		cocos2d::log("%s Conection attempt started.", "[NETWORK SYSTEM]");
	}

	m_eventManager->Subscribe(EVENTS::MOUSE_PRESSED, &NetworkSystem::mousePressed, this);
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
				m_serverGUID = packet->guid;
				m_online = true;
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
				cocos2d::log("%s Message with identifier %i has arrived.", "[NETWORK SYSTEM]", packet->data[0]);
				receive(&bsIn);
				break;
			}
		}
}

void NetworkSystem::mousePressed(unsigned int eid, unsigned int cid, cocos2d::Event * ccevnt)
{
	if (m_online && m_peer)
	{
		cocos2d::EventMouse* e = dynamic_cast<cocos2d::EventMouse*>(ccevnt);

		SLNet::BitStream bsOut;
		bsOut.Write((SLNet::MessageID)EVENTS::MOUSE_PRESSED);
		bsOut.Write(eid);
		bsOut.Write(cid);
		bsOut.Write(e->getMouseButton());
		bsOut.Write(e->getLocation().x);
		bsOut.Write(e->getLocation().y);
		m_peer->Send(&bsOut, HIGH_PRIORITY, RELIABLE_ORDERED, 0, m_serverGUID, false);
	}
}

void NetworkSystem::receive(SLNet::BitStream* bsIn)
{
	EVENTS evnt = EVENTS::FIRST;
	int eid = -1, cid = -1;

	bsIn->Read(evnt);
	bsIn->Read(eid);
	bsIn->Read(cid);
	m_eventManager->execute(evnt, eid, cid, nullptr);
}
