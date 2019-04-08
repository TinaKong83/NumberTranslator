#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
	/*pixels1.allocate(640, 480, OF_IMAGE_COLOR);
	pixels1.set(0);
	pixels2 = pixels1;
	pixels2.setColor(10, 10, ofColor(255, 255, 255));

	tex1.allocate(640, 480, GL_RGB);
	tex2.allocate(640, 480, GL_RGB);
	tex1.loadData(pixels1);
	tex2.loadData(pixels2);
	*/
	ofSetWindowTitle("Final Project");
	ofBackground(144, 238, 144);
	instruction.load("Verdana.ttf", 20);
	
	play_music.load("Jarico.mp3");
	play_music.play();
}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
	/*tex1.draw(0, 0);
	tex2.draw(660, 0);*/
	ofSetColor(0, 0, 0);
	instruction.drawString("Please draw a number", 90, 90);
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

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
