#ifndef __NETWORK_SYSTEM_H__
#define __NETWORK_SYSTEM_H__

#include "RakPeerInterface.h"
#include "slikenet/BitStream.h"
#include "RakNetTypes.h"  // MessageID
#include "slikenet/SecureHandshake.h"

#include "ECS/SignalsManager.h"
#include "ECS/SignalsList.h"
#include "entt.hpp"

#include "ECS/iSystems/iSystem.h"

#include "ECS/ECS_Log.h"

#define log(x, y) std::cout << y << x << std::endl

class NetworkSystem : public ECS::iSystem
{
public:
	const ECS::iSystemTags _tag = ECS::iSystemTags::NetworkSystem_tag;
	NetworkSystem(entt::registry* registry);
	~NetworkSystem();

	virtual void update(double dt) override;

	void broadcast(entt::entity entity, SLNet::BitStream* bsOut);
	void sendClient(entt::entity entity, SLNet::BitStream* bsOut);

private:
	void requestENTT(SLNet::Packet* packet);
	void conectionLost(SLNet::Packet* packet);
	void disconected(SLNet::Packet * packet);
	void receive(Signals signal, SLNet::BitStream* bsIn);

	bool loadKeyPublic();
	bool loadKeyPrivate();

	bool generateKeys();

	bool writeKeyPublic();
	bool writeKeyPrivate();

private:
	std::shared_ptr<ECS::SignalsManager> m_signalsManager;

	entt::registry* m_registry;

	SLNet::RakPeerInterface* m_peer;

	bool m_online;

	std::map<entt::entity, SLNet::RakNetGUID*> m_clients;

	char m_public_key[cat::EasyHandshake::PUBLIC_KEY_BYTES];
	char m_private_key[cat::EasyHandshake::PRIVATE_KEY_BYTES];
};

#endif // __NETWORK_SYSTEM_H__