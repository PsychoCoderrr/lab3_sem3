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

//#include <string>
//#include <sstream>
//#include <vector>
//#include <stdexcept>
//#include <algorithm>
//#include "Dictionary.h"
//
//Dictionary<std::string, std::vector<int>> buildAlphabeticalIndex(const std::string &input,
//                                                                 int pageSize,
//                                                                 bool sizeInWords) {
//    Dictionary<std::string, std::vector<int>> index;
//    std::istringstream wordsStream(input);
//    std::vector<std::string> words;
//    std::string word;
//
//    // 1. Разбиение строки на слова
//    while (wordsStream >> word) {
//        words.push_back(word);
//    }
//
//    int pageCount = 1; // Номер текущей страницы
//    int currentPageCapacity = pageSize / 2; // Первая страница заполняется на половину
//    int currentSize = 0; // Счётчик текущего размера страницы (слов или символов)
//
//    // 2. Разделение списка слов на страницы
//    for (size_t i = 0; i < words.size(); ++i) {
//        const std::string &currentWord = words[i];
//
//        // Подсчёт размера слова (в символах или как одно слово)
//        size_t wordSize = sizeInWords ? 1 : currentWord.length();
//
//        // Проверяем, умещается ли слово на текущей странице
//        if ((sizeInWords && currentSize + wordSize > currentPageCapacity) ||
//            (!sizeInWords && currentSize + wordSize + (currentSize > 0 ? 1 : 0) > currentPageCapacity)) {
//            // Если страница заполнена, увеличиваем номер страницы
//            pageCount++;
//            currentPageCapacity = (pageCount % 10 == 0) ? (3 * pageSize / 4) : pageSize;
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
//        currentSize += wordSize + (currentSize > 0 ? 1 : 0); // +1 для пробела между словами
//    }
//
//    return index;
//}
//
//// Пример использования
//int main() {
//    std::string input = "apple banana cherry";
//    int pageSize = 2; // Размер страницы в словах или символах
//    bool sizeInWords = false; // Если true — ограничение по словам, иначе — по символам
//
//    auto index = buildAlphabeticalIndex(input, pageSize, sizeInWords);
//
//    // Вывод результата
//    for (auto it = index.begin(); it != index.end(); ++it) {
//        auto [word, pages] = *it;
//        std::cout << word << ": ";
//        for (int page : pages) {
//            std::cout << page << " ";
//        }
//        std::cout << "\n";
//    }
//
//    return 0;
//}
//
//#include <iostream>
//#include <fstream>
//#include <sstream>
//#include <vector>
//#include <string>
//#include "Dictionary.h" // Подключаем ваш класс Dictionary
//
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
//        if (ch == '\n' || ch == '\t') {
//            ch = ' ';
//        }
//    }
//
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
//
//int main() {
//    try {
//        // Настройки
//        std::string inputFilePath = "/Users/vitalijkoldasev/Desktop/laboratories_3_sem/laboratory3/laboratory3/input.txt";
//        std::string outputFilePath = "/Users/vitalijkoldasev/Desktop/laboratories_3_sem/laboratory3/laboratory3/output.txt";
//        int pageSize = 10; // Размер страницы
//        bool sizeInWords = true; // Измерение страницы в словах
//
//        // Создание алфавитного указателя
//        buildAlphabeticalIndexFromFile(inputFilePath, pageSize, sizeInWords, outputFilePath);
//
//        std::cout << "Алфавитный указатель успешно создан и сохранён в " << outputFilePath << std::endl;
//    } catch (const std::exception &ex) {
//        std::cerr << "Ошибка: " << ex.what() << std::endl;
//    }
//
//    return 0;
//}

#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <cctype>
#include <algorithm>
#include "Dictionary.h" // Подключаем ваш класс Dictionary

// Функция для удаления знаков препинания и приведения к нижнему регистру
std::string normalizeWord(const std::string &word) {
    std::string normalized;
    for (char ch : word) {
        if (std::isalnum(static_cast<unsigned char>(ch))) { // Проверяем, является ли символ буквой или цифрой
            normalized += std::tolower(static_cast<unsigned char>(ch));
        }
    }
    return normalized;
}

Dictionary<std::string, std::vector<int>> buildAlphabeticalIndexFromFile(
    const std::string &inputFilePath,
    int pageSize,
    bool sizeInWords,
    const std::string &outputFilePath) {
    
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

    std::cout << inputText << std::endl;
    // Разбиение текста на слова
    std::istringstream wordsStream(inputText);
    std::vector<std::string> words;
    std::string word;
    while (wordsStream >> word) {
        words.push_back(word);
    }

    int pageCount = 1; // Номер текущей страницы
    int currentSize = 0; // Текущий размер страницы (в словах или символах)

    // Разделение списка слов на страницы
    for (const std::string &currentWord : words) {
        size_t wordSize = sizeInWords ? 1 : currentWord.length();

        // Проверяем, умещается ли слово на текущей странице
        if ((sizeInWords && currentSize + wordSize > pageSize) ||
            (!sizeInWords && currentSize + wordSize + (currentSize > 0 ? 1 : 0) > pageSize)) {
            // Если страница заполнена, увеличиваем номер страницы
            pageCount++;
            currentSize = 0;
        }

        // Добавляем слово на текущую страницу
        if (index.contains(currentWord)) {
            std::vector<int> &pages = index.get(currentWord);
            if (pages.empty() || pages.back() != pageCount) {
                pages.push_back(pageCount); // Избегаем дублирования номеров страниц
            }
        } else {
            index.add(currentWord, {pageCount});
        }

        // Увеличиваем текущий размер страницы
        currentSize += wordSize + (currentSize > 0 ? 1 : 0); // +1 для пробела
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

int main() {
    try {
        // Настройки
        std::string inputFilePath = "/Users/vitalijkoldasev/Desktop/laboratories_3_sem/laboratory3/laboratory3/input.txt";
        std::string outputFilePath = "/Users/vitalijkoldasev/Desktop/laboratories_3_sem/laboratory3/laboratory3/output.txt";
        int pageSize = 100; // Размер страницы
        bool sizeInWords = true; // Измерение страницы в словах

        // Создание алфавитного указателя
        buildAlphabeticalIndexFromFile(inputFilePath, pageSize, sizeInWords, outputFilePath);

        std::cout << "Алфавитный указатель успешно создан и сохранён в " << outputFilePath << std::endl;
    } catch (const std::exception &ex) {
        std::cerr << "Ошибка: " << ex.what() << std::endl;
    }

    return 0;
}



