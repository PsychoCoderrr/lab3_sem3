#ifndef LAB3_ROWS
#define LAB3_ROWS
#include "ArraySequence.h"
#include <vector>
#include <string>
#include <fstream>
#include <sstream>

class Row
{
private:
    std::string row_;
public:
    Row() = default;
    
    Row(std::string& get_row)
    {
        row_ = get_row;
    }
    
    void append(std::string& word)
    {
        row_ = row_ + word;
    }
//    Row(std::string& text, int row_size)
//    {
//        int count = 0;
//        std::istringstream wordsStream(text);
//        std::string line;
//        std::string word;
//        while (wordsStream >> word)
//        {
//            line += line + word + " ";
//            count++;
//            if (count == row_size)
//            {
//                rows->Append(line);
//                line.clear();
//                count = 0;
//            }
//        }
//        if (!line.empty())
//        {
//            rows->Append(line);
//            line.clear();
//            count = 0;
//        }
//    }
    
    
    
};


#endif //LAB3_ROWS
