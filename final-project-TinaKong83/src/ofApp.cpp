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
	ofBackground(218, 165, 32);
	instruction.load("OstrichSans-Heavy.otf", 31);
	english_label.load("OstrichSans-Heavy.otf", 55);
	french_label.load("OstrichSans-Heavy.otf", 55);

	translate_button.setup("Translate the number");
	translate_button.addListener(this, &ofApp::translatePressed);

	play_music.load("Jarico.mp3");
	play_music.setLoop(true);
	play_music.play();
	
	//pineapple shoudl appear
	image_display.loadImage("pineapple.jpg");

	english_button.set(750, 100, 300, 150);
	//button_divider.set(1000, 100, 40, 150);
	french_button.set(1100, 100, 300, 150);
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
	ofSetLineWidth(100);
	ofFill();
	if (num_pts > 1) {
		for (int i = 0; i < num_pts - 1; i++) {
			ofLine(pts[i].x, pts[i].y, pts[i + 1].x, pts[i + 1].y);
		}
	}
	translate_button.draw();

	ofSetColor(216, 191, 216);
	ofDrawRectRounded(english_button, 20);
	ofSetColor(75, 0, 130);
	english_label.drawString("ENGLISH", 790, 170);

	ofSetColor(216, 191, 216);
	ofDrawRectRounded(french_button, 20);


	ofSetColor(255, 215, 0);
	ofDrawRectRounded(button_divider, 20);


	/*user_drawing.loadImage("UserDrawing.png");
	user_drawing.draw(150, 150, 588, 588);*/
}

void ofApp::handleUserButton(int x, int y) {
	if (english_button.inside(x, y)) {
		language_button_clicked = true;
		default_english_button_color.set(clicked_button_color);
	}
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
	if (key == OF_KEY_RETURN) {
		user_drawing.grabScreen(100, 100, 500, 500);
		user_drawing.setImageType(OF_IMAGE_GRAYSCALE);
		user_drawing.resize(28, 28);
		user_drawing.save("UserDrawing.png");
		//user_drawing.loadImage("UserDrawing.png");
		//user_drawing.draw(150, 150, 588, 588);
	}
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::translatePressed() {
	//image_display.loadImage("UserDrawing.png");
	//image_display.draw(100, 100, 500, 500);
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
	handleUserButton(x, y);

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
