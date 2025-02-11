#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int maxProfit(vector<int> &p) {
    int n = p.size();
    vector<int> dp(n + 1, 0);
    
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= i; j++) {
            dp[i] = max(dp[i], p[j - 1] + dp[i - j]);
        }
    }
    return dp[n];
}

int main() {
    vector<int> p = {1, 5, 8, 9, 10, 17, 17, 20};
    cout << maxProfit(p);
    return 0;
}
