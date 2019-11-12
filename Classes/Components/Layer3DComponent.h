#ifndef __LAYER3D_COMPONENT_H__
#define __LAYER3D_COMPONENT_H__

#include "ECS/Components/Component.h"

#include "cocos2d.h"

class Layer3DComponent : public ECS::Component
{
public:
	Layer3DComponent()
	{
		cocos2d::log("%s Constructor", "[LAYER3D COMPONENT]");

		m_layer3D = nullptr;
		m_layer3D = cocos2d::Layer::create();
		m_layer3D->retain();
		m_layer3D->setCameraMask(static_cast<int>(
			cocos2d::CameraFlag::USER1));
	}
	~Layer3DComponent()
	{
		if (m_layer3D)
			if (m_layer3D->getReferenceCount() > 0)
				m_layer3D->release();
		cocos2d::log("%s Destructor", "[LAYER3D COMPONENT]");
	}

	virtual ComponentType getType() override
	{
		return m_type;
	}

	virtual cocos2d::Layer* getLayer() override
	{
		return m_layer3D;
	}

	virtual void setLayer(cocos2d::Layer* layer3D) override
	{
		m_layer3D = layer3D;
	}

private:
	const ComponentType m_type = ComponentType::LAYER3D;

	cocos2d::Layer* m_layer3D;

};
#endif // !__LAYER3D_COMPONENT_H__
