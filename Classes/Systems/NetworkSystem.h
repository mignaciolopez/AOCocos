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

	void mousePressed(unsigned int eid, unsigned int cid, cocos2d::Event* ccevnt);

private:
	void receive(SLNet::BitStream* bsIn);

private:
	std::vector<ComponentType> m_compatibleComponents;

	ECS::ComponentManager* m_componentManager;
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