#include <bits/stdc++.h>
using namespace std;

void rabinKarpSearch(string pattern, string text, int prime) {
    int patternLen = pattern.size();
    int textLen = text.size();
    int patternHash = 0, textHash = 0, hashBase = 1;
    int alphabetSize = 256; 

    for (int i = 0; i < patternLen - 1; i++)
        hashBase = (hashBase * alphabetSize) % prime;

    for (int i = 0; i < patternLen; i++) {
        patternHash = (alphabetSize * patternHash + pattern[i]) % prime;
        textHash = (alphabetSize * textHash + text[i]) % prime;
    }

    for (int i = 0; i <= textLen - patternLen; i++) {
        if (patternHash == textHash) {
            int j = 0;
            while (j < patternLen && text[i + j] == pattern[j])
                j++;
            if (j == patternLen)
                cout << "Pattern found at index " << i << endl;
        }

        if (i < textLen - patternLen) {
            textHash = (alphabetSize * (textHash - text[i] * hashBase) + text[i + patternLen]) % prime;
            if (textHash < 0)
                textHash += prime;
        }
    }
}

int main() {
    string text = "GEEKS FOR GEEKS";
    string pattern = "GEEK";
    int prime = INT_MAX; 
    rabinKarpSearch(pattern, text, prime);
    return 0;
}
