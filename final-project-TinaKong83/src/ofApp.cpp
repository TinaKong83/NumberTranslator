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

	//translate_button.setup("Translate the number");
	//translate_button.addListener(this, &ofApp::translatePressed);

	play_music.load("Jarico.mp3");
	play_music.setLoop(true);
	play_music.play();

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
	instruction.drawString("Please draw a number in the box below.", 90, 90);

	ofSetColor(255, 228, 196);
	ofFill();
	ofDrawRectangle(100, 100, 500, 500);

	ofSetColor(0, 0, 0);
	ofSetLineWidth(100000);
	ofFill();
	if (num_pts > 1) {
		for (int i = 0; i < num_pts - 1; i++) {
			ofLine(pts[i].x, pts[i].y, pts[i + 1].x, pts[i + 1].y);
		}
	}
	//translate_button.draw();

	ofSetColor(216, 191, 216);
	ofDrawRectRounded(english_button, 20);
	ofSetColor(75, 0, 130);
	english_label.drawString("ENGLISH", 790, 170);

	ofSetColor(216, 191, 216);
	ofDrawRectRounded(french_button, 20);

	ofSetColor(255, 215, 0);
	ofDrawRectRounded(button_divider, 20);

	if (user_image_entered) {
		user_drawing.load("UserDrawing.png");
		user_drawing.draw(0, 0);
	}
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
		//user_drawing.setImageType(OF_IMAGE_GRAYSCALE);
		user_drawing.resize(28, 28);
		user_drawing.save("UserDrawing.png");
		user_image_entered = true;

		user_drawing.setImageType(OF_IMAGE_GRAYSCALE);
		ofPixels image_pixels = user_drawing.getPixels();
		vector<vector<char>> converted_image = processImage(image_pixels);
		printCompositeImage(converted_image);

		vector<vector<int>> image_in_binary = ConvertImagetoBinary(converted_image);

		string training_images = "C:\\Users\\kongt\\final-project-TinaKong83\\final-project-TinaKong83\\bin\\data\\trainingimagesfinal";
		string training_labels = "C:\\Users\\kongt\\final-project-TinaKong83\\final-project-TinaKong83\\bin\\data\\traininglabelsfinal";

		cout << "creating vector of images" << endl;
		vector<vector<vector<int>>> vector_training_images = CreateVectorOfImages(training_images);
		cout << "creating vector of labels" << endl;

		vector<int> vector_training_labels = CreateVectorOfLabels(training_labels);

		cout << "creating feature probabilities" << endl;

		vector<vector<vector<double>>> vector_class_feature_probability =
			VectorClassFeatureProbability(vector_training_images, vector_training_labels);

		cout << "creating label priors" << endl;
		vector<double> vector_label_priors = VectorLabelPriors(vector_training_labels);

		vector<double> vector_posterior_probabilities = VectorPosteriorProbabilities(vector_label_priors, 
			vector_class_feature_probability, image_in_binary);

		int estimated_class = EstimateImageClass(vector_posterior_probabilities);
		cout << "hello" << endl;
		cout << estimated_class;
	}
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){
}

//--------------------------------------------------------------
vector<vector<char>> ofApp::processImage(ofPixels& image_pixels) {
	user_drawing.setImageType(OF_IMAGE_GRAYSCALE);

	vector<vector<char>> converted_image(28, vector<char>(28));
	//ofPixels& image_pixels = user_drawing.getPixels();

	for (int x = 0; x < 28; x++) {
		// Loop through every pixel row
		for (int y = 0; y < 28; y++) {
			// Use the formula to find the 1D location
			//int loc = x + y * 28;
			int loc = y + x * 28;
			if (image_pixels[loc] >= 0 && image_pixels[loc] <= 10) {
				converted_image.at(x).at(y) = '#';
			}
			else if (image_pixels[loc] >= 10 && image_pixels[loc] <= 120) {
				converted_image.at(x).at(y) = '+';
			}
			else {
				converted_image.at(x).at(y) = ' ';
			}
		}
	}
	//cout << "hello";
	return converted_image;
}

//--------------------------------------------------------------
void ofApp::printCompositeImage(vector<vector<char>>& converted_image) {
	for (int i = 0; i < converted_image.size(); i++) {
		for (int j = 0; j < converted_image.size(); j++) {
			cout << converted_image.at(i).at(j);
		}
		cout << endl;
	}
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
	//handleUserButton(x, y);
	if (english_button.inside(x, y)) {
		language_button_clicked = true;
		//default_english_button_color.set(0, 0, 0);
		//change button color?
	}

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
