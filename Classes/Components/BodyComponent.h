#ifndef __BODY_COMPONENT_H__
#define __BODY_COMPONENT_H__

#include "ECS/Components/Component.h"

class BodyComponent : public ECS::Component
{
public:
	BodyComponent();
	~BodyComponent();

	cocos2d::Sprite* _bodySprite;
	const ComponentType _type = ComponentType::BODYCOMPONENT;
};

#endif // __BODY_COMPONENT_H__