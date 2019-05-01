// ConsoleApplication1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "ImageLabelsData.h"
#include "TrainingData.h"
#include "ClassifyingData.h"

//Method that reads a file of integer labels. Push each integer into a vector of image labels
vector<int> CreateVectorOfLabels(string file_name) {
	vector<int> vector_labels;
	std::ifstream read_file;
	read_file.open(file_name);
	if (read_file.fail()) {
		std::cout << "File is invalid." << std::endl;
	}
	else {
		int label;
		//read file line by line, assuming each line is some integer
		while (read_file >> label) {
			vector_labels.push_back(label);
		}
	}
	read_file.close();
	return vector_labels;
}

//Method that reads a file of character images. Returns a list of 2d vector images with binary features
vector<vector<vector<int>>> CreateVectorOfImages(string file_name) {
	vector<vector<vector<int>>> vector_image_features;
	std::ifstream read_file;
	read_file.open(file_name);
	if (read_file.fail()) {
		std::cout << "File is invalid." << std::endl;
	}
	else {
		char image_char;
		while (!read_file.eof()) {
			vector<vector<int>> single_image;
			single_image.resize(kImageSize);
			for (int i = 0; i < kImageSize; i++) {
				single_image[i].resize(kImageSize + 1);
				for (int j = 0; j < kImageSize + 1; j++) {
					read_file.get(image_char);
					if (image_char == '\n') {
						continue;
					}
					if (image_char == ' ') {
						single_image[i][j] = 0;
					}
					else if (image_char == '#' || image_char == '+') {
						single_image[i][j] = 1;
					}
				}
			}
			vector_image_features.push_back(single_image);
		}
	}
	vector_image_features.pop_back();
	return vector_image_features;
}

vector<vector<int>> ConvertImagetoBinary(vector<vector<char>> current_image) {
	vector<vector<int>> image_in_binary(kImageSize, vector<int>(kImageSize));

	for (int i = 0; i < kImageSize; i++) {
		for (int j = 0; j < kImageSize; j++) {
			if (current_image[i][j] == ' ') {
				image_in_binary[i][j] = 0;
			}
			else if (current_image[i][j] == '#' || current_image[i][j] == '+') {
				image_in_binary[i][j] = 1;
			}
		}
	}
	return image_in_binary;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file