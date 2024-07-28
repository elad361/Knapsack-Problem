#include "KnapsackProblem.hpp"

using namespace std;

int main() {
    vector<Item> items {
        {5, 4},
        {4, 3},
        {3, 2},
        {2, 1},
    };

    KnapsackProblem prob;
    int choice;
    cout << "How would you like to add items?" << endl << "1 for manulay" << endl << "2 for using existing list" << endl;
    cin >> choice;
    if (choice == 1) prob.addItems();
    else prob.addVectorOfItems(items);
    
    prob.displayItems();

    // weight limit
    int weight;
    cout << endl << "Enter weight limit:" << endl;
    cin >> weight;

    vector<Item> solotion = prob.solve(weight);
    for (const auto& item : solotion) {
        cout << "Value: " << item.value  << ", Weight: " << item.weight << endl;
    }
    return 0;
}
