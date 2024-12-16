#ifndef LAB3_GENERATOR
#define LAB3_GENERATOR
#include <string>
#include <ctime>
#include <random>

std::string helpful_array = "abcdefghijklmnopqrstuvwxyz";

std::string GenerateSequence(int count)
{
    std::string result = "";
    std::mt19937 generator(static_cast<unsigned int>(std::time(nullptr)));
    std::uniform_int_distribution<int> dist1(0, 25);
    for (int i = 0; i < count; i++)
    {
        result += helpful_array[dist1(generator)];
    }
    
    return result;
}


#endif //LAB3_GENERATOR
