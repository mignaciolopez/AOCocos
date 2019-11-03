#ifndef __NETWORK_SYSTEM_H__
#define __NETWORK_SYSTEM_H__

#include "ECS/ECSEngine.h"

#include "RakPeerInterface.h"
#include "slikenet/BitStream.h"
#include "RakNetTypes.h"  // MessageID
#include "slikenet/SecureHandshake.h"


namespace cocos2d
{
	class Director;
}

class NetworkSystem : public ECS::System
{
public:
	NetworkSystem();
	~NetworkSystem();

	virtual void Update() override;

	void mousePressed(int eid, cocos2d::Event* ccevnt, SLNet::BitStream* bs);

private:
	void receive(int evntid, SLNet::BitStream* bsIn);

	void conectionAccepted(SLNet::Packet* packet);

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
};

#endif // __NETWORK_SYSTEM_H__