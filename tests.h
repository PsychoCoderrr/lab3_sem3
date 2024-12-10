#ifndef LAB3_TESTS
#define LAB3_TESTS
#include <iostream>
#include <cassert>
#include "RBTree.h"
#include "KnapsackProblem.h"

void testInsertAndSearch() {
    RedBlackTree<int, std::string> tree;
    tree.insert(10, "Data1");
    tree.insert(20, "Data2");
    tree.insert(5, "Data3");
    tree.insert(15, "Data4");
    tree.insert(25, "Data5");

    assert(tree.find(10)->key == 10);
    assert(tree.find(20)->key == 20);
    assert(tree.find(5)->key == 5);
    assert(tree.find(15)->key == 15);
    assert(tree.find(25)->key == 25);

    assert(tree.find(30) == tree.getNil());
}

void testRemove() {
    RedBlackTree<int, std::string> tree;
    tree.insert(10, "Data1");
    tree.insert(20, "Data2");
    tree.insert(5, "Data3");

    tree.remove(20);
    assert(tree.find(20) == tree.getNil());

    tree.remove(10);
    assert(tree.find(10) == tree.getNil());

    tree.remove(5);
    assert(tree.find(5) == tree.getNil());

    std::cout << "Test Remove passed!" << std::endl;
}

void testKnapsack1()
{
    std::vector<Item> items;
    Item item1(10, 60);
    Item item2(20, 100);
    Item item3(30,120);
    items.push_back(item1);
    items.push_back(item2);
    items.push_back(item3);
    int capacity = 50;
    int result = KnapsackProblemSolving(items, capacity);
    assert(result == 220);
}

void testKnapsack2()
{
    std::vector<Item> items;
    Item item1(5, 10);
    Item item2(5, 10);
    Item item3(5, 10);
    Item item4(10, 30);
    Item item5(15,45);
    items.push_back(item1);
    items.push_back(item2);
    items.push_back(item3);
    items.push_back(item4);
    items.push_back(item5);
    int capacity = 20;
    int result = KnapsackProblemSolving(items, capacity);
    assert(result == 55);
}

void testKnapsack3()
{
    std::vector<Item> items;
    Item item1(60, 100);
    Item item2(10, 20);
    Item item3(20, 50);
    Item item4(30, 60);
    items.push_back(item1);
    items.push_back(item2);
    items.push_back(item3);
    items.push_back(item4);
    int capacity = 50;
    int result = KnapsackProblemSolving(items, capacity);
    assert(result == 110);
}

void testKnapsack4()
{
    std::vector<Item> items;
    Item item1(1, 10);
    Item item2(2, 20);
    Item item3(3, 30);
    Item item4(4, 40);
    Item item5(5, 50);
    items.push_back(item1);
    items.push_back(item2);
    items.push_back(item3);
    items.push_back(item4);
    items.push_back(item5);
    int capacity = 15;
    int result = KnapsackProblemSolving(items, capacity);
    assert(result == 150);
}

void testKnapsack5()
{
    std::vector<Item> items;
    Item item1(10, 60);
    Item item2(20, 100);
    Item item3(30,120);
    items.push_back(item1);
    items.push_back(item2);
    items.push_back(item3);
    int capacity = 25;
    int result = KnapsackProblemSolving(items, capacity);
    assert(result == 100);
}

void testKnapsack6()
{
    std::vector<Item> items;
    Item item1(10, 10);
    Item item2(10, 20);
    Item item3(10, 30);
    Item item4(10, 40);
    items.push_back(item1);
    items.push_back(item2);
    items.push_back(item3);
    items.push_back(item4);
    int capacity = 20;
    int result = KnapsackProblemSolving(items, capacity);
    assert(result == 70);
}

void testKnapsack7()
{
    std::vector<Item> items;
    Item item1(1, 1);
    Item item2(2, 2);
    Item item3(3, 3);
    Item item4(4, 4);
    Item item5(5, 5);
    Item item6(6, 6);
    Item item7(7, 7);
    Item item8(8, 8);
    Item item9(9, 9);
    Item item10(10, 10);
    items.push_back(item1);
    items.push_back(item2);
    items.push_back(item3);
    items.push_back(item4);
    items.push_back(item5);
    items.push_back(item6);
    items.push_back(item7);
    items.push_back(item8);
    items.push_back(item9);
    items.push_back(item10);
    int capacity = 15;
    int result = KnapsackProblemSolving(items, capacity);
    assert(result == 15);
}

#endif //LAB3_TESTS
