#include "NetworkSystem.h"

NetworkSystem::NetworkSystem(entt::registry* registry) : m_registry(registry)
{
	cocos2d::log("[NetworkSystem] Constructor");

	m_director = cocos2d::Director::getInstance();
	m_signalsManager = ECS::SignalsManager::getInstance();

	m_peer = nullptr;

	m_online = false;
	m_connecting = false;
	m_elapsedTime = 0.0f;

	m_signalsManager->connect<&NetworkSystem::send>(Signals::NW_SEND_SERVER, this);
	m_signalsManager->connect<&NetworkSystem::connect>(Signals::NW_CONNECT, this);
	m_signalsManager->connect<&NetworkSystem::disconnect>(Signals::NW_DISCONNECT, this);

	m_signalsManager->connect<&NetworkSystem::setLocalEntity>(Signals::NW_MY_ENTT, this);	
}

NetworkSystem::~NetworkSystem()
{
#if _DEBUG
	cocos2d::log("[NetworkSystem] Destructor");
#endif
	
	ECS::SignalsManager::getInstance()->disconnectAll(this);

	if (m_online && m_peer)
	{
		SLNet::BitStream bsOut;
		bsOut.Write((SLNet::MessageID)ID_DISCONNECTION_NOTIFICATION);
		m_peer->Send(&bsOut, LOW_PRIORITY, RELIABLE_ORDERED, 0, m_serverGUID, false);
	}

	if (m_peer)
	{
		m_peer->Shutdown(10000);
		m_peer->DestroyInstance(m_peer);
		m_peer = nullptr;
	}
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
				cocos2d::log("[NetworkSystem] ID_PUBLIC_KEY_MISMATCH");
				break;
			case ID_CONNECTION_REQUEST_ACCEPTED:
				conectionAccepted(packet);
				break;
			case ID_NO_FREE_INCOMING_CONNECTIONS:
				cocos2d::log("[NetworkSystem] ID_NO_FREE_INCOMING_CONNECTIONS");
				m_connecting = false;
				updateUILatencylbl();
				break;
			case ID_DISCONNECTION_NOTIFICATION:
				cocos2d::log("[NetworkSystem] ID_DISCONNECTION_NOTIFICATION");
				m_online = false;
				m_connecting = false;
				updateUILatencylbl();
				break;
			case ID_CONNECTION_LOST:
				cocos2d::log("[NetworkSystem] ID_CONNECTION_LOST");
				m_online = false;
				m_connecting = false;
				updateUILatencylbl();
				//Go Back to LOGIN SCENE
				break;
			case ID_CONNECTION_ATTEMPT_FAILED:
				cocos2d::log("[NetworkSystem] ID_CONNECTION_ATTEMPT_FAILED");
				if (!m_registry->valid(m_localEntt))
				{
					m_localEntt = m_registry->create();
					m_registry->destroy(m_localEntt);

					fakeBs.Write(1);
					fakeBs.Write(0);
					fakeBs.Write(0);
					fakeBs.Write(Directions::South);
					fakeBs.Write(Genres::Female);
					fakeBs.Write(Races::Human);
					fakeBs.Write(Bodies::Body_Human_Male);
					fakeBs.Write(Heads::Head_Human_Male_Brown);
					fakeBs.Write(Shields::NoShield);
					fakeBs.Write(Helmets::NoHelmet);
					fakeBs.Write(Weapons::NoWeapon);
					fakeBs.Write(100); //hp
					fakeBs.Write(100);	//hpMax
					fakeBs.Write(2200); //mp
					fakeBs.Write(2200);	//mpMax

					m_signalsManager->publish(Signals::NW_MY_ENTT, m_localEntt, &fakeBs);
				}
				

				fakeBs.Reset();
				fakeBs.Write(12);
				m_signalsManager->publish(Signals::AUDIO_SET_MUSIC_TRACK, m_localEntt, &fakeBs);

				m_online = false;
				m_connecting = false;
				break;
			default:
				//cocos2d::log("[NetworkSystem] Message with identifier %i has arrived.", packet->data[0]);
				receive(packet->data[0], &bsIn);
				break;
			}
		}
	m_elapsedTime += dt;

	if (m_elapsedTime > 1.0f)
	{
		updateUILatencylbl();
		m_elapsedTime = 0.0f;
	}
}

void NetworkSystem::send(entt::entity entity, SLNet::BitStream* bs)
{
	if (m_online && m_peer)
	{
		m_peer->Send(bs, HIGH_PRIORITY, RELIABLE_ORDERED, 0, m_serverGUID, false);
	}
}

void NetworkSystem::connect(entt::entity entity,  SLNet::BitStream* bs)
{
	if (m_connecting)
	{
		cocos2d::log("[NetworkSystem] Already Trying to Connect.");
		return;
	}
	if (m_online && m_peer)
	{
		cocos2d::log("[NetworkSystem] Conection attempt failed! (Already Connected)");
		return;
	}

	m_connecting = true;

	m_peer = SLNet::RakPeerInterface::GetInstance();
	SLNet::StartupResult result = m_peer->Startup(1, &m_sd, 1);

	if (result != SLNet::StartupResult::RAKNET_STARTED)
	{
		cocos2d::log("[NetworkSystem] peer failed!");
		m_connecting = false;
		return;
	}

	if (SLNet::CONNECTION_ATTEMPT_STARTED != m_peer->Connect(SERVER_ADDRESS, SERVER_PORT, 0, 0))
	{
		cocos2d::log("[NetworkSystem] Conection attempt failed!");
		m_connecting = false;
	}
	else
	{
		cocos2d::log("[NetworkSystem] Conection attempt started.");
	}
}

void NetworkSystem::disconnect(entt::entity entity,  SLNet::BitStream* bs)
{
	if (m_connecting)
	{
		cocos2d::log("[NetworkSystem] Closing connection in progress.");
		if (m_peer)
			m_peer->Shutdown(10000);
		return;
	}
	if (!m_online || !m_peer)
	{
		cocos2d::log("[NetworkSystem] Not Connected.");
		return;
	}

	cocos2d::log("[NetworkSystem] Notifying server about disconnection.");
	SLNet::BitStream bsOut;
	bsOut.Write((SLNet::MessageID)ID_DISCONNECTION_NOTIFICATION);
	m_peer->Send(&bsOut, LOW_PRIORITY, RELIABLE_ORDERED, 0, m_serverGUID, false);

	m_peer->Shutdown(10000);
}

void NetworkSystem::setLocalEntity(entt::entity entity,  SLNet::BitStream* bs)
{
	m_localEntt = entity;
}

void NetworkSystem::receive(int evntid, SLNet::BitStream* bsIn)
{
	entt::entity entity = entt::null;

	bsIn->IgnoreBytes(sizeof(SLNet::MessageID));
	bsIn->Read(entity);
	m_signalsManager->publish(static_cast<Signals>(evntid), entity, bsIn);
}

void NetworkSystem::conectionAccepted(SLNet::Packet* packet)
{
	m_serverGUID = packet->guid;
	m_online = true;
	m_connecting = false;

	cocos2d::log("[NetworkSystem] Connected.");
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

	m_signalsManager->publish(Signals::UI_LBL_NETWORK, m_localEntt, &bsOut);
}
