#ifndef __MAIN_SCENE_H__
#define __MAIN_SCENE_H__

#include "ECS/ECS_Engine.h"

#include "Graphics/Interface.h"

class MainScene : public cocos2d::Scene
{
public:
    static cocos2d::Scene* createScene();

    virtual bool init() override;
    
    // a selector callback
    void menuCloseCallback(cocos2d::Ref* pSender);
    
    // implement the "static create()" method manually
    CREATE_FUNC(MainScene);

	virtual void update(float dt) override;

	void mainSceneOnExit();

private:
	ECS::ECS_Engine* m_ECS_Engine;
	ECS::SignalsManager* m_signalsManager;
	ECS::SystemManager* m_systemManager;
	entt::registry* m_registry;
};

#endif // !__MAIN_SCENE_H__
