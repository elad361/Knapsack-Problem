#pragma once
#include <iostream>
#include <string>
#include <list>
#include <vector>

using namespace std;


struct Item {
    int value;
    int weight;
};

class KnapsackProblem {
private:
    vector<Item> items;
public:
    KnapsackProblem() {}

    // Print the set of items
    void displayItems();

    // Add items manualy
    void addItems();

    // Add items by a given vector
    void addVectorOfItems(const vector<Item>& vec);

    // Solve problem using Dynamic Programming
    vector<Item> solve();
};