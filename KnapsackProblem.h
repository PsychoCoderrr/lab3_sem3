#ifndef LAB3_KNAPSACK_PROBLEM
#define LAB3_KNAPSACK_PROBLEM

#include "RBTree.h"

struct Item {
    int weight;
    int value;
    double valuePerWeight() const {
        return static_cast<double>(value) / weight;
    }
};


struct State {
    int currentWeight;
    int currentValue;
    std::vector<int> usedItems;

    // Для сравнения состояний в красно-черном дереве
    bool operator<(const State& other) const {
        if (currentWeight != other.currentWeight)
            return currentWeight < other.currentWeight;
        return currentValue < other.currentValue;
    }
    

    // Оператор равенства для сравнения состояний
    bool operator==(const State& other) const {
        return currentWeight == other.currentWeight &&
               currentValue == other.currentValue &&
               usedItems == other.usedItems;
    }
};

class KnapsackSolver {
private:
    int capacity;
    std::vector<Item> items;
    RedBlackTree<State, int> stateTree; // Хранение уникальных состояний
    int maxValue;

    void dfs(State state) {
        // Если превышен вес рюкзака, выходим
        if (state.currentWeight > capacity) return;

        // Проверяем и обновляем максимальное значение
        maxValue = std::max(maxValue, state.currentValue);

        // Добавляем состояние в дерево (если оно уникально)
        if (stateTree.find(state) != stateTree.getNil()) return; // Уникальность
        stateTree.insert(state, state.currentValue);

        // Пробуем добавить каждый предмет
        for (int i = 0; i < items.size(); ++i) {
            if (std::find(state.usedItems.begin(), state.usedItems.end(), i) != state.usedItems.end())
                continue; // Пропускаем уже использованные предметы

            State nextState = state;
            nextState.currentWeight += items[i].weight;
            nextState.currentValue += items[i].value;
            nextState.usedItems.push_back(i);
            dfs(nextState); // Рекурсивно углубляемся
        }
    }

public:
    KnapsackSolver(int capacity, const std::vector<Item>& items)
        : capacity(capacity), items(items), maxValue(0) {
        // Сортируем предметы по ценности на единицу веса
        std::sort(this->items.begin(), this->items.end(), [](const Item& a, const Item& b) {
            return a.valuePerWeight() > b.valuePerWeight();
        });
    }

    int solve() {
        State initialState = {0, 0, {}};
        dfs(initialState);
        return maxValue;
    }
};



#endif //LAB3_KNAPSACK_PROBLEM

