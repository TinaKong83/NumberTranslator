#pragma once

#include "ofMain.h"
#include "ofxGui.h"
#include "../src/ClassifyingData.h"
#include "ImageLabelsData.h"
#include "TrainingData.h"

//#define MAX_PTS = 3000

class ofApp : public ofBaseApp {

	enum AppState {
		CANVAS_STATE = 0,
		OUTPUT
	};

	enum LanguageState {
		ENGLISH = 0,
		FRENCH,
		SPANISH,
		CHINESE
	};

	ofTrueTypeFont instruction_;
	ofTrueTypeFont english_label_;
	ofTrueTypeFont french_label_;
	ofTrueTypeFont spanish_label_;
	ofTrueTypeFont chinese_label_;
	ofTrueTypeFont digit_estimate_;
	ofTrueTypeFont pronunciation_label_;
	ofTrueTypeFont translation_label_;

	ofTrueTypeFont character_label_;
	ofTrueTypeFont pronunciation_output_;
	ofTrueTypeFont translation_output_;

	ofSoundPlayer play_music_;
	ofSoundPlayer translation_audio_;

public:
	void setup();
	void loadFonts();
	void draw();
	void translateClassifiedImage();
	void setupEnglishButton();
	void setupFrenchButton();
	void setupSpanishButton();
	void setupChineseButton();

	void audioOfZero();
	void audioOfOne();
	void audioOfTwo();
	void audioOfThree();
	void audioOfFour();
	void audioOfFive();
	void audioOfSix();
	void audioOfSeven();
	void audioOfEight();
	void audioOfNine();
	void audioOfInvalidNumber();

	void keyPressed(int key);
	void setLanguageAudio(int estimated_class);
	vector<vector<char>> processImage(ofPixels& image_pixels);
	void printCompositeImage(vector<vector<char>>& converted_image);
	void mouseDragged(int x, int y, int button);
	void mousePressed(int x, int y, int button);
	void resetButtonColors();

	AppState current_state_ = CANVAS_STATE;
	LanguageState current_language_ = ENGLISH;
	int estimated_class_;

	ofPoint pts[3000];
	int num_pts_;

	ofxButton translate_button_;

	ofImage user_drawing_;
	ofImage chinese_char_;

	ofRectangle canvas_;
	ofRectangle english_button_;
	ofRectangle french_button_;
	ofRectangle spanish_button_;
	ofRectangle chinese_button_;

	ofRectangle button_divider;

	ofColor default_english_button_color_ = ofColor(75, 0, 130);
	ofColor default_french_button_color_ = ofColor(75, 0, 130);
	ofColor default_spanish_button_color_ = ofColor(75, 0, 130);
	ofColor default_chinese_button_color_ = ofColor(75, 0, 130);

	ofColor clicked_button_color_ = ofColor(230, 230, 100);

	bool language_button_clicked_;
	bool user_image_entered_ = false;
	bool image_classified_ = false;

	string translate_audio_file_;
	string training_images_;
	string training_labels_;

	vector<int> vector_training_labels_;
	vector<vector<vector<double>>> vector_class_feature_probability_;

	const string kTrainingImagesPath_
		= "C:\\Users\\kongt\\final-project-TinaKong83\\final-project-TinaKong83\\bin\\data\\trainingimagesfinal";
	const string kTrainingLabelsPath_ 
		= "C:\\Users\\kongt\\final-project-TinaKong83\\final-project-TinaKong83\\bin\\data\\traininglabelsfinal";
};
