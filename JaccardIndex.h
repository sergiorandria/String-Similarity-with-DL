// Header guard to prevent multiple inclusions of this header file
#ifndef JACCARD_INDEX_H 
#define JACCARD_INDEX_H

#include <iostream>
#include <fstream>
#include <unordered_set>

// Function template to calculate the Jaccard Index between two sets
// @param setA: The first set
// @param setB: The second set
// @return: The Jaccard Index as a double
template<typename T>
double JaccardIndex(const std::unordered_set<T>& setA, const std::unordered_set<T>& setB);

// Function to generate n-grams from a given string
// @param str: The input string
// @param n: The length of each n-gram
// @return: A set of n-grams
std::unordered_set<std::string> generateNGrams(const std::string& str, int n);

// Include the implementation file for the template function
#include "JaccardIndex.tpp"

#endif  