#include "TestScene.h"

USING_NS_CC;

TestScene* TestScene::createScene()
{
    auto scene = TestScene::create();
    return scene;
}

bool TestScene::init()
{
    if ( !Scene::init() )
    {
        return false;
    }
    
    auto listener = EventListenerTouchOneByOne::create();
    listener->onTouchBegan = [=](Touch*, Event*){
        if(onTouched) onTouched();
        return true;
    };
    getEventDispatcher()->addEventListenerWithSceneGraphPriority(listener, this);
    
    return true;
}