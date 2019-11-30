#include "NetworkSystem.h"

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

	m_clock_b = clock();
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
#if _DEBUG
	cocos2d::log("%s Destructor", "[NETWORK SYSTEM]");
#endif
}

void NetworkSystem::update(float dt)
{
	SLNet::BitStream fakeBs;

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
				updateUILatencylbl();
				break;
			case ID_NO_FREE_INCOMING_CONNECTIONS:
				cocos2d::log("%s ID_NO_FREE_INCOMING_CONNECTIONS", "[NETWORK SYSTEM]");
				updateUILatencylbl();
				break;
			case ID_DISCONNECTION_NOTIFICATION:
				cocos2d::log("%s ID_DISCONNECTION_NOTIFICATION", "[NETWORK SYSTEM]");
				m_online = false;
				updateUILatencylbl();
				break;
			case ID_CONNECTION_LOST:
				cocos2d::log("%s ID_CONNECTION_LOST", "[NETWORK SYSTEM]");
				m_online = false;
				updateUILatencylbl();
				//Go Back to LOGIN SCENE
				break;
			case ID_CONNECTION_ATTEMPT_FAILED:
				cocos2d::log("%s ID_CONNECTION_ATTEMPT_FAILED", "[NETWORK SYSTEM]");
				fakeBs.Write(10);
				fakeBs.Write(10);
				fakeBs.Write(Direction::South);
				fakeBs.Write(Genre::Female);
				fakeBs.Write(Race::Human);
				fakeBs.Write(Body::Body_Common_Clothes_Green);
				fakeBs.Write(Head::Head_Male_Human1);
				fakeBs.Write(Shield::Shield_Imperial);
				fakeBs.Write(Helmet::Helmet_Iron);
				fakeBs.Write(Weapon::Weapon_Sword_Long);
				m_eventManager->execute(EVENTS::MY_EID, 0, nullptr, &fakeBs);
				m_online = false;
				updateUILatencylbl();
				break;
			default:
				//cocos2d::log("%s Message with identifier %i has arrived.", "[NETWORK SYSTEM]", packet->data[0]);
				receive(packet->data[0], &bsIn);
				break;
			}
		}
	m_clock_e = clock();
	double elapsed_secs = double(m_clock_e - m_clock_b) / CLOCKS_PER_SEC;
	if (m_online && elapsed_secs > 1)
	{
		updateUILatencylbl();
		m_clock_b = clock();
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

void NetworkSystem::updateUILatencylbl()
{
	SLNet::BitStream bsOut;

	if (!m_peer || !m_online)
	{
		bsOut.Write(false);
		bsOut.Write(-1);
	}
	else
	{
		bsOut.Write(true);
		bsOut.Write(m_peer->GetLastPing(m_serverGUID));
	}

	m_eventManager->execute(EVENTS::UI_LBL_NETWORK, 0, nullptr, &bsOut);
}
