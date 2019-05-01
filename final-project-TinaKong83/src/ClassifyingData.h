#pragma once
#include <math.h>
#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <iterator>
#include <fstream>
#include <string>
using std::map;
using std::string;
using std::vector;

double CalculatePosteriorProbability(vector<vector<double>>& vector_feature_probabilities);
vector<double> VectorPosteriorProbabilities(vector<double>& vector_label_priors,
	vector<vector<vector<double>>>& vector_class_feature_probability, vector<vector<int>>& current_image);
vector<vector<double>> SetImageTestFeatureProbabilities(vector<vector<int>>& current_image,
	vector<vector<double>>& vector_feature_probabilities);
int EstimateImageClass(vector<double>& vector_posterior_probabilities_per_class);
const int kInvalidPosterity = -400;
const int kCurrentImageSize = 28;