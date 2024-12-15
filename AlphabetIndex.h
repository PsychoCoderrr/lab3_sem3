#ifndef LAB3_ALPHABET_INDEX
#define LAB3_ALPHABET_INDEX

#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <cctype>
#include <algorithm>
#include "Dictionary.h" 
#include "Book.h"
#include "Pages.h"
#include "Rows.h"

Dictionary<std::string, std::vector<int>> buildAlphabeticalIndexFromFile(
    const std::string &inputFilePath,
    int pageSize,
    bool sizeInWords,
    const std::string &outputFilePath, int rowSize) {
    
    Dictionary<std::string, std::vector<int>> index;

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
    
    
    
    
    
//    int row_size = 5;
//    int page_size = 3;

    // Разбиваем текст на строки
    Vector<Row> rows = lexer(inputText, rowSize);

    // Разбиваем строки на страницы
    Vector<Page> pages = PageMaker(rows, pageSize);
    
    Book item(pages);
//
//    // Выводим страницы
//    std::cout << "here programm was too" << std::endl;
//    std::cout << "\nBook:\n";
//    for (int i = 0; i < item.GetPageCount(); i++)
//    {
//        std::cout << "Page " << i + 1 << ":\n";
//
//        // Получаем текущую страницу
//        Page page = item.GetPage(i);
//
//        // Для каждой страницы выводим строки
//        for (int j = 0; j < item.GetPage(i).getPageSize(); j++)
//        {
//            std::cout << page.getRow(j).get() << '\n';
//        }
//        std::cout << '\n';
//    }
    std::string bookOutputFilePath = "/Users/vitalijkoldasev/Desktop/laboratories_3_sem/laboratory3/laboratory3/outputbook.txt";
    std::ofstream bookOutputFile(bookOutputFilePath);
    if (!bookOutputFile) {
        throw std::runtime_error("Не удалось открыть файл для записи книги.");
    }

    bookOutputFile << "Book:\n";
    for (int i = 0; i < item.GetPageCount(); i++) {
        bookOutputFile << "Page " << i + 1 << ":\n";

        // Получаем текущую страницу
        Page page = item.GetPage(i);

        // Для каждой страницы записываем строки
        for (int j = 0; j < item.GetPage(i).getPageSize(); j++) {
            bookOutputFile << page.getRow(j).get() << '\n';
        }
        bookOutputFile << '\n';
    }

    bookOutputFile.close();

    
    
    

    

    // Разбиение текста на слова
    std::istringstream wordsStream(inputText);
    std::vector<std::string> words;
    std::string word;
    while (wordsStream >> word) {
        words.push_back(word);
    }

    int pageCount = 1; // Номер текущей страницы
    int currentSize = 0; // Текущий размер страницы (в словах или символах)

//    // Разделение списка слов на страницы
//    for (const std::string &currentWord : words) {
//        size_t wordSize = sizeInWords ? 1 : currentWord.length();
//
//        // Проверяем, умещается ли слово на текущей странице
//        if ((sizeInWords && currentSize + wordSize > pageSize) ||
//            (!sizeInWords && currentSize + wordSize + (currentSize > 0 ? 1 : 0) > pageSize)) {
//            // Если страница заполнена, увеличиваем номер страницы
//            pageCount++;
//            currentSize = 0;
//        }
//
//        // Добавляем слово на текущую страницу
//        if (index.contains(currentWord)) {
//            std::vector<int> &pages = index.get(currentWord);
//            if (pages.empty() || pages.back() != pageCount) {
//                pages.push_back(pageCount); // Избегаем дублирования номеров страниц
//            }
//        } else {
//            index.add(currentWord, {pageCount});
//        }
//
//        // Увеличиваем текущий размер страницы
//        currentSize += wordSize + (currentSize > 0 ? 1 : 0); // +1 для пробела
//    }

    for (int NumPage = 0; NumPage < item.GetPageCount(); NumPage++)
    {
        Page page = item.GetPage(NumPage);
        for (int NumRow = 0; NumRow < page.getPageSize(); NumRow++)
        {
            Row row = page.getRow(NumRow);
            std::istringstream rowStream(row.get());
            std::string word;
            while(rowStream >> word)
            {
                if(index.contains(word))
                {
                    std::vector<int> &pages = index.get(word);
                    if (pages.empty() || pages.back() != NumPage)
                    {
                        pages.push_back(NumPage + 1);
                    }
                }
                else
                {
                    index.add(word, {NumPage + 1});
                }
            }
        }
        
    }
    
    
    // Запись алфавитного указателя в выходной файл
    std::ofstream outputFile(outputFilePath);
    if (!outputFile) {
        throw std::runtime_error("Не удалось открыть выходной файл.");
    }

    for (auto it = index.begin(); it != index.end(); ++it) {
        const std::pair<std::string, std::vector<int>> &entry = *it;
        outputFile << entry.first << ": ";
        for (size_t i = 0; i < entry.second.size(); ++i) {
            outputFile << entry.second[i];
            if (i < entry.second.size() - 1) {
                outputFile << ", ";
            }
        }
        outputFile << std::endl;
    }

    outputFile.close();
    return index;
}

void StartBuildingAlphabetIndex(std::string fileName, int pageSize, int rowSize)
{
    std::string RealFileName = "/Users/vitalijkoldasev/Desktop/laboratories_3_sem/laboratory3/laboratory3/" + fileName;
    std::string outputFilePath = "/Users/vitalijkoldasev/Desktop/laboratories_3_sem/laboratory3/laboratory3/output.txt";
    std::cout << "Enter page size" << std::endl;
    bool sizeInWords = false; // Измерение страницы в словах

    // Создание алфавитного указателя
    buildAlphabeticalIndexFromFile(RealFileName, pageSize, sizeInWords, outputFilePath, rowSize);
}

#endif //LAB3_ALPHABET_INDEX
