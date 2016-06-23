//
//  GameManagerBase.hpp
//  SlotMachine
//
//  Created by Atsumu Ono on 2016/04/07.
//
//

#ifndef GameManagerBase_hpp
#define GameManagerBase_hpp

#include "cocos2d.h"
#include "SingletonBase.hpp"

/**
 *  @class GameManagerBase
 *  @brief ゲームマネージャのベースクラスです
 */
template<class Manager, class Scene_t>
class GameManagerBase : public SingletonBase<Manager>{
public:
    void runScene();
    void update(float){};
    
    Scene_t* getScene() {
        return _scene;
    }
    
protected:
    ~GameManagerBase() = default;
    GameManagerBase() {
    }
    void onExitScene();
    Scene_t* _scene;
};

/**
 *  シーンをランします
 */
template<class Manager, class Scene_t>
void GameManagerBase<Manager, Scene_t>::runScene() {
    _scene = Scene_t::createScene();
    
    _scene->setOnExitCallback(CC_CALLBACK_0(GameManagerBase<Manager, Scene_t>::onExitScene, this));
    
    auto scheduler = cocos2d::Director::getInstance()->getScheduler();
    scheduler->schedule(CC_CALLBACK_1(Manager::update, SingletonBase<Manager>::_singletonInstancePointer), this, 0.0f, false, "SCENE");
    
    cocos2d::Director::getInstance()->replaceScene(_scene);
}

/**
 *  シーンがイグジットした際に呼ばれます
 */
template<class Manager, class Scene_t>
void GameManagerBase<Manager, Scene_t>::onExitScene() {
    _scene = nullptr;
    auto scheduler = cocos2d::Director::getInstance()->getScheduler();
    scheduler->unscheduleAllForTarget(this);
    Manager::destroyInstance();
}

#endif /* GameManagerBase_hpp */
