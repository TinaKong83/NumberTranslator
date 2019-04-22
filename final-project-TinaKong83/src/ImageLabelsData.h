#pragma once
#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <iterator>
#include <fstream>
using std::map;
using std::string;
using std::vector;

vector<int> CreateVectorOfLabels(string file_name);
vector<vector<vector<int>>> CreateVectorOfImages(string file_name);
vector<vector<int>> ConvertImagetoBinary(vector<vector<char>> current_image);

const int kImageSize = 28;




