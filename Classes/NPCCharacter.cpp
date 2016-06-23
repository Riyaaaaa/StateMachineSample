//
//  NPCCharacter.cpp
//  test
//
//  Created by Atsumu Ono on 2016/06/23.
//
//

#include "NPCCharacter.h"

USING_NS_CC;

NPCCharacter::~NPCCharacter() {
    for(auto&& pair: _animationList){
        pair.second->release();
    }
}

void NPCCharacter::runAnimation(key_t key) {
    auto itr = _animationList.find(key);
    if(itr != _animationList.end()) {
        CCLOG("%s", key.c_str());
        _baseImage->stopAllActions();
        _baseImage->runAction(RepeatForever::create(Animate::create(itr->second)));
    }
}

void NPCCharacter::setAnimation(std::pair<std::string, cocos2d::Animation*> animation) {
    animation.second->retain();
    _animationList.insert(animation);
}

void NPCCharacter::stopAnimation() {
    _baseImage->stopAllActions();
}