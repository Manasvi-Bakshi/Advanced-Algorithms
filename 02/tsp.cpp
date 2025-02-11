#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
using namespace std;

int tspUtil(int mask, int curr, int n, vector<vector<int>> &c, vector<vector<int>> &dp) {
    if (mask == (1 << n) - 1) return c[curr][0];  // All cities visited, return to start
    
    if (dp[curr][mask] != -1) return dp[curr][mask];

    int ans = INT_MAX;
    for (int i = 0; i < n; i++) {
        if (!(mask & (1 << i))) {  // If city `i` is unvisited
            ans = min(ans, c[curr][i] + tspUtil(mask | (1 << i), i, n, c, dp));
        }
    }
    return dp[curr][mask] = ans;
}

int tsp(vector<vector<int>> &c) {
    constexpr int n = 4;  
    vector<vector<int>> dp(n, vector<int>(1 << n, -1));
    return tspUtil(1, 0, n, c, dp);
}

int main() {
    vector<vector<int>> c = {{0, 10, 15, 20}, 
                             {10, 0, 35, 25}, 
                             {15, 35, 0, 30}, 
                             {20, 25, 30, 0}};

    cout << tsp(c) << endl;
    return 0;
}
