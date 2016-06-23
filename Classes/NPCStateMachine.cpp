//
//  NPCStateMachine.cpp
//  test
//
//  Created by Atsumu Ono on 2016/05/02.
//
//

#include "NPCStateMachine.hpp"

NPCStateMachine::NPCStateMachine(state_t* firstState, int ID) : _npcID(ID),  _elapsedTime(0), HFStateMachine<NPCStateMachine, event>(firstState){
}

void NPCStateMachine::update(float dt) {
    MachineBase::update(dt);
    
    _elapsedTime += dt;
    if(_elapsedTime >= CHANGE_DIRECTION_TIME) {
        this->dispatchEvent(eventAct::DirectionChange);
        _elapsedTime = 0;
    }
}

NPCStateMachine::walk::walk() {
    addAction(DirectionChange, new changeDirection);
    addTransition(SwitchState, new factoryDefault<NPCStateMachine, idle>);
}

void NPCStateMachine::walk::entry(const std::shared_ptr<context_t>& context) {
    auto manager = AnimationManager::getInstance();
    manager->runAnimation(context->_npcID, "FRONT");
}

void NPCStateMachine::walk::changeDirection::exe(const std::shared_ptr<context_t>& context) {
    std::uniform_int_distribution<int> dist(0, 3);
    std::string animation[] = {"FRONT", "LEFT", "RIGHT", "BACK"};
    auto manager = AnimationManager::getInstance();
    int index = dist(engine);
    manager->runAnimation(context->_npcID, animation[index]);
}

NPCStateMachine::idle::idle() {
    addTransition(SwitchState, new factoryDefault<NPCStateMachine, walk>);
}

void NPCStateMachine::idle::entry(const std::shared_ptr<context_t>& context) {
    auto manager = AnimationManager::getInstance();
    manager->stopAnimation(context->_npcID);
}