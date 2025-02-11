#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int solve(int i, vector<vector<int>> &jobs, vector<int> &dp) {
    if (i == jobs.size()) return 0;
    if (dp[i] != -1) return dp[i];

    int profit = jobs[i][2];

    int nxt = lower_bound(jobs.begin(), jobs.end(), vector<int>{jobs[i][1], 0, 0}) - jobs.begin();
    profit += solve(nxt, jobs, dp);

    return dp[i] = max(profit, solve(i + 1, jobs, dp));
}

int maxProfit(vector<vector<int>> &jobs) {
    sort(jobs.begin(), jobs.end(), [](auto &a, auto &b) { return a[1] < b[1]; }); 
    vector<int> dp(jobs.size(), -1);
    return solve(0, jobs, dp);
}

int main() {
    vector<vector<int>> jobs = {{1, 2, 50}, {3, 5, 20}, {6, 19, 100}, {2, 100, 200}};
    cout << maxProfit(jobs) << endl;
    return 0;
}
