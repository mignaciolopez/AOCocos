#ifndef __MAIN_SCENE_H__
#define __MAIN_SCENE_H__

#include "Systems/IncludeSystems.h"

#include "Graphics/Graphics.h"
#include "Graphics/Interface.h"

namespace ECS
{
	class ECS_Engine;
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

	void mainSceneOnExit();

private:
	ECS::ECS_Engine* m_ECS_Engine;

	int m_cameraSystemID;
	int m_inputSystemID;
	int m_uiSystemID;
	int m_movementSystemID;
	int m_networkSystemID;
	int m_spawnSystemID;
	int m_animationSystemID;
	int m_mapSystemID;
	int m_audioSystemID;
	int m_combatSystemID;
	int m_graphicsSystemID;

	cocos2d::Layer* m_layer;
};

#endif // __MAIN_SCENE_H__
