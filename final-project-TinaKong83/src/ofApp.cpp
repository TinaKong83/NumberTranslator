#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
	num_pts = 0;
	ofSetWindowTitle("Final Project");
	ofBackground(218, 165, 32);
	instruction.load("OstrichSans-Heavy.otf", 31);
	english_label.load("OstrichSans-Heavy.otf", 55);
	french_label.load("OstrichSans-Heavy.otf", 55);

	//translate_button.setup("Translate the number");
	//translate_button.addListener(this, &ofApp::translatePressed);

	//play_music.load("Jarico.mp3");
	//play_music.setLoop(true);
	//play_music.play();

	english_button.set(750, 100, 300, 150);
	french_button.set(1100, 100, 300, 150);

	if (user_image_entered) {
		cout << "USER IMAGE ENTERED" << endl;
		//user_drawing.draw(0, 0);
	}

	training_images = "C:\\Users\\kongt\\final-project-TinaKong83\\final-project-TinaKong83\\bin\\data\\trainingimagesfinal";
	training_labels = "C:\\Users\\kongt\\final-project-TinaKong83\\final-project-TinaKong83\\bin\\data\\traininglabelsfinal";
	cout << "creating vector of images" << endl;
	vector<vector<vector<int>>> vector_training_images = CreateVectorOfImages(training_images);
	
	cout << "creating vector of labels" << endl;
	vector_training_labels = CreateVectorOfLabels(training_labels);

	cout << "creating feature probabilities" << endl;
	vector_class_feature_probability = VectorClassFeatureProbability(vector_training_images, vector_training_labels);

	cout << "this part finished" << endl;
}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
	//set up canvas
	ofSetColor(0, 0, 0);
	instruction.drawString("Please draw a number in the box below.", 90, 90);

	ofSetColor(255, 228, 196);
	ofFill();
	ofDrawRectangle(100, 100, 500, 500);

	//english button
	ofSetColor(216, 191, 216);
	ofDrawRectRounded(english_button, 20);
	ofSetColor(default_english_button_color);
	english_label.drawString("ENGLISH", 790, 170);
	if (language_button_clicked && current_language == ENGLISH) {
		default_english_button_color.set(clicked_button_color);
	}

	//french button
	ofSetColor(216, 191, 216);
	ofDrawRectRounded(french_button, 20);
	ofSetColor(default_french_button_color);
	french_label.drawString("FRENCH", 1150, 170);
	if (language_button_clicked && current_language == FRENCH) {
		default_french_button_color.set(clicked_button_color);
	}

	ofSetColor(255, 215, 0);
	ofDrawRectRounded(button_divider, 20);

	if (current_state == CANVAS_STATE) {
		ofSetColor(0, 0, 0);
		ofSetLineWidth(100);
		ofFill();
		if (num_pts > 1) {
			for (int i = 0; i < num_pts - 1; i++) {
				ofLine(pts[i].x, pts[i].y, pts[i + 1].x, pts[i + 1].y);
			}
		}
	}
}

void ofApp::handleUserButton(int x, int y) {
	/*if (english_button.inside(x, y)) {
		language_button_clicked = true;
		default_english_button_color.set(clicked_button_color);
	}*/
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

		cout << "creating label priors" << endl;
		vector<double> vector_label_priors = VectorLabelPriors(vector_training_labels);

		vector<double> vector_posterior_probabilities = VectorPosteriorProbabilities(vector_label_priors, 
			vector_class_feature_probability, image_in_binary);

		estimated_class = EstimateImageClass(vector_posterior_probabilities);
		current_state = OUTPUT;
		cout << estimated_class;
		setLanguageAudio(estimated_class);
		current_state = CANVAS_STATE;

		//now write the code for outputting the correct audio
		
	}
}

//--------------------------------------------------------------
void ofApp::setLanguageAudio(int estimated_class) {
	if (estimated_class == 0) {
		if (current_language == ENGLISH) {
			translate_audio_file = "zero.mp3";
			translation_audio.load(translate_audio_file);
			translation_audio.play();
			cout << "estimated class audio playing is 0" << endl;
		}
	}
	else if (estimated_class == 1) {
		if (current_language == ENGLISH) {
			translate_audio_file = "one.mp3";
			translation_audio.load(translate_audio_file);
			translation_audio.play();
		}
	}
	else if (estimated_class == 2) {
		if (current_language == ENGLISH) {
			translate_audio_file = "two.mp3";
			translation_audio.load(translate_audio_file);
			translation_audio.play();
			cout << "testing";
		}
	}
	else if (estimated_class == 3) {
		if (current_language == ENGLISH) {
			translate_audio_file = "three.mp3";
			translation_audio.load(translate_audio_file);
			translation_audio.play();
			cout << "testing";
		}
	}
	else if (estimated_class == 4) {
		if (current_language == ENGLISH) {
			translate_audio_file = "four.mp3";
			translation_audio.load(translate_audio_file);
			translation_audio.play();
			cout << "testing";
		}
	}
	else if (estimated_class == 5) {
		if (current_language == ENGLISH) {
			translate_audio_file = "five.mp3";
			translation_audio.load(translate_audio_file);
			translation_audio.play();
			cout << "testing";
		}
	}
	else if (estimated_class == 6) {
		if (current_language == ENGLISH) {
			translate_audio_file = "six.mp3";
			translation_audio.load(translate_audio_file);
			translation_audio.play();
			cout << "testing";
		}
	}
	else if (estimated_class == 7) {
		if (current_language == ENGLISH) {
			translate_audio_file = "seven.mp3";
			translation_audio.load(translate_audio_file);
			translation_audio.play();
			cout << "testing";
		}
	}
	else if (estimated_class == 8) {
		if (current_language == ENGLISH) {
			translate_audio_file = "eight.mp3";
			translation_audio.load(translate_audio_file);
			translation_audio.play();
			cout << "testing";
		}
	}
	else if (estimated_class == 9) {
		if (current_language == ENGLISH) {
			translate_audio_file = "nine.mp3";
			translation_audio.load(translate_audio_file);
			translation_audio.play();
			cout << "testing";
		}
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
		resetButtonColors();
		current_language = ENGLISH;
		language_button_clicked = true;
		cout << "ENGLISH BUTTON CLICKED" << endl;
	}
	else if (french_button.inside(x, y)) {
		resetButtonColors();
		current_language = FRENCH;
		language_button_clicked = true;
		cout << "FRENCH BUTTON CLICKED" << endl;
	}

}

//--------------------------------------------------------------
void ofApp::resetButtonColors() {
	default_english_button_color = ofColor(75, 0, 130);
	default_french_button_color = ofColor(75, 0, 130);
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
