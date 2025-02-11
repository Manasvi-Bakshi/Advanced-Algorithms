#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
using namespace std;

int minMult(vector<int> &a, int i, int j, vector<vector<int>> &dp) {
    if (i + 1 == j) return 0;
    if (dp[i][j] != -1) return dp[i][j];

    int res = INT_MAX;
    for (int k = i + 1; k < j; k++) {
        res = min(res, minMult(a, i, k, dp) + minMult(a, k, j, dp) + a[i] * a[k] * a[j]);
    }
    return dp[i][j] = res;
}

int matMul(vector<int> &a) {
    int n = a.size();
    vector<vector<int>> dp(n, vector<int>(n, -1));
    return minMult(a, 0, n - 1, dp);
}

int main() {
    vector<int> a = {1, 2, 3, 4, 3};
    cout << matMul(a) << endl;
    return 0;
}
