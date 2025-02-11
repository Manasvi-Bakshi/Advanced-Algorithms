#include <iostream>
#include <vector>

using namespace std;

int longestCommonSubseq(string &a, string &b, int m, int n, vector<vector<int>> &dp) {
    if (m == 0 || n == 0) return 0;
    if (dp[m][n] != -1) return dp[m][n];

    return dp[m][n] = (a[m - 1] == b[n - 1]) 
        ? 1 + longestCommonSubseq(a, b, m - 1, n - 1, dp) 
        : max(longestCommonSubseq(a, b, m, n - 1, dp), longestCommonSubseq(a, b, m - 1, n, dp));
}

int main() {
    string a = "AGGTAB", b = "GXTXAYB";
    int m = a.size(), n = b.size();
    vector<vector<int>> dp(m + 1, vector<int>(n + 1, -1));

    cout << longestCommonSubseq(a, b, m, n, dp) << endl;
    return 0;
}
