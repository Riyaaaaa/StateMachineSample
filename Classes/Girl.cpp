//
//  Girl.cpp
//  test
//
//  Created by Atsumu Ono on 2016/06/23.
//
//

#include "Girl.h"

USING_NS_CC;

Girl::Girl(int ID) : NPCCharacter(ID){
    Animation* animations[DIRECTION_SIZE];
    
    for (int y = 0; y < DIRECTION_SIZE; y++) {
        animations[y] = Animation::create();
        for (int x = 0; x < ANIMATION_NUMS; x++) {
            Rect rect(x * WIDTH_SIZE, y * HEIGHT_SIZE, WIDTH_SIZE, HEIGHT_SIZE);
            animations[y]->addSpriteFrame(SpriteFrame::create("girl.png", rect));
        }
        animations[y]->addSpriteFrame(SpriteFrame::create("girl.png", Rect(1 * WIDTH_SIZE, y * HEIGHT_SIZE, WIDTH_SIZE, HEIGHT_SIZE))); //使用した画像の事情により追加
        animations[y]->setDelayPerUnit(0.5f);
    }

    int i = 0;
    for(auto&& key : {"FRONT", "LEFT", "RIGHT", "BACK"}) {
        setAnimation(std::make_pair(key, animations[i]));
        i++;
    }
    
    setBaseImage(Sprite::create("girl.png", Rect(0, 0, WIDTH_SIZE, HEIGHT_SIZE)));
}