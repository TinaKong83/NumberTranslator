#pragma once

#include "ofMain.h"
#include "ofxGui.h"
#include "../src/ClassifyingData.h"
#include "../src/ofxCenteredTrueTypeFont.h"
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

	ofTrueTypeFont instruction;
	ofTrueTypeFont english_label;
	ofTrueTypeFont french_label;
	ofTrueTypeFont spanish_label;
	ofTrueTypeFont chinese_label;
	ofTrueTypeFont digit_estimate;
	ofTrueTypeFont pronunciation_label;
	ofTrueTypeFont translation_label;

	ofTrueTypeFont character_label;
	ofTrueTypeFont pronunciation_output;
	ofTrueTypeFont translation_output;

	ofSoundPlayer play_music;
	ofSoundPlayer translation_audio;

	ofPolyline line_;

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

	AppState current_state = CANVAS_STATE;
	LanguageState current_language = ENGLISH;
	int estimated_class;

	ofPoint pts[3000];
	int num_pts;

	ofxButton translate_button;

	ofImage user_drawing;
	ofImage chinese_char;

	ofRectangle canvas;
	ofRectangle english_button;
	ofRectangle french_button;
	ofRectangle spanish_button;
	ofRectangle chinese_button;

	ofRectangle button_divider;

	ofColor default_english_button_color = ofColor(75, 0, 130);
	ofColor default_french_button_color = ofColor(75, 0, 130);
	ofColor default_spanish_button_color = ofColor(75, 0, 130);
	ofColor default_chinese_button_color = ofColor(75, 0, 130);

	ofColor clicked_button_color = ofColor(230, 230, 100);

	bool language_button_clicked;
	bool user_image_entered = false;
	bool image_classified = false;

	string translate_audio_file;

	string training_images;
	string training_labels;

	vector<int> vector_training_labels;
	vector<vector<vector<double>>> vector_class_feature_probability;
};
