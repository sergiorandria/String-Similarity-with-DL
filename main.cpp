#include <fstream>

#include "JaccardIndex.h"
#include "StringSimilarity.h"

/**
*   @brief To avoid using a naive algorithm, we will try using a Deep Neural Network to 
*    analyze each name properly 
*/
int main()
{
    std::ifstream listName("malagasy_names.txt");
    std::string str1 = "Rakontondraibe Aina";
    std::string str2 = "Rakotondrabe Aina";

    auto gram1 = generateNGrams(str1, 3);
    auto gram2 = generateNGrams(str2, 3);
    std::cout << JaccardIndex(gram1, gram2);
    return 0;
}
