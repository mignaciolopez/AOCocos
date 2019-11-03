#ifndef __MAIN_SCENE_H__
#define __MAIN_SCENE_H__

#include "Components/SpriteComponent.h"
#include "Systems/RenderSystem.h"
#include "Systems/InputSystem.h"
#include "Systems/UISystem.h"
#include "Systems/MovementSystem.h"
#include "Systems/NetworkSystem.h"

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

	int m_renderSystemID;
	int m_inputSystemID;
	int m_uiSystemID;
	int m_movementSystemID;
	int m_networkSystemID;	
};

#endif // __MAIN_SCENE_H__
