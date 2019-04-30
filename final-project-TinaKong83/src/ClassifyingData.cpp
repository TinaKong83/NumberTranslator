#include <iostream>
#include "ClassifyingData.h"

//Calculates the posterior probabilities of a class
double CalculatePosteriorProbability(vector<vector<double>>& vector_feature_probabilities) {
	double posterior_probability_of_class = 0.0;
	for (int i = 0; i < kCurrentImageSize; i++) {
		for (int j = 0; j < kCurrentImageSize; j++) {
			posterior_probability_of_class = posterior_probability_of_class + log(vector_feature_probabilities[i][j]);
		}
	}
	return posterior_probability_of_class;
}

//Creates a list of an image's posterior probabilities per class
vector<double> VectorPosteriorProbabilities(vector<double>& vector_label_priors,
	vector<vector<vector<double>>>& vector_class_feature_probability, vector<vector<int>>& current_image) {

	vector<double> vector_test_probabilities;
	for (int i = 0; i < vector_class_feature_probability.size(); i++) {
		int current_label = i;
		vector<vector<double>> vector_feature_probabilities_of_a_class = vector_class_feature_probability[i];
		vector<vector<double>> set_vector_feature_probabilities =
			SetImageTestFeatureProbabilities(current_image, vector_feature_probabilities_of_a_class);
		double posterior_probability = log(vector_label_priors[current_label])
			+ CalculatePosteriorProbability(set_vector_feature_probabilities);
		vector_test_probabilities.push_back(posterior_probability);
	}
	return vector_test_probabilities;
}

/*Since the feature probabilities are calculated for white pixels by default, this method allows the probability of black
pixel to be stored as well*/
vector<vector<double>> SetImageTestFeatureProbabilities(vector<vector<int>>& current_image,
	vector<vector<double>>& vector_feature_probabilities) {
	vector<vector<double>> set_vector_feature_probabilities(28, vector<double>(28, 0.0));

	for (int i = 0; i < kCurrentImageSize; i++) {
		for (int j = 0; j < kCurrentImageSize; j++) {
			if (current_image[i][j] == 0) {
				set_vector_feature_probabilities[i][j] = vector_feature_probabilities[i][j];
			}
			else if (current_image[i][j] == 1) {
				set_vector_feature_probabilities[i][j] = 1.0 - (vector_feature_probabilities[i][j]);
			}
		}
	}
	return set_vector_feature_probabilities;
}

//Uses the calculated posterior probabilities to estimate the test image's class by taking the max posterior probability
int EstimateImageClass(vector<double>& vector_posterior_probabilities_per_class) {
	int estimated_class = 0;
	double max_posterior_probability = vector_posterior_probabilities_per_class.at(0);

	for (int i = 0; i < vector_posterior_probabilities_per_class.size(); i++) {
		int current_class = i;
		double current_posterior_probability = vector_posterior_probabilities_per_class[i];
		if (current_posterior_probability > max_posterior_probability) {
			max_posterior_probability = current_posterior_probability;
			estimated_class = current_class;
		}
	}

	if (max_posterior_probability < -400) {
		estimated_class = -1;
	}
	return estimated_class;
}