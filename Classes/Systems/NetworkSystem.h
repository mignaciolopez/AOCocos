#ifndef __NETWORK_SYSTEM_H__
#define __NETWORK_SYSTEM_H__

#include "ECS/ECS_Engine.h"

#include "RakPeerInterface.h"
#include "slikenet/BitStream.h"
#include "RakNetTypes.h"  // MessageID
#include "slikenet/SecureHandshake.h"


#define SERVER_ADDRESS "migna.dnsabr.com"
#define SERVER_PORT 6000

#include "cocos2d.h"
#include <ctime>

class NetworkSystem : public ECS::System
{
public:
	NetworkSystem();
	~NetworkSystem();

	virtual void update(float dt) override;

	void send(int eid, cocos2d::Event* ccevnt, SLNet::BitStream* bs);

private:
	void receive(int evntid, SLNet::BitStream* bsIn);

	void conectionAccepted(SLNet::Packet* packet);

	void updateUILatencylbl();

private:
	std::vector<ComponentType> m_compatibleComponents;

	ECS::EventManager* m_eventManager;
	cocos2d::Director* m_director;


	SLNet::RakPeerInterface* m_peer;
	SLNet::SocketDescriptor m_sd;

	SLNet::RakString m_accountName;
	SLNet::RakString m_passwd;

	SLNet::RakNetGUID m_serverGUID;

	bool m_online;

	clock_t m_clock_b;
	clock_t m_clock_e;
};

#endif // __NETWORK_SYSTEM_H__