#ifndef __TEST_SCENE_H__
#define __TEST_SCENE_H__

#include "cocos2d.h"
#include "NPCStateMachine.hpp"

class TestScene : public cocos2d::Scene
{
public:
    static TestScene* createScene();

    virtual bool init();
    CREATE_FUNC(TestScene);
    
private:
    CC_SYNTHESIZE(std::function<void()>, onTouched, OnTouched);
};

#endif // __HELLOWORLD_SCENE_H__
