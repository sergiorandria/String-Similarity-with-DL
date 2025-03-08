#include "JaccardIndex.h"
#include "StringSimilarity.h"

template<typename T>
/**
 * @brief Computes the Jaccard Index between two sets.
 * 
 * The Jaccard Index is a measure of similarity between two sets, defined as the size of the intersection 
 * divided by the size of the union of the sets.
 * 
 * @tparam T The type of elements in the sets.
 * @param setA The first set.
 * @param setB The second set.
 * @return double The Jaccard Index, a value between 0 and 1.
 */
double JaccardIndex(const std::unordered_set<T>& setA, const std::unordered_set<T>& setB)
{
    std::unordered_set<T> intersection;
    std::unordered_set<T> unionSet;

    for (const auto& elem : setA)
    {
        if (setB.find(elem) != setB.end())
        {
            intersection.insert(elem);
        }

        unionSet.insert(elem);
    }

    for (const auto& elem : setB)
    {
        unionSet.insert(elem);
    }

    return static_cast<double>(intersection.size()) / static_cast<double>(unionSet.size());
}

/**
 * @brief Generates a set of n-grams from the given string.
 * 
 * An n-gram is a contiguous sequence of n items from a given sample of text.
 * This function generates all possible n-grams of length n from the input string.
 * If the length of the string is less than n, the entire string is returned as the only n-gram.
 * 
 * @param str The input string from which n-grams are to be generated.
 * @param n The length of each n-gram.
 * @return std::unordered_set<std::string> A set containing all n-grams of length n from the input string.
 */
std::unordered_set<std::string> generateNGrams(const std::string& str, int n)
{
    std::unordered_set<std::string> nGrams;

    if (str.size() < n) 
    {
        nGrams.insert(str);
        return nGrams;
    }

    for (int i = 0; i < str.size() - n + 1; i++)
    {
        nGrams.insert(str.substr(i, n));
    }

    return nGrams;
}

