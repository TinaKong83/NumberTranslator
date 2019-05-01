#pragma once
#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <iterator>
#include <fstream>
#include <math.h>

using std::map;
using std::string;
using std::vector;

double CalculateLabelPriorProbability(int label, vector<int>& training_labels);
vector<double> VectorLabelPriors(vector<int>& training_labels);
double FindFeatureProbabilityFromClass(int row, int col, int label,
	vector<vector<vector<int>>>& vector_of_images, vector<int>& vector_of_labels);
vector<vector<vector<double>>> VectorClassFeatureProbability(vector<vector<vector<int>>>& vector_of_images,
	vector<int>& vector_of_labels);
const double laplace_smoothing_factor = 0.1;