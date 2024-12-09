#include "HashTable.h"
#include "Dictionary.h"
#include "RBTree.h"
#include <iostream>
#include <vector>
#include <algorithm>
#include <list>
#include <memory>
#include "MostFrequent.h"
#include "KnapsackProblem.h"
#include "AlphabetIndex.h"
#include <ncurses.h>

//struct Item {
//    int weight;
//    int value;
//    double valuePerWeight() const {
//        return static_cast<double>(value) / weight;
//    }
//};
//
//
//struct State {
//    int currentWeight;
//    int currentValue;
//    std::vector<int> usedItems;
//
//    // Для сравнения состояний в красно-черном дереве
//    bool operator<(const State& other) const {
//        if (currentWeight != other.currentWeight)
//            return currentWeight < other.currentWeight;
//        return currentValue < other.currentValue;
//    }
//    
//
//    // Оператор равенства для сравнения состояний
//    bool operator==(const State& other) const {
//        return currentWeight == other.currentWeight &&
//               currentValue == other.currentValue &&
//               usedItems == other.usedItems;
//    }
//};
//
//class KnapsackSolver {
//private:
//    int capacity;
//    std::vector<Item> items;
//    RedBlackTree<State, int> stateTree; // Хранение уникальных состояний
//    int maxValue;
//
//    void dfs(State state) {
//        // Если превышен вес рюкзака, выходим
//        if (state.currentWeight > capacity) return;
//
//        // Проверяем и обновляем максимальное значение
//        maxValue = std::max(maxValue, state.currentValue);
//
//        // Добавляем состояние в дерево (если оно уникально)
//        if (stateTree.find(state) != stateTree.getNil()) return; // Уникальность
//        stateTree.insert(state, state.currentValue);
//
//        // Пробуем добавить каждый предмет
//        for (int i = 0; i < items.size(); ++i) {
//            if (std::find(state.usedItems.begin(), state.usedItems.end(), i) != state.usedItems.end())
//                continue; // Пропускаем уже использованные предметы
//
//            State nextState = state;
//            nextState.currentWeight += items[i].weight;
//            nextState.currentValue += items[i].value;
//            nextState.usedItems.push_back(i);
//            dfs(nextState); // Рекурсивно углубляемся
//        }
//    }
//
//public:
//    KnapsackSolver(int capacity, const std::vector<Item>& items)
//        : capacity(capacity), items(items), maxValue(0) {
//        // Сортируем предметы по ценности на единицу веса
//        std::sort(this->items.begin(), this->items.end(), [](const Item& a, const Item& b) {
//            return a.valuePerWeight() > b.valuePerWeight();
//        });
//    }
//
//    int solve() {
//        State initialState = {0, 0, {}};
//        dfs(initialState);
//        return maxValue;
//    }
//};

//int main() {
//    std::string input = "abcabcabc";
//    int lmin = 2, lmax = 3;
//
//    Dictionary<std::string, int> result = theMostFrequentSubsequences(input, lmin, lmax);
//
//    for (auto it = result.begin(); it != result.end(); ++it) {
//        auto [key, value] = *it;
//        std::cout << "Subsequence: " << key << ", Frequency: " << value << std::endl;
//    }
//
//    return 0;
//}

//Dictionary<std::string, std::vector<int>> buildAlphabeticalIndexFromFile(
//    const std::string &inputFilePath,
//    int pageSize,
//    bool sizeInWords,
//    const std::string &outputFilePath) {
//    
//    Dictionary<std::string, std::vector<int>> index;
//
//    // Чтение текста из входного файла
//    std::ifstream inputFile(inputFilePath);
//    if (!inputFile) {
//        throw std::runtime_error("Не удалось открыть входной файл.");
//    }
//
//    std::ostringstream textBuffer;
//    textBuffer << inputFile.rdbuf();
//    inputFile.close();
//    std::string inputText = textBuffer.str();
//
//    // Замена табуляций и переносов строк на пробелы
//    for (char &ch : inputText) {
//        if (ch == '\n' || ch == '\t' || !(std::isalnum(ch))) {
//            ch = ' ';
//        }
//        else
//        {
//            ch = static_cast<char>(std::tolower(ch));
//        }
//    }
//
//    std::cout << inputText << std::endl;
//    // Разбиение текста на слова
//    std::istringstream wordsStream(inputText);
//    std::vector<std::string> words;
//    std::string word;
//    while (wordsStream >> word) {
//        words.push_back(word);
//    }
//
//    int pageCount = 1; // Номер текущей страницы
//    int currentSize = 0; // Текущий размер страницы (в словах или символах)
//
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
//
//    // Запись алфавитного указателя в выходной файл
//    std::ofstream outputFile(outputFilePath);
//    if (!outputFile) {
//        throw std::runtime_error("Не удалось открыть выходной файл.");
//    }
//
//    for (auto it = index.begin(); it != index.end(); ++it) {
//        const std::pair<std::string, std::vector<int>> &entry = *it;
//        outputFile << entry.first << ": ";
//        for (size_t i = 0; i < entry.second.size(); ++i) {
//            outputFile << entry.second[i];
//            if (i < entry.second.size() - 1) {
//                outputFile << ", ";
//            }
//        }
//        outputFile << std::endl;
//    }
//
//    outputFile.close();
//    return index;
//}

// Прототип вашей функции







#include <ncurses.h>
#include <string>
#include <sstream>
#include <stdexcept>

// Прототип вашей функции

// Вспомогательная функция для отображения окна ввода
std::string inputWindow(const std::string &prompt);

int inputWindowPages(const std::string &prompt);
std::string inputWindowSequence(const std::string &prompt);
int inputWindowLMin(const std::string &prompt);
int inputWindowLMax(const std::string &prompt);

// Вспомогательная функция для отображения окна результата
void outputWindow(const std::string &result);

// Отображение главного меню
void displayMenu(int highlight);

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
                        outputWindow("func 3 is not realised yet");
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

// Отображение главного меню
void displayMenu(int highlight) {
    clear();
    const char *options[] = {"Alphabet index", "func 2", "func 3", "func 4"};
    int numOptions = sizeof(options) / sizeof(options[0]);

    mvprintw(0, 0, "Choose the func and press Enter:");

    for (int i = 0; i < numOptions; i++) {
        if (i == highlight) {
            attron(A_REVERSE);
            mvprintw(i + 3, 10, options[i]);
            attroff(A_REVERSE);
        } else {
            mvprintw(i + 3, 10, options[i]);
        }
    }

    refresh();
}

// Окно для ввода текста
std::string inputWindow(const std::string &prompt) {
    clear();
    mvprintw(1, 1, prompt.c_str());
    mvprintw(3, 1, "Enter file name: ");
    refresh();

    char buffer[1024];
    echo();
    getnstr(buffer, 1023); // Ограничение длины ввода
    noecho();

    return std::string(buffer);
}

int inputWindowPages(const std::string &prompt) {
    clear();
    mvprintw(1, 1, prompt.c_str());
    mvprintw(3, 1, "Enter pages size: ");
    refresh();

    char buffer[1024];
    echo();
    getnstr(buffer, 1023); // Ограничение длины ввода
    noecho();

    return stoi(std::string(buffer));
}

std::string inputWindowSequence(const std::string &prompt) {
    clear();
    mvprintw(1, 1, prompt.c_str());
    mvprintw(3, 1, "Enter your sequence: ");
    refresh();

    char buffer[1024];
    echo();
    getnstr(buffer, 1023); // Ограничение длины ввода
    noecho();

    return std::string(buffer);
}

int inputWindowLMin(const std::string &prompt) {
    clear();
    mvprintw(1, 1, prompt.c_str());
    mvprintw(3, 1, "Enter minimal length: ");
    refresh();

    char buffer[1024];
    echo();
    getnstr(buffer, 1023); // Ограничение длины ввода
    noecho();

    return stoi(std::string(buffer));
}

int inputWindowLMax(const std::string &prompt) {
    clear();
    mvprintw(1, 1, prompt.c_str());
    mvprintw(3, 1, "Enter maximum length: ");
    refresh();

    char buffer[1024];
    echo();
    getnstr(buffer, 1023); // Ограничение длины ввода
    noecho();

    return stoi(std::string(buffer));
}

// Окно для вывода результата
void outputWindow(const std::string &result) {
    clear();
    mvprintw(1, 1, "Result:");
    mvprintw(3, 1, result.c_str());
    mvprintw(5, 1, "Press Enter to return to main menu...");
    refresh();

    getch(); // Ожидание Enter
}

//// Реализация вашей функции (пример)
//void StartBuildingAlphabetIndex(const std::string &input, std::ostream &output) {
//    // Простая обработка текста
//    output << "Вы ввели: " << input << "\n";
//    output << "Функция StartBuildingAlphabetIndex выполнена!";
//}


//int main()
//{
//    std::string input_string = "abcabcabcabc";
//    FindingTheMostFrequentSubsequence(input_string, 2, 3);
//    return 0;
//}
