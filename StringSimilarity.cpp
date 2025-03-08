#include "StringSimilarity.h"

int LevenshteinDistance(std::string& s1, std::string& s2)
{
    std::transform(s1.begin(), s1.end(), s1.begin(), 
                [](unsigned char c) { 
                    return std::tolower(c);
                });
    std::transform(s2.begin(), s2.end(), s2.begin(), 
                [](unsigned char c) {
                    return std::tolower(c);
                });
    
    std::vector<int> v0(s1.size() + 1);
    std::vector<int> v1(s1.size() + 1);

    for (int i = 0; i < v0.size(); i++)
    {
        v0[i] = i;
    }

    for (int i = 0; i < s2.size(); i++)
    {
        v1[0] = i + 1;

        for (int j = 0; j < s1.size(); j++)
        {
            int cost = (s1[j] == s2[i]) ? 0 : 1;
            v1[j + 1] = std::min(v1[j] + 1, std::min(v0[j + 1] + 1, v0[j] + cost));
        }

        v0 = v1;
    }

    return v1[s1.size()];
}

float Similarity(std::string& s1, std::string& s2)
{
    int maxLen = std::max(s1.size(), s2.size());
    int distance = LevenshteinDistance(s1, s2);

    return 1.0f - (float)distance / (float)maxLen;
}