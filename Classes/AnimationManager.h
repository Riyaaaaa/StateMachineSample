//
//  AnimationManager.h
//  test
//
//  Created by Atsumu Ono on 2016/06/23.
//
//

#ifndef AnimationManager_h
#define AnimationManager_h

#include "NPCCharacter.h"
#include "SingletonBase.hpp"
#include "cocos2d.h"

class AnimationManager : public SingletonBase<AnimationManager>{
public:
    friend SingletonBase<AnimationManager>;
    typedef NPCCharacter::key_t key_t;
    
    void addNPC(NPCCharacter* npc);
    void runAnimation(int ID, key_t key);
    void stopAnimation(int ID);
private:
    std::vector<std::shared_ptr<NPCCharacter>> _npcList;
};

#endif /* AnimationManager_h */
