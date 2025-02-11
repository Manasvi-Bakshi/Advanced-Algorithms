#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
using namespace std;

int getSum(vector<int> &f, int i, int j) {
    int s = 0;
    for (int k = i; k <= j; k++) s += f[k];
    return s;
}

int minCost(vector<int> &f, int i, int j, vector<vector<int>> &dp) {
    if (j < i) return 0;
    if (i == j) return f[i];
    if (dp[i][j] != -1) return dp[i][j];

    int sum = getSum(f, i, j), res = INT_MAX;
    for (int r = i; r <= j; r++) {
        res = min(res, minCost(f, i, r - 1, dp) + minCost(f, r + 1, j, dp));
    }
    return dp[i][j] = res + sum;
}

int optBST(vector<int> &keys, vector<int> &f) {
    int n = keys.size();
    vector<vector<int>> dp(n, vector<int>(n, -1));
    return minCost(f, 0, n - 1, dp);
}

int main() {
    vector<int> keys = {10, 12, 20}, f = {34, 8, 50};
    cout << optBST(keys, f);
    return 0;
}
