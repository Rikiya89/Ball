//
//  Ball.h
//  Ball
//
//  Created by Ricky O'kawa on 2023/01/08.
//
#pragma once //include gard
#include "ofMain.h"

class Ball {
private:
 glm::vec2 pos; //positon for a circle
    float radius; // radius for a circle


public:
    Ball(); //constructor
    void draw(); //draw a circle
    void setRadius(float radius);//radius setter
    float getRadius();//radius getter
    void setPos(glm::vec2 pos);//pos setter
    glm::vec2 getPos(); //pos getter
};

#ifndef Ball_h
#define Ball_h

#include <stdio.h>

#endif /* Ball_h */
