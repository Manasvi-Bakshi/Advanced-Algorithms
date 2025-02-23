#include <bits/stdc++.h>
using namespace std;

bool solve(int row, vector<int>& cols, vector<int>& leftDiag, 
           vector<int>& rightDiag, vector<int>& result) {
    int n = cols.size();
    if (row == n) return true;

    for (int col = 0; col < n; col++) {
        if (cols[col] || rightDiag[row + col] || leftDiag[row - col + n - 1]) 
            continue;
        
        cols[col] = rightDiag[row + col] = leftDiag[row - col + n - 1] = 1;
        result.push_back(col + 1);

        if (solve(row + 1, cols, leftDiag, rightDiag, result)) return true;

        result.pop_back();
        cols[col] = rightDiag[row + col] = leftDiag[row - col + n - 1] = 0;
    }
    return false;
}

vector<int> nQueen(int n) {
    vector<int> cols(n, 0), leftDiag(2 * n, 0), rightDiag(2 * n, 0), result;
    return solve(0, cols, leftDiag, rightDiag, result) ? result : vector<int>{-1};
}

int main() {
    int n = 4;
    vector<int> ans = nQueen(n);
    for (int pos : ans)
        cout << pos << " ";
    return 0;
}
