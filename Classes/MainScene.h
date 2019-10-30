#ifndef __MAIN_SCENE_H__
#define __MAIN_SCENE_H__

#include "Components/SpriteComponent.h"
#include "Systems/RenderSystem.h"
#include "Systems/InputSystem.h"

namespace ECS
{
	class ECSEngine;
}

#include "cocos2d.h"

class MainScene : public cocos2d::Scene
{
public:
    static cocos2d::Scene* createScene();

    virtual bool init();

    // implement the "static create()" method manually
    CREATE_FUNC(MainScene);

	virtual void update(float dt) override;



private:
	ECS::ECSEngine* m_ECSEngine;

	unsigned int m_renderSystemID;
	unsigned int m_inputSystemID;
	unsigned int m_bodyComponentID;
	unsigned int m_headComponentID;
	
};

#endif // __MAIN_SCENE_H__
