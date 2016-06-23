//
//  GameManager.cpp
//  test
//
//  Created by Atsumu Ono on 2016/06/23.
//
//

#include "GameManager.h"
#include "AnimationManager.h"
#include "Girl.h"

void GameManager::runScene() {
    GameManagerBase<GameManager, TestScene>::runScene();
    auto size = cocos2d::Director::getInstance()->getWinSize();
    auto animationManager = AnimationManager::getInstance();
    
    _scene->setOnTouched([=](){
        girlStateMachine->dispatchEvent(eventAct::SwitchState);
    });
    
    Girl* girl = new Girl(0);
    _scene->addChild(girl->getBaseImage());
    girl->getBaseImage()->setPosition(size / 2.0f);
    animationManager->addNPC(girl);
    
    girlStateMachine = NPCStateMachine::create(new NPCStateMachine::walk, 0);
}

void GameManager::update(float dt) {
    girlStateMachine->update(dt);
}