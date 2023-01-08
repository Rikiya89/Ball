//
//  Ball.cpp
//  Ball
//
//  Created by Ricky O'kawa on 2023/01/08.
//

#include "Ball.h"

void Ball::draw(){
    ofSetColor(31, 63, 255);
    ofDrawCircle(ofGetWidth()/2, ofGetHeight()/2,100);//draw a circle in the center
}
