#ifndef LAB3_ALPHABET_INDEX
#define LAB3_ALPHABET_INDEX

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <cctype>
#include <algorithm>
#include "Dictionary.h" 
#include "Book.h"
#include "Pages.h"
#include "Rows.h"

class AlphaBeticalIndex
{
private:
    Dictionary<std::string, DynamicArray<int>> index;
public:
    AlphaBeticalIndex() = default;
    
    AlphaBeticalIndex(Book& input_book)
    {
        for (int NumPage = 0; NumPage < input_book.GetPageCount(); NumPage++)
        {
            Page page = input_book.GetPage(NumPage);
            for (int NumRow = 0; NumRow < page.getPageSize(); NumRow++)
            {
                Row row = page.getRow(NumRow);
                std::istringstream rowStream(row.get());
                std::string word;
                while(rowStream >> word)
                {
                    if(index.contains(word))
                    {
                        DynamicArray<int> &pages = index.get(word);
                        pages.push_back(NumPage + 1);
                    }
                    else
                    {
                        DynamicArray<int> buf(1, NumPage + 1);
                        index.add(word, buf);
                    }
                }
            }
            
        }
    }
    
    Dictionary<std::string, DynamicArray<int>> GetIndex()
    {
        return index;
    }
    
    void DictionaryToFile(const std::string& outputFilePath)
    {
        std::ofstream outputFile(outputFilePath);
        if (!outputFile) {
            throw std::runtime_error("Не удалось открыть выходной файл.");
        }

        for (auto it = index.begin(); it != index.end(); ++it) {
            const std::pair<std::string, DynamicArray<int>> &entry = *it;
            outputFile << entry.first << ": ";
            for (size_t i = 0; i < entry.second.get_size(); ++i) {
                outputFile << entry.second[i];
                if (i < entry.second.get_size() - 1) {
                    outputFile << ", ";
                }
            }
            outputFile << std::endl;
        }
        outputFile.close();
    }
};


AlphaBeticalIndex buildAlphabeticalIndexFromFile(
    const std::string &inputFilePath,
    int pageSize,
    const std::string &outputFilePath, int rowSize) {

    // Чтение текста из входного файла
    std::ifstream inputFile(inputFilePath);
    if (!inputFile) {
        throw std::runtime_error("Не удалось открыть входной файл.");
    }

    std::ostringstream textBuffer;
    textBuffer << inputFile.rdbuf();
    inputFile.close();
    std::string inputText = textBuffer.str();

    // Замена табуляций и переносов строк на пробелы
    for (char &ch : inputText) {
        if (ch == '\n' || ch == '\t' || !(std::isalnum(ch))) {
            ch = ' ';
        }
        else
        {
            ch = static_cast<char>(std::tolower(ch));
        }
    }

    DynamicArray<Row> rows = lexer(inputText, rowSize);

    DynamicArray<Page> pages = PageMaker(rows, pageSize);
    
    Book item(pages);
    
    std::string bookOutputFilePath = "/Users/vitalijkoldasev/Desktop/laboratories_3_sem/laboratory3/laboratory3/outputbook.txt";
    std::ofstream bookOutputFile(bookOutputFilePath);
    if (!bookOutputFile) {
        throw std::runtime_error("Не удалось открыть файл для записи книги.");
    }

    bookOutputFile << "Book:\n";
    for (int i = 0; i < item.GetPageCount(); i++) {
        bookOutputFile << "Page " << i + 1 << ":\n";

        Page page = item.GetPage(i);

        for (int j = 0; j < item.GetPage(i).getPageSize(); j++) {
            bookOutputFile << page.getRow(j).get() << '\n';
        }
        bookOutputFile << '\n';
    }

    bookOutputFile.close();
    
    AlphaBeticalIndex index(item);
    

    index.DictionaryToFile(outputFilePath);
    
    return index;
}

void StartBuildingAlphabetIndex(std::string fileName, int pageSize, int rowSize)
{
    std::string RealFileName = "/Users/vitalijkoldasev/Desktop/laboratories_3_sem/laboratory3/laboratory3/" + fileName;
    std::string outputFilePath = "/Users/vitalijkoldasev/Desktop/laboratories_3_sem/laboratory3/laboratory3/output.txt";

    buildAlphabeticalIndexFromFile(RealFileName, pageSize, outputFilePath, rowSize);
}

#endif //LAB3_ALPHABET_INDEX
