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
#include "Generator.hpp"


int main() {
    startTests();
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
                        
                        std::string input = inputWindow("Entering file name");
                        
                        int pagesCount = inputWindowPages("Entering pages size");
                        int rowsSize = inputWindowRows("Entering rows size");
                        StartBuildingAlphabetIndex(input, pagesCount, rowsSize);
                        outputWindow("Alphabet index was saved into file output.txt");
                        break;
                    }
                    case 1:{
                        std::string sequence = inputWindowSequence("Entering Sequence");
                        int lmin = inputWindowLMin("Entering minimal length");
                        int lmax = inputWindowLMax("Entering maximum length");
                        FindingTheMostFrequentSubsequence(sequence, lmin, lmax);
                        outputWindow("Sequences and their frequency were saved to a file outputSequences.txt");
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
                        int count = inputWindowCountTest("Entering count for test");
                        int lmin = inputWindowLMin("Entering minimal length");
                        int lmax = inputWindowLMax("Entering maximum length");
                        testFrequentSubsequences(count, lmin, lmax);
                        outputWindow("Tests have been passed");
                        break;
                    }
                }
                displayMenu(highlight);
                break;
        }
        displayMenu(highlight);
    }

    endwin();
    return 0;
}
