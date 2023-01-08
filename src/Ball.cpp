//
//  Ball.cpp
//  Ball
//
//  Created by Ricky O'kawa on 2023/01/08.
//

#include "Ball.h"

Ball::Ball(){
    pos = glm::vec2(400,300);// setting for position
    radius = 80.0; //setting for radius
}

void Ball::draw(){
    ofSetColor(31, 63, 255,100);
    ofDrawCircle(pos.x, pos.y, radius);//draw two circle
    ofSetColor(255, 0, 0, 200);
    ofDrawCircle(pos.x, pos.y, radius/10.0);
    ofSetColor(31, 63, 255);
}

//pos setter
void Ball::setPos(glm::vec2 _pos){
    pos = _pos;
}

//pos getter
glm::vec2 Ball::getPos() {
    return pos;
}

//radius setter
void Ball::setRadius(float _radius) {
    radius = _radius;
}

//radius getter
float Ball::getRadius(){
    return radius;
}
