//Using the Levenshtein metric to calculate the similarity between two strings
#pragma once

#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

int LevenshteinDistance(std::string& s1, std::string& s2);
float Similarity(std::string& s1, std::string& s2);