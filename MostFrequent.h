#ifndef LAB3_MOST_FREQUENT
#define LAB3_MOST_FREQUENT
#include "Dictionary.h"

Dictionary<std::string, int> theMostFrequentSubsequences(const std::string &input, int lmin, int lmax) {
    Dictionary<std::string, int> result;

    for (int i = 0; i < input.length(); i++) {
        for (int j = lmin; j <= lmax; j++) {
            if (i + j <= input.length()) {
                std::string word = input.substr(i, j);
                if (result.contains(word)) {
                    result.get(word) += 1; // Увеличиваем значение
                } else {
                    result.add(word, 1); // Добавляем новую запись
                }
            }
        }
    }

    return result;
}

#endif //LAB3_MOST_FREQUENT

