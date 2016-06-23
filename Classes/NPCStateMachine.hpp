//
//  NPCStateMachine.hpp
//  test
//
//  Created by Atsumu Ono on 2016/05/02.
//
//

#ifndef NPCStateMachine_hpp
#define NPCStateMachine_hpp

#include "HFStateMachine.hpp"
#include "NPCCharacter.h"
#include "AnimationManager.h"
#include "cocos2d.h"

enum eventAct {
    DirectionChange,
    SwitchState
};

using event = EventBase<eventAct>;

class NPCStateMachine : public HFStateMachine<NPCStateMachine, event> {
public:
    typedef HFStateMachine<NPCStateMachine, event> MachineBase;
    typedef SMUtils<NPCStateMachine, event> Utils;
    typedef MachineBase::context_t  context_t;
    typedef MachineBase::state_t    state_t;
    typedef MachineBase::action_t   action_t;
    typedef MachineBase::factory_t  factory_t;
 
    explicit NPCStateMachine(state_t* firstState, int ID);
    
    void update(float dt);
    
    struct walk : state_t{
        void entry(const std::shared_ptr<context_t>& context) override;
        walk();
        
        struct changeDirection : action_t {
            void exe(const std::shared_ptr<context_t>& context) override;
            std::mt19937 engine;
        };
    private:
    };
    
    struct idle : state_t{
        void entry(const std::shared_ptr<context_t>& context) override;
        idle();
    private:
    };
    
private:
    static constexpr float CHANGE_DIRECTION_TIME = 5.0f;
    int _npcID;
    float _elapsedTime;
};

#endif /* NPCStateMachine_hpp */
