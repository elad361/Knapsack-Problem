#include "KnapsackProblem.hpp"
#include <limits>
#include <iomanip>

using namespace std;

void KnapsackProblem::addItems() {
    int counter = 0;
    while (true) {
        int weight, value;

        cout << "Enter item value (0 to stop): ";
        cin >> value;
        if (value <= 0) {
            break;
        }
        cout << "Enter item weight: ";
        cin >> weight;

        // Ignore the remaining newline character left in the input stream
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        // Add to items
        items.push_back({value, weight});
        counter++;
    }
}


void KnapsackProblem::addVectorOfItems(const vector<Item>& vec) {
    items.insert(items.end(), vec.begin(), vec.end());
}


void KnapsackProblem::displayItems() {
    cout << "Items in set:" << endl;
    for (int i = 0; i < items.size(); i++) {
        cout <<"# " << setw(3) << setfill(' ') << left << (i + 1) << "Value: " << items[i].value  << ", Weight: " << items[i].weight << endl;
    }
}

vector<Item> KnapsackProblem::solve(int limit) {

    // number of items
    int n = items.size();

    // create matrix 
    int m[n + 1][limit + 1];

    cout << "solving..." << endl;

    //cout << endl << "*************************************************" << endl; //used to print matrix

    for (int i = 0; i <= n; ++i) {
        for (int j = 0; j <= limit; ++j) {
            if (i == 0 || j == 0) {
                m[i][j] = 0;
            }
            else if (items[i-1].weight > j) {
                m[i][j] = m[i-1][j];
            } else {
                m[i][j] = max(m[i - 1][j], m[i-1][j - items[i-1].weight] + items[i-1].value);
            }
            //cout << setw(5) << m[i][j] << " "; //used to print matrix
        }
        //cout << endl << endl; //used to print matrix
    }
    //cout << "*************************************************" << endl << endl; //used to print matrix

    cout << endl << "Maximum value in knapsack: " << m[n][limit] << endl;

    int res = limit;
    vector<Item> selected;
    for  (int i = n; i > 0; i--) {
        if (m[i][res] != m[i - 1][res]) {
            selected.push_back(items[i - 1]);
            res -= items[i - 1].weight;
        }

    }
    
    return selected;
}
