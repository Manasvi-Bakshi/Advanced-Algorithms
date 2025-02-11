#include <iostream>
#include <vector>
using namespace std;

int knapSack(int W, vector<int>& wt, vector<int>& val) {
    int n = wt.size();
    vector<vector<int>> dp(n + 1, vector<int>(W + 1));

    for (int i = 1; i <= n; i++) {
        for (int w = 0; w <= W; w++) {
            dp[i][w] = dp[i - 1][w];  
            if (wt[i - 1] <= w)
                dp[i][w] = max(dp[i][w], val[i - 1] + dp[i - 1][w - wt[i - 1]]);
        }
    }
    return dp[n][W];
}

int main() {
    vector<int> val = {60, 100, 120}, wt = {10, 20, 30};
    constexpr int W = 50;

    cout << knapSack(W, wt, val) << endl;
    return 0;
}
