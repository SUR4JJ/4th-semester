#include <iostream>
#include <algorithm>
using namespace std;

const int N = 30;  // Number of items

typedef struct {
    int index, profit, weight;
    double profitPerWeight;
} Item;

// Sorting by non-increasing profit
bool compareByProfit(Item a, Item b) {
    return a.profit > b.profit;
}

// Sorting by non-decreasing weight
bool compareByWeight(Item a, Item b) {
    return a.weight < b.weight;
}

// Sorting by non-increasing profit/weight ratio
bool compareByProfitPerWeight(Item a, Item b) {
    return a.profitPerWeight > b.profitPerWeight;
}

// Function to compute maximum profit based on given sorting criteria
void knapsack(Item items[], int capacity) {
    int C = capacity;
    double totalProfit = 0.0;
    
    for (int i = 0; i < N; i++) {
        if (items[i].weight <= C) {
            totalProfit += items[i].profit;
            C -= items[i].weight;
        } else {  // Taking fraction of item
            totalProfit += items[i].profitPerWeight * C;
            break;
        }
    }
    cout << "Total Profit: " << totalProfit << endl;
}

int main() {
    int capacity = 100;
    Item items[N];

    // Initializing items
    for (int i = 0; i < N; i++) {
        items[i].index = i + 1;
        items[i].profit = rand() % 20 + 1;
        items[i].weight = rand() % 20 + 1;
        items[i].profitPerWeight = (double)items[i].profit / items[i].weight;
    }
    
    cout << "Sorting by Profit (Non-Increasing Order):\n";
    sort(items, items + N, compareByProfit);
    knapsack(items, capacity);
    
    cout << "Sorting by Weight (Non-Decreasing Order):\n";
    sort(items, items + N, compareByWeight);
    knapsack(items, capacity);
    
    cout << "Sorting by Profit/Weight Ratio (Non-Increasing Order):\n";
    sort(items, items + N, compareByProfitPerWeight);
    knapsack(items, capacity);
    
    return 0;
}
