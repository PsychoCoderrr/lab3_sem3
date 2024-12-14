cmake_minimum_required(VERSION 3.16)
project(MyProject LANGUAGES CXX)

# Укажите стандарт C++
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Пути к ncurses
set(NCURSES_INCLUDE_DIR /opt/homebrew/include)
set(NCURSES_LIBRARY_DIR /opt/homebrew/lib)

# Укажите исходные файлы
set(SOURCE_FILES
    main.cpp
    # Заголовочные файлы
    AlphabetIndex.h
    Dictionary.h
    HashTable.h
    KnapsackProblem.h
    MostFrequent.h
    RBTree.h
    FuncForUI.h
    tests.h
    ArraySequence.h
    ArrayIterator.h
    Sequence.h
)

# Добавляем исполняемый файл
add_executable(${PROJECT_NAME} ${SOURCE_FILES})



# Указываем, где искать заголовочные файлы

include_directories(${NCURSES_INCLUDE_DIR})


# Линкуем библиотеку SDL2

target_link_directories(${PROJECT_NAME} PRIVATE ${NCURSES_LIBRARY_DIR})


target_link_libraries(${PROJECT_NAME} ncurses)
