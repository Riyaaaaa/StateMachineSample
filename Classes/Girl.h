//
//  Girl.h
//  test
//
//  Created by Atsumu Ono on 2016/06/23.
//
//

#ifndef Girl_h
#define Girl_h

#include "NPCCharacter.h"

class Girl : public NPCCharacter {
public:
    Girl(int ID);
    
    static constexpr int WIDTH_SIZE = 40;
    static constexpr int HEIGHT_SIZE = 60;
    static constexpr int ANIMATION_NUMS = 3;
    
    enum Direction {
        FRONT = 0,
        LEFT,
        RIGHT,
        BACK,
        DIRECTION_SIZE
    };
    
private:
};

#endif /* Girl_h */
