#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Item {
    int weight;
    int value;
};
bool compare(Item a, Item b) {
    return (double)a.value / a.weight >
           (double)b.value / b.weight;
}

double fractionalKnapsack(int capacity, vector<Item>& items) {
    sort(items.begin(), items.end(), compare);
    double totalValue = 0.0;
    for (auto item : items) {
        if (item.weight <= capacity) {
            capacity -= item.weight;
            totalValue += item.value;
        }
        else {
            double fraction = (double)capacity / item.weight;
            totalValue += item.value * fraction;
            capacity = 0;
            break;
        }
    }

    return totalValue;
}

int main() {
    int n, capacity;
    cout << "Enter number of items: ";
    cin >> n;
    vector<Item> items(n);

    cout << "Enter weight and value of each item:\n";
    for (int i = 0; i < n; i++) {
        cin >> items[i].weight >> items[i].value;
    }
    cout << "Enter knapsack capacity: ";
    cin >> capacity;
    double maxValue = fractionalKnapsack(capacity, items);
    cout << "\nMaximum value = " << maxValue << endl;

    return 0;
}