//
//  Ball.cpp
//  Ball
//
//  Created by Ricky O'kawa on 2023/01/08.
//

#include "Ball.h"

Ball::Ball(){
    pos = glm::vec2(ofGetWidth()/2,ofGetHeight()/2);// setting for position
    radius = 100.0; //setting for radius
    speed = glm::vec2(0,0); //move speed
    phaseSpeed = ofRandom(0.1,0.5); //reducing speed
    phase = 0;
}

void Ball::draw(){
    ofSetColor(153, 153, 255,200);
    ofDrawCircle(pos.x, pos.y, strechedRadius);//apply reducing radius

    ofSetColor(255, 51, 255, 200);
    ofDrawCircle(pos.x, pos.y, radius/10.0);
    ofSetColor(255, 153, 255);
}

//animation for a circle
void Ball::update(){

    strechedRadius = radius + sin(phase)*radius/4;
    phase += phaseSpeed;
    if(phase > TWO_PI){
        phase -= TWO_PI;
    }

    pos += speed;
    //bounce a circle
    if(pos.x < radius || pos.x > ofGetWidth()-radius){
        speed.x *= -1;
    }
    if(pos.y < radius || pos.y > ofGetHeight()-radius){
        speed.y *= -1;
    }
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

//speed setter

void Ball::setSpeed(glm::vec2 _speed){
    speed = _speed;
}

//speed getter
glm::vec2 Ball::getSpeed(){
    return speed;
}
