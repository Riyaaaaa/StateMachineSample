//
//  GameManager.h
//  test
//
//  Created by Atsumu Ono on 2016/06/23.
//
//

#ifndef GameManager_h
#define GameManager_h

#include "GameManagerBase.hpp"
#include "TestScene.h"

class GameManager : public GameManagerBase<GameManager, TestScene> {
public:
    void runScene();
    void update(float dt);
    
private:
    std::shared_ptr<NPCStateMachine> girlStateMachine;
};

#endif /* GameManager_h */
