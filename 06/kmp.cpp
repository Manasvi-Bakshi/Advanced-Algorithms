#include <iostream>
#include <vector>

using namespace std;

void computeLPS(const string &pattern, vector<int> &lps) {
    int length = 0, i = 1;
    lps[0] = 0;

    while (i < pattern.length()) {
        if (pattern[i] == pattern[length]) {
            lps[i++] = ++length;
        } else {
            length ? length = lps[length - 1] : lps[i++] = 0;
        }
    }
}

vector<int> kmpSearch(const string &pattern, const string &text) {
    int i = 0, j = 0, textLen = text.length(), patternLen = pattern.length();
    vector<int> lps(patternLen), occurrences;
    
    computeLPS(pattern, lps);

    while (i < textLen) {
        if (text[i] == pattern[j]) {
            i++, j++;
            if (j == patternLen) {
                occurrences.push_back(i - j);
                j = lps[j - 1];
            }
        } else {
            j ? j = lps[j - 1] : i++;
        }
    }
    return occurrences;
}

int main() {
    string text = "aabaacaadaabaaba", pattern = "aaba";
    for (int index : kmpSearch(pattern, text))
        cout << index << " ";
    return 0;
}
