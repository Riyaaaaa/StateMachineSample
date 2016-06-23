//
//  NPCCharacter.h
//  test
//
//  Created by Atsumu Ono on 2016/06/23.
//
//

#ifndef NPCCharacter_h
#define NPCCharacter_h

#include "cocos2d.h"

class NPCCharacter {
public:
    typedef std::string key_t;
    NPCCharacter(int ID) noexcept : _id(ID)  {}
    virtual ~NPCCharacter();

    void runAnimation(key_t key);
    void setAnimation(std::pair<std::string, cocos2d::Animation*> animation);
    void stopAnimation();
    
private:
    CC_SYNTHESIZE_READONLY(int, _id, Id);
    CC_SYNTHESIZE(cocos2d::Sprite*, _baseImage, BaseImage);
    std::unordered_map<std::string, cocos2d::Animation*> _animationList;
};

#endif /* NPCCharacter_h */
