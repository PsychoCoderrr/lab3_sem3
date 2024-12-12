#ifndef LAB3_FUNC_FOR_UI
#define LAB3_FUNC_FOR_UI

#include <ncurses.h>


// Отображение главного меню
void displayMenu(int highlight) {
    clear();
    const char *options[] = {"Alphabet index", "The most frequent sequence", "Knapsack Problem Solving", "Testing"};
    int numOptions = sizeof(options) / sizeof(options[0]);

    mvprintw(0, 0, "Choose the func and press Enter:");

    for (int i = 0; i < numOptions; i++) {
        if (i == highlight) {
            attron(A_REVERSE);
            mvprintw(i + 3, 0, options[i]);
            attroff(A_REVERSE);
        } else {
            mvprintw(i + 3, 0, options[i]);
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

int inputWindowKnapsackCapacity(const std::string &prompt) {
    clear();
    mvprintw(1, 1, prompt.c_str());
    mvprintw(3, 1, "Enter capacity: ");
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

int inputWindowCountOfElements(const std::string &prompt) {
    clear();
    mvprintw(1, 1, prompt.c_str());
    mvprintw(3, 1, "Enter count of elements: ");
    refresh();

    char buffer[1024];
    echo();
    getnstr(buffer, 1023); // Ограничение длины ввода
    noecho();

    return stoi(std::string(buffer));
}

std::vector<Item> inputWindowItems(const std::string &prompt, int count) {
    std::vector<Item> result;
    for(int i = 0; i < count; i++)
    {
        clear();
        mvprintw(1, 1, prompt.c_str());
        mvprintw(3, 1, "Enter weight: ");
        refresh();
        
        char buffer1[1024];
        echo();
        getnstr(buffer1, 1023); // Ограничение длины ввода
        noecho();
        
        clear();
        mvprintw(1, 1, prompt.c_str());
        mvprintw(3, 1, "Enter value: ");
        refresh();
        
        char buffer2[1024];
        echo();
        getnstr(buffer2, 1023); // Ограничение длины ввода
        noecho();
        Item temp_item(stoi(std::string(buffer1)), stoi(std::string(buffer2)));
        result.push_back(temp_item);
    }
    

    return result;
}

#endif // LAB3_FUNC_FOR_UI
