#include <bits/stdc++.h>
using namespace std;

int knapsackUtil(vector<int>& weights, vector<int>& values, int W, int index, int currentWeight, int currentValue, int& maxProfit) {
    if (currentWeight > W) return 0;
    maxProfit = max(maxProfit, currentValue);
    if (index >= weights.size()) return maxProfit;

    knapsackUtil(weights, values, W, index + 1, currentWeight + weights[index], currentValue + values[index], maxProfit);
    knapsackUtil(weights, values, W, index + 1, currentWeight, currentValue, maxProfit);

    return maxProfit;
}

int knapsack(vector<int>& weights, vector<int>& values, int W) {
    int maxProfit = 0;
    return knapsackUtil(weights, values, W, 0, 0, 0, maxProfit);
}

int main() {
    vector<int> weights = {2, 3, 4, 5};
    vector<int> values = {3, 4, 5, 6};
    int W = 5;

    cout << "Maximum Profit: " << knapsack(weights, values, W) << endl;
    return 0;
}
