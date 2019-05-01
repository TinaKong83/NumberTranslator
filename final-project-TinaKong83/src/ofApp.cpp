#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
	num_pts_ = 0;
	ofSetWindowTitle("Final Project");
	ofBackground(170, 189, 171);
	loadFonts();

	english_button_.set(750, 100, 300, 150);
	french_button_.set(1100, 100, 300, 150);
	spanish_button_.set(750, 300, 300, 150);
	chinese_button_.set(1100, 300, 300, 150);
	
	/*
	training_images = 
		"C:\\Users\\kongt\\final-project-TinaKong83\\final-project-TinaKong83\\bin\\data\\trainingimagesfinal";
	training_labels = 
		"C:\\Users\\kongt\\final-project-TinaKong83\\final-project-TinaKong83\\bin\\data\\traininglabelsfinal";
	vector<vector<vector<int>>> vector_training_images = CreateVectorOfImages(training_images);
	vector_training_labels = CreateVectorOfLabels(training_labels);
	vector_class_feature_probability = VectorClassFeatureProbability(vector_training_images, vector_training_labels);
	*/
}

//--------------------------------------------------------------
void ofApp::loadFonts() {
	instruction_.load("JaneRoe-Light.ttf", 31);
	english_label_.load("OstrichSans-Heavy.otf", 55);
	french_label_.load("OstrichSans-Heavy.otf", 55);
	spanish_label_.load("OstrichSans-Heavy.otf", 55);
	chinese_label_.load("OstrichSans-Heavy.otf", 55);
	digit_estimate_.load("JaneRoe-Light.ttf", 31);
	character_label_.load("JaneRoe-Light.ttf", 31);
	pronunciation_label_.load("JaneRoe-Light.ttf", 31);
	translation_label_.load("JaneRoe-Light.ttf", 31);
	pronunciation_output_.load("happy-times-at-the-ikob.otf", 50);
	translation_output_.load("happy-times-at-the-ikob.otf", 50);
}

//--------------------------------------------------------------
void ofApp::draw(){
	ofSetColor(0, 0, 0);
	instruction_.drawString("Please draw a number in the box below", 80, 80);
	translation_label_.drawString("Translation: ", 790, 600);
	pronunciation_label_.drawString("Pronunciation: ", 790, 800);
	character_label_.drawString("Character: ", 1300, 600);

	ofSetColor(243, 219, 172);
	ofFill();
	canvas_.set(100, 100, 500, 500);
	ofDrawRectangle(canvas_);

	setupEnglishButton();
	setupFrenchButton();
	setupSpanishButton();
	setupChineseButton();

	if (current_state_ == CANVAS_STATE) {
		ofSetColor(0, 0, 0);
		ofSetLineWidth(100);
		ofFill();
		if (num_pts_ > 1) {
			for (int i = 0; i < num_pts_ - 1; i++) {
				ofLine(pts[i].x, pts[i].y, pts[i + 1].x, pts[i + 1].y);
			}
		}
	}
	if (image_classified_) {
		translateClassifiedImage();
	}
}

//--------------------------------------------------------------
void ofApp::setupEnglishButton() {
	ofSetColor(216, 191, 216);
	ofDrawRectRounded(english_button_, 20);
	ofSetColor(default_english_button_color_);
	english_label_.drawString("ENGLISH", 790, 170);

	//Allows button text color to change when button is clicked
	if (language_button_clicked_ && current_language_ == ENGLISH) {
		default_english_button_color_.set(clicked_button_color_);
	}
}
//--------------------------------------------------------------
void ofApp::setupFrenchButton() {
	ofSetColor(216, 191, 216);
	ofDrawRectRounded(french_button_, 20);
	ofSetColor(default_french_button_color_);
	french_label_.drawString("FRENCH", 1150, 170);

	if (language_button_clicked_ && current_language_ == FRENCH) {
		default_french_button_color_.set(clicked_button_color_);
	}
}
//--------------------------------------------------------------
void ofApp::setupSpanishButton() {
	ofSetColor(216, 191, 216);
	ofDrawRectRounded(spanish_button_, 20);
	ofSetColor(default_spanish_button_color_);
	spanish_label_.drawString("SPANISH", 790, 370);

	if (language_button_clicked_ && current_language_ == SPANISH) {
		default_spanish_button_color_.set(clicked_button_color_);
	}
}
//--------------------------------------------------------------
void ofApp::setupChineseButton() {
	ofSetColor(216, 191, 216);
	ofDrawRectRounded(chinese_button_, 20);
	ofSetColor(default_chinese_button_color_);
	chinese_label_.drawString("CHINESE", 1150, 370);

	if (language_button_clicked_ && current_language_ == CHINESE) {
		default_chinese_button_color_.set(clicked_button_color_);
	}
}

//--------------------------------------------------------------
void ofApp::translateClassifiedImage() {
	if (estimated_class_ == 0) {
		translation_output_.drawString("Zero", 1020, 600);
		if (current_language_ == CHINESE) {
			chinese_char_.load("ling_image.png");
			chinese_char_.draw(1500, 500);
			ofSetColor(0, 0, 0);
			pronunciation_output_.drawString("Ling", 1020, 800);
		}
		else if (current_language_ == SPANISH) {
			pronunciation_output_.drawString("Cero", 1020, 800);
		}
		else if (current_language_ == FRENCH) {
			pronunciation_output_.drawString("Zero", 1020, 800);
		}
	} else if (estimated_class_ == 1) {
		translation_output_.drawString("One", 1020, 600);
		if (current_language_ == CHINESE) {
			chinese_char_.load("yi_image.png");
			chinese_char_.draw(1500, 500);
			ofSetColor(0, 0, 0);
			pronunciation_output_.drawString("Yi", 1020, 800);
		}
		else if (current_language_ == SPANISH) {
			pronunciation_output_.drawString("Uno", 1020, 800);
		}
		else if (current_language_ == FRENCH) {
			pronunciation_output_.drawString("Un", 1020, 800);
		}
	} else if (estimated_class_ == 2) {
		translation_output_.drawString("Two", 1020, 600);
		if (current_language_ == CHINESE) {
			chinese_char_.load("er_image.png");
			chinese_char_.draw(1500, 500);
			ofSetColor(0, 0, 0);
			pronunciation_output_.drawString("Er", 1020, 800);
		}
		else if (current_language_ == SPANISH) {
			pronunciation_output_.drawString("Dos", 1020, 800);
		}
		else if (current_language_ == FRENCH) {
			pronunciation_output_.drawString("Deux", 1020, 800);
		}
	} else if (estimated_class_ == 3) {
		translation_output_.drawString("Three", 1020, 600);
		if (current_language_ == CHINESE) {
			chinese_char_.load("san_image.png");
			chinese_char_.draw(1500, 500);
			ofSetColor(0, 0, 0);
			pronunciation_output_.drawString("San", 1020, 800);
		}
		else if (current_language_ == SPANISH) {
			pronunciation_output_.drawString("Tres", 1020, 800);
		}
		else if (current_language_ == FRENCH) {
			pronunciation_output_.drawString("Trois", 1020, 800);
		}
	} else if (estimated_class_ == 4) {
		translation_output_.drawString("Four", 1020, 600);
		if (current_language_ == CHINESE) {
			chinese_char_.load("si_image.png");
			chinese_char_.draw(1500, 500);
			ofSetColor(0, 0, 0);
			pronunciation_output_.drawString("Si", 1020, 800);
		}
		else if (current_language_ == SPANISH) {
			pronunciation_output_.drawString("Cuatro", 1020, 800);
		}
		else if (current_language_ == FRENCH) {
			pronunciation_output_.drawString("Quatre", 1020, 800);
		}
	} else if (estimated_class_ == 5) {
		translation_output_.drawString("Five", 1020, 600);
		if (current_language_ == CHINESE) {
			chinese_char_.load("wu_image.png");
			chinese_char_.draw(1500, 500);
			ofSetColor(0, 0, 0);
			pronunciation_output_.drawString("Wu", 1020, 800);
		}
		else if (current_language_ == SPANISH) {
			pronunciation_output_.drawString("Cinco", 1020, 800);
		}
		else if (current_language_ == FRENCH) {
			pronunciation_output_.drawString("Cinq", 1020, 800);
		}
	} else if (estimated_class_ == 6) {
		translation_output_.drawString("Six", 1020, 600);
		if (current_language_ == CHINESE) {
			chinese_char_.load("liu_image.png");
			chinese_char_.draw(1500, 500);
			ofSetColor(0, 0, 0);
			pronunciation_output_.drawString("Liu", 1020, 800);
		}
		else if (current_language_ == SPANISH) {
			pronunciation_output_.drawString("Seis", 1020, 800);
		}
		else if (current_language_ == FRENCH) {
			pronunciation_output_.drawString("Six", 1020, 800);
		}
	} else if (estimated_class_ == 7) {
		translation_output_.drawString("Seven", 1020, 600);
		if (current_language_ == CHINESE) {
			chinese_char_.load("qi_image.png");
			chinese_char_.draw(1500, 500);
			ofSetColor(0, 0, 0);
			pronunciation_output_.drawString("Qi", 1020, 800);
		}
		else if (current_language_ == SPANISH) {
			pronunciation_output_.drawString("Siete", 1020, 800);
		}
		else if (current_language_ == FRENCH) {
			pronunciation_output_.drawString("Sept", 1020, 800);
		}
	} else if (estimated_class_ == 8) {
		translation_output_.drawString("Eight", 1020, 600);
		if (current_language_ == CHINESE) {
			chinese_char_.load("ba_image.png");
			chinese_char_.draw(1500, 500);
			ofSetColor(0, 0, 0);
			pronunciation_output_.drawString("Ba", 1020, 800);
		}
		else if (current_language_ == SPANISH) {
			pronunciation_output_.drawString("Ocho", 1020, 800);
		}
		else if (current_language_ == FRENCH) {
			pronunciation_output_.drawString("Huit", 1020, 800);
		}
	} else if (estimated_class_ == 9) {
		translation_output_.drawString("Nine", 1020, 600);
		if (current_language_ == CHINESE) {
			chinese_char_.load("jiu_image.png");
			chinese_char_.draw(1500, 500);
			ofSetColor(0, 0, 0);
			pronunciation_output_.drawString("Jiu", 1020, 800);
		}
		else if (current_language_ == SPANISH) {
			pronunciation_output_.drawString("Nueve", 1020, 800);
		}
		else if (current_language_ == FRENCH) {
			pronunciation_output_.drawString("Neuf", 1020, 800);
		}
	} else if (estimated_class_ == -1) {
		translation_output_.drawString("Invalid", 1020, 600);
		pronunciation_output_.drawString("Invalid", 1020, 800);
	}
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
	int upper_key = toupper(key);
	if (upper_key == 'C') {
		num_pts_ = 0;
	}
	if (key == OF_KEY_RETURN) {
		user_drawing_.grabScreen(100, 100, 500, 500);
		user_drawing_.resize(28, 28);
		user_image_entered_ = true;
		user_drawing_.setImageType(OF_IMAGE_GRAYSCALE);
		ofPixels image_pixels = user_drawing_.getPixels();
		vector<vector<char>> converted_image = processImage(image_pixels);
		vector<vector<int>> image_in_binary = ConvertImagetoBinary(converted_image);
		
		training_images_ =
			"C:\\Users\\kongt\\final-project-TinaKong83\\final-project-TinaKong83\\bin\\data\\trainingimagesfinal";
		training_labels_ =
			"C:\\Users\\kongt\\final-project-TinaKong83\\final-project-TinaKong83\\bin\\data\\traininglabelsfinal";
		vector<vector<vector<int>>> vector_training_images = CreateVectorOfImages(training_images_);

		vector_training_labels_ = CreateVectorOfLabels(training_labels_);

		vector_class_feature_probability_ = VectorClassFeatureProbability(vector_training_images, vector_training_labels_);

		
		vector<double> vector_label_priors = VectorLabelPriors(vector_training_labels_);
		vector<double> vector_posterior_probabilities = VectorPosteriorProbabilities(vector_label_priors, 
			vector_class_feature_probability_, image_in_binary);

		estimated_class_ = EstimateImageClass(vector_posterior_probabilities);
		image_classified_ = true;
		setLanguageAudio(estimated_class_);
	}
}

//--------------------------------------------------------------
void ofApp::setLanguageAudio(int estimated_class_) {
	if (estimated_class_ == 0) {
		audioOfZero();
	}
	else if (estimated_class_ == 1) {
		audioOfOne();
	}
	else if (estimated_class_ == 2) {
		audioOfTwo();
	}
	else if (estimated_class_ == 3) {
		audioOfThree();
	}
	else if (estimated_class_ == 4) {
		audioOfFour();
	}
	else if (estimated_class_ == 5) {
		audioOfFive();
	}
	else if (estimated_class_ == 6) {
		audioOfSix();
	}
	else if (estimated_class_ == 7) {
		audioOfSeven();
	}
	else if (estimated_class_ == 8) {
		audioOfEight();
	}
	else if (estimated_class_ == 9) {
		audioOfNine();
	}
	else if (estimated_class_ == -1) {
		audioOfInvalidNumber();
	}
}

//--------------------------------------------------------------
void ofApp::audioOfZero() {
	if (current_language_ == ENGLISH) {
		translate_audio_file_ = "zero.mp3";
		translation_audio_.load(translate_audio_file_);
		translation_audio_.play();
	} else if (current_language_ == SPANISH) {
		translate_audio_file_ = "cero.mp3";
		translation_audio_.load(translate_audio_file_);
		translation_audio_.play();
	} else if (current_language_ == CHINESE) {
		translate_audio_file_ = "ling.mp3";
		translation_audio_.load(translate_audio_file_);
		translation_audio_.play();
	} else if (current_language_ == FRENCH) {
		translate_audio_file_ = "french_zero.mp3";
		translation_audio_.load(translate_audio_file_);
		translation_audio_.play();
	}
}
//--------------------------------------------------------------
void ofApp::audioOfOne() {
	if (current_language_ == ENGLISH) {
		translate_audio_file_ = "one.mp3";
		translation_audio_.load(translate_audio_file_);
		translation_audio_.play();
	}
	if (current_language_ == SPANISH) {
		translate_audio_file_ = "uno.mp3";
		translation_audio_.load(translate_audio_file_);
		translation_audio_.play();
	}
	if (current_language_ == CHINESE) {
		translate_audio_file_ = "yi.mp3";
		translation_audio_.load(translate_audio_file_);
		translation_audio_.play();
	}
	if (current_language_ == FRENCH) {
		translate_audio_file_ = "un.mp3";
		translation_audio_.load(translate_audio_file_);
		translation_audio_.play();
	}

}//--------------------------------------------------------------
void ofApp::audioOfTwo() {
	if (current_language_ == ENGLISH) {
		translate_audio_file_ = "two.mp3";
		translation_audio_.load(translate_audio_file_);
		translation_audio_.play();
	}
	if (current_language_ == SPANISH) {
		translate_audio_file_ = "dos.mp3";
		translation_audio_.load(translate_audio_file_);
		translation_audio_.play();
	}
	if (current_language_ == CHINESE) {
		translate_audio_file_ = "er.mp3";
		translation_audio_.load(translate_audio_file_);
		translation_audio_.play();
	}
	if (current_language_ == FRENCH) {
		translate_audio_file_ = "deux.mp3";
		translation_audio_.load(translate_audio_file_);
		translation_audio_.play();
	}

}//--------------------------------------------------------------
void ofApp::audioOfThree() {
	if (current_language_ == ENGLISH) {
		translate_audio_file_ = "three.mp3";
		translation_audio_.load(translate_audio_file_);
		translation_audio_.play();
	}
	if (current_language_ == SPANISH) {
		translate_audio_file_ = "tres.mp3";
		translation_audio_.load(translate_audio_file_);
		translation_audio_.play();
	}
	if (current_language_ == CHINESE) {
		translate_audio_file_ = "san.mp3";
		translation_audio_.load(translate_audio_file_);
		translation_audio_.play();
	}
	if (current_language_ == FRENCH) {
		translate_audio_file_ = "trois.mp3";
		translation_audio_.load(translate_audio_file_);
		translation_audio_.play();
	}

}//--------------------------------------------------------------
void ofApp::audioOfFour() {
	if (current_language_ == ENGLISH) {
		translate_audio_file_ = "four.mp3";
		translation_audio_.load(translate_audio_file_);
		translation_audio_.play();
	}
	if (current_language_ == SPANISH) {
		translate_audio_file_ = "cuatro.mp3";
		translation_audio_.load(translate_audio_file_);
		translation_audio_.play();
	}
	if (current_language_ == CHINESE) {
		translate_audio_file_ = "si.mp3";
		translation_audio_.load(translate_audio_file_);
		translation_audio_.play();
	}
	if (current_language_ == FRENCH) {
		translate_audio_file_ = "quatre.mp3";
		translation_audio_.load(translate_audio_file_);
		translation_audio_.play();
	}

}//--------------------------------------------------------------
void ofApp::audioOfFive() {
	if (current_language_ == ENGLISH) {
		translate_audio_file_ = "five.mp3";
		translation_audio_.load(translate_audio_file_);
		translation_audio_.play();
	}
	if (current_language_ == SPANISH) {
		translate_audio_file_ = "cinco.mp3";
		translation_audio_.load(translate_audio_file_);
		translation_audio_.play();
	}
	if (current_language_ == CHINESE) {
		translate_audio_file_ = "wu.mp3";
		translation_audio_.load(translate_audio_file_);
		translation_audio_.play();
	}
	if (current_language_ == FRENCH) {
		translate_audio_file_ = "cinq.mp3";
		translation_audio_.load(translate_audio_file_);
		translation_audio_.play();
	}

}//--------------------------------------------------------------
void ofApp::audioOfSix() {
	if (current_language_ == ENGLISH) {
		translate_audio_file_ = "six.mp3";
		translation_audio_.load(translate_audio_file_);
		translation_audio_.play();
	}
	if (current_language_ == SPANISH) {
		translate_audio_file_ = "seis.mp3";
		translation_audio_.load(translate_audio_file_);
		translation_audio_.play();
	}
	if (current_language_ == CHINESE) {
		translate_audio_file_ = "liu.mp3";
		translation_audio_.load(translate_audio_file_);
		translation_audio_.play();
	}
	if (current_language_ == FRENCH) {
		translate_audio_file_ = "french_six.mp3";
		translation_audio_.load(translate_audio_file_);
		translation_audio_.play();
	}

}//--------------------------------------------------------------
void ofApp::audioOfSeven() {
	if (current_language_ == ENGLISH) {
		translate_audio_file_ = "seven.mp3";
		translation_audio_.load(translate_audio_file_);
		translation_audio_.play();
	}
	if (current_language_ == SPANISH) {
		translate_audio_file_ = "siete.mp3";
		translation_audio_.load(translate_audio_file_);
		translation_audio_.play();
	}
	if (current_language_ == CHINESE) {
		translate_audio_file_ = "qi.mp3";
		translation_audio_.load(translate_audio_file_);
		translation_audio_.play();
	}
	if (current_language_ == FRENCH) {
		translate_audio_file_ = "sept.mp3";
		translation_audio_.load(translate_audio_file_);
		translation_audio_.play();
	}

}//--------------------------------------------------------------
void ofApp::audioOfEight() {
	if (current_language_ == ENGLISH) {
		translate_audio_file_ = "eight.mp3";
		translation_audio_.load(translate_audio_file_);
		translation_audio_.play();
	}
	if (current_language_ == SPANISH) {
		translate_audio_file_ = "ocho.mp3";
		translation_audio_.load(translate_audio_file_);
		translation_audio_.play();
	}
	if (current_language_ == CHINESE) {
		translate_audio_file_ = "ba.mp3";
		translation_audio_.load(translate_audio_file_);
		translation_audio_.play();
	}
	if (current_language_ == FRENCH) {
		translate_audio_file_ = "huit.mp3";
		translation_audio_.load(translate_audio_file_);
		translation_audio_.play();
	}

}//--------------------------------------------------------------
void ofApp::audioOfNine() {
	if (current_language_ == ENGLISH) {
		translate_audio_file_ = "nine.mp3";
		translation_audio_.load(translate_audio_file_);
		translation_audio_.play();
	}
	if (current_language_ == SPANISH) {
		translate_audio_file_ = "nueve.mp3";
		translation_audio_.load(translate_audio_file_);
		translation_audio_.play();
	}
	if (current_language_ == CHINESE) {
		translate_audio_file_ = "jiu.mp3";
		translation_audio_.load(translate_audio_file_);
		translation_audio_.play();
	}
	if (current_language_ == FRENCH) {
		translate_audio_file_ = "neuf.mp3";
		translation_audio_.load(translate_audio_file_);
		translation_audio_.play();
	}
}

//--------------------------------------------------------------
void ofApp::audioOfInvalidNumber() {
	translate_audio_file_ = "Computer Error-Sound.mp3";
	translation_audio_.load(translate_audio_file_);
	translation_audio_.play();
}

//--------------------------------------------------------------
vector<vector<char>> ofApp::processImage(ofPixels& image_pixels) {
	user_drawing_.setImageType(OF_IMAGE_GRAYSCALE);
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
void ofApp::mouseDragged(int x, int y, int button){
	if (num_pts_ < 3000 && canvas_.inside(x, y)) {
		pts[num_pts_].x = x;
		pts[num_pts_].y = y;
		num_pts_++;
	}
}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){
	if (english_button_.inside(x, y)) {
		resetButtonColors();
		current_language_ = ENGLISH;
		language_button_clicked_ = true;
	}
	else if (french_button_.inside(x, y)) {
		resetButtonColors();
		current_language_ = FRENCH;
		language_button_clicked_ = true;
	}
	else if (spanish_button_.inside(x, y)) {
		resetButtonColors();
		current_language_ = SPANISH;
		language_button_clicked_ = true;
	}
	else if (chinese_button_.inside(x, y)) {
		resetButtonColors();
		current_language_ = CHINESE;
		language_button_clicked_ = true;
	}
}

//--------------------------------------------------------------
void ofApp::resetButtonColors() {
	default_english_button_color_ = ofColor(75, 0, 130);
	default_french_button_color_ = ofColor(75, 0, 130);
	default_spanish_button_color_ = ofColor(75, 0, 130);
	default_chinese_button_color_ = ofColor(75, 0, 130);
}
