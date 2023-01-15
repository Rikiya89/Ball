#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofBackground(0, 0, 0);
    ofSetCircleResolution(32);
    ofEnableAlphaBlending();
    ofSetFrameRate(30);

    //change a circle position
    //    myBall.setPos(glm::vec2(300,300));
    //    myBall.setRadius(100);
    //    myBall.setSpeed(glm::vec2(3,5));
}

//--------------------------------------------------------------
void ofApp::update(){
    //loop instance
    for (int i = 0; i < balls.size(); i++) {
        balls[i].update();
    }
}

//--------------------------------------------------------------
void ofApp::draw(){
    //loop draw
    for (int i = 0; i < balls.size(); i++) {
        balls[i].draw();
    }
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){
    switch (key){ //Recognise to type key
        case 'f': //if type 'f' key change to screen size to maximum
            ofToggleFullscreen();
            break;
        case 'r': //if type 'r' key delete to all of cirecles
            balls.clear();
    }

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){
    int bSize = balls.size(); //balls values inside to bSize

    if (bSize < 1) {// If there is no ball, add a new ball
        Ball b = Ball();//Instancing
        float radius = ofGetHeight()/3;
        b.setRadius(radius);//setting scale
        b.setSpeed(glm::vec2(3,3));//setting speed 0
        b.setPos(glm::vec2(mouseX,mouseY));//position setting is center
        balls.push_back(b);//Dynamic array balls is adding instancing b
    }

    //If there is one circle on screen, when it click a circle to divide four
    for (int i =0; i<bSize; i++) {//loop value number
        glm::vec2 pos = balls[i].getPos();//assignment to pos value
        float radius = balls[i].getRadius();//assignment to circle scale
        float dist = ofDist(pos.x,pos.y, mouseX, mouseY);//measure mouse position and circle position

        //circle 01 divide a circle
        if(dist < radius) {
            balls[i].setRadius(radius*0.6);
            balls[i].setPos(glm::vec2(pos.x-radius*0.9,pos.y));
            balls[i].setSpeed(glm::vec2(ofRandom(-radius/150,radius/150),ofRandom(-radius/150,radius/150)));

            //circle 02 position right
            Ball b1 = Ball();
            b1.setRadius(radius*0.6);
            b1.setPos(glm::vec2(pos.x+radius*0.9,pos.y));
            b1.setSpeed(glm::vec2 (ofRandom(-radius/150,radius/150),ofRandom(-radius/150,radius/150)));
            balls.push_back(b1);

            //circle 03 position top
            Ball b2 = Ball();
            b2.setRadius(radius*0.6);
            b2.setPos(glm::vec2(pos.x,pos.y-radius*0.9));
            b2.setSpeed(glm::vec2 (ofRandom(-radius/150,radius/150),ofRandom(-radius/150,radius/150)));
            balls.push_back(b2);

            //circle 04 position bottom
            Ball b3 = Ball();
            b3.setRadius(radius*0.6);
            b3.setPos(glm::vec2(pos.x,pos.y+radius*0.9));
            b3.setSpeed(glm::vec2 (ofRandom(-radius/150,radius/150),ofRandom(-radius/150,radius/150)));
            balls.push_back(b2);
        }
    }
}


//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){

}
