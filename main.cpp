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

int main() {
    // Инициализация ncurses
    initscr();
    raw();
    keypad(stdscr, TRUE);
    noecho();

    int highlight = 0; // Подсвеченная кнопка
    int ch;

    // Отображение меню
    displayMenu(highlight);

    while ((ch = getch()) != 'q') { // Нажатие 'q' завершает программу
        switch (ch) {
            case KEY_UP:
                if (highlight > 0) {
                    highlight--;
                }
                break;
            case KEY_DOWN:
                if (highlight < 3) {
                    highlight++;
                }
                break;
            case 10: // Нажатие Enter
                switch (highlight) {
                    case 0: {
                        // Ввод текста для функции
                        std::string input = inputWindow("Entering file name");
                        
                        int pagesCount = inputWindowPages("Entering pages size");
                        // Вызываем вашу функцию
                        StartBuildingAlphabetIndex(input, pagesCount);
                        
                        // Отображаем результат в новом окне
//                        outputWindow(resultOutput.str());
                        break;
                    }
                    case 1:{
                        std::string sequence = inputWindowSequence("Entering Sequence");
                        int lmin = inputWindowLMin("Entering minimal length");
                        int lmax = inputWindowLMax("Entering maximum length");
                        FindingTheMostFrequentSubsequence(sequence, lmin, lmax);
                        break;
                    }
                    case 2:{
                        int capacity = inputWindowKnapsackCapacity("Entering capacity of knapsack");
                        int count = inputWindowCountOfElements("Entering count of elements");
                        std::vector<Item> items = inputWindowItems("Entering items of knapsack", count);
                        outputWindow(std::to_string(KnapsackProblemSolving(items, capacity)));
                        break;
                    }
                    case 3:{
                        outputWindow("func 4 is not realised yet");
                        break;
                    }
                }
                displayMenu(highlight); // Возврат к меню
                break;
        }
        displayMenu(highlight); // Обновляем меню
    }

    endwin(); // Завершение ncurses
    return 0;
}

