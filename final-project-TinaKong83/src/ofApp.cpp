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
	num_pts = 0;
	ofSetWindowTitle("Final Project");
	ofBackground(255, 215, 0);
	instruction.load("Verdana.ttf", 20);
	
	if (true) {
		play_music.load("Jarico.mp3");
		play_music.play();
	}

}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
	/*tex1.draw(0, 0);
	tex2.draw(660, 0);*/
	ofSetColor(0, 0, 0);
	instruction.drawString("Please draw a number in the box below", 90, 90);

	ofSetColor(255, 228, 196);
	ofFill();
	ofDrawRectangle(100, 100, 500, 500);

	ofSetColor(0, 0, 0);
	ofSetLineWidth(10);
	if (num_pts > 1) {
		for (int i = 0; i < num_pts - 1; i++) {
			ofLine(pts[i].x, pts[i].y, pts[i + 1].x, pts[i + 1].y);
		}
	}
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
	if (num_pts < 3000) {
		pts[num_pts].x = x;
		pts[num_pts].y = y;
		num_pts++;
	}

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){
	num_pts = 0;
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
