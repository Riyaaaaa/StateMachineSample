//
//  AnimationManager.cpp
//  test
//
//  Created by Atsumu Ono on 2016/06/23.
//
//

#include "AnimationManager.h"

void AnimationManager::addNPC(NPCCharacter* npc) {
    _npcList.push_back( std::shared_ptr<NPCCharacter>(npc) );
}

void AnimationManager::runAnimation(int ID, key_t key) {
    auto itr = std::find_if(_npcList.begin(), _npcList.end(), [=](const std::shared_ptr<NPCCharacter>& npc){ return npc->getId() == ID; });
    
    if(itr != _npcList.end()) {
        (*itr)->runAnimation(key);
    }
}

void AnimationManager::stopAnimation(int ID) {
    auto itr = std::find_if(_npcList.begin(), _npcList.end(), [=](const std::shared_ptr<NPCCharacter>& npc){ return npc->getId() == ID; });
    
    if(itr != _npcList.end()) {
        (*itr)->stopAnimation();
    }
}