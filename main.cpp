#include <iostream>
#include <vector>
#include <algorithm>
#include <list>
#include <memory>
#include <ncurses.h>
#include <string>
#include <sstream>
#include <stdexcept>

#include "HashTable.h"
#include "Dictionary.h"
#include "RBTree.h"
#include "MostFrequent.h"
#include "KnapsackProblem.h"
#include "AlphabetIndex.h"
#include "FuncForUI.h"
#include "tests.h"
#include "ArraySequence.h"
#include "Rows.h"
#include "Pages.h"
#include "Book.h"
#include "vector.hpp"

//int main() {
//    // Инициализация ncurses
//    initscr();
//    raw();
//    keypad(stdscr, TRUE);
//    noecho();
//
//    int highlight = 0; // Подсвеченная кнопка
//    int ch;
//
//    // Отображение меню
//    displayMenu(highlight);
//
//    while ((ch = getch()) != 'q') { // Нажатие 'q' завершает программу
//        switch (ch) {
//            case KEY_UP:
//                if (highlight > 0) {
//                    highlight--;
//                }
//                break;
//            case KEY_DOWN:
//                if (highlight < 3) {
//                    highlight++;
//                }
//                break;
//            case 10: // Нажатие Enter
//                switch (highlight) {
//                    case 0: {
//                        // Ввод текста для функции
//                        std::string input = inputWindow("Entering file name");
//                        
//                        int pagesCount = inputWindowPages("Entering pages size");
//                        // Вызываем вашу функцию
//                        StartBuildingAlphabetIndex(input, pagesCount, 3);
//
//                         //Отображаем результат в новом окне
//                        outputWindow("Alphabet index was saved into file output.txt");
//                        break;
//                    }
//                    case 1:{
//                        std::string sequence = inputWindowSequence("Entering Sequence");
//                        int lmin = inputWindowLMin("Entering minimal length");
//                        int lmax = inputWindowLMax("Entering maximum length");
//                        FindingTheMostFrequentSubsequence(sequence, lmin, lmax);
//                        outputWindow("Sequences and their frequency were saved to a file outputSequences.txt");
//                        break;
//                    }
//                    case 2:{
//                        int capacity = inputWindowKnapsackCapacity("Entering capacity of knapsack");
//                        int count = inputWindowCountOfElements("Entering count of elements");
//                        std::vector<Item> items = inputWindowItems("Entering items of knapsack", count);
//                        outputWindow(std::to_string(KnapsackProblemSolving(items, capacity)));
//                        break;
//                    }
//                    case 3:{
//                        startTests();
//                        outputWindow("Tests have been passed");
//                        break;
//                    }
//                }
//                displayMenu(highlight); // Возврат к меню
//                break;
//        }
//        displayMenu(highlight); // Обновляем меню
//    }
//
//    endwin(); // Завершение ncurses
//    return 0;
//}

//int main()
//{
//    // Пример исходного текста
//    std::string text = "This is a simple example of how to use the lexer and PageMaker functions. "
//                       "It demonstrates splitting a text into rows of a fixed size, "
//                       "then grouping those rows into pages.";
//
//    // Размер строки (количество слов в строке)
//    int row_size = 5;
//
//    // Размер страницы (количество строк на странице)
//    int page_size = 3;
//
//    // Разбиваем текст на строки
//    Vector<Row> rows = lexer(text, row_size);
//
//    // Выводим строки
//    std::cout << "Rows:\n";
//    for (int i = 0; i < rows.get_size(); i++)
//    {
//        std::cout << rows[i].get() << '\n';
//    }
//
//    // Разбиваем строки на страницы
//    Vector<Page> pages = PageMaker(rows, page_size);
//    
//    Book item(pages);
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
//
//    return 0;
//}

int main()
{
    StartBuildingAlphabetIndex("input.txt", 5, 3);
    return 0;
}
