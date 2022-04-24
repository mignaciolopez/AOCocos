#ifndef NETWORK_SYSTEM_H__
#define NETWORK_SYSTEM_H__

#include "Components/IncludeComponents.h"

#include "RakPeerInterface.h"
#include "slikenet/BitStream.h"
#include "RakNetTypes.h"  // MessageID
#include "slikenet/SecureHandshake.h"

#if _DEBUG
#define SERVER_ADDRESS "127.0.0.1"
#else
#define SERVER_ADDRESS "127.0.0.1"
#endif
#define SERVER_PORT 6000

#include "cocos2d.h"
#include "ECS/SignalsManager.h"
#include "entt.hpp"
#include "ECS/iSystems/iSystem.h"

class NetworkSystem : public ECS::iSystem
{
public:
	const ECS::iSystemTags _tag = ECS::iSystemTags::NetworkSystem_tag;
	NetworkSystem(entt::registry* registry);
	~NetworkSystem();

	virtual void update(float dt) override;

	void send(entt::entity entity, SLNet::BitStream* bs);

	void connect(entt::entity entity, SLNet::BitStream* bs);
	void disconnect(entt::entity entity, SLNet::BitStream* bs);

	void setLocalEntity(entt::entity entity, SLNet::BitStream* bs);

private:
	void receive(int evntid, SLNet::BitStream* bsIn);

	void conectionAccepted(SLNet::Packet* packet);

	void updateUILatencylbl();

private:
	ECS::SignalsManager* m_signalsManager;
	cocos2d::Director* m_director;

	entt::registry* m_registry;
	entt::entity m_localEntt = entt::null;

	SLNet::RakPeerInterface* m_peer;
	SLNet::SocketDescriptor m_sd;

	SLNet::RakString m_accountName;
	SLNet::RakString m_passwd;

	SLNet::RakNetGUID m_serverGUID;

	bool m_online;
	bool m_connecting;

	float m_elapsedTime;
};

#endif // !NETWORK_SYSTEM_H__