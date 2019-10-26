#ifndef __MAIN_SCENE_H__
#define __MAIN_SCENE_H__

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
};

#endif // __MAIN_SCENE_H__
