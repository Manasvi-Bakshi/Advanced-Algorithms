#include <bits/stdc++.h>
using namespace std;

int nextFit(int w[], int n, int c) {
    int bins = 0, rem = c;
    for (int i = 0; i < n; i++) {
        if (w[i] > rem) {
            bins++;
            rem = c - w[i];
        } else {
            rem -= w[i];
        }
    }
    return bins;
}

int firstFit(int w[], int n, int c) {
    int bins = 0, rem[n];
    for (int i = 0; i < n; i++) {
        int j;
        for (j = 0; j < bins; j++) {
            if (rem[j] >= w[i]) {
                rem[j] -= w[i];
                break;
            }
        }
        if (j == bins) {
            rem[bins] = c - w[i];
            bins++;
        }
    }
    return bins;
}

int bestFit(int w[], int n, int c) {
    int bins = 0, rem[n];
    for (int i = 0; i < n; i++) {
        int min = c + 1, bi = 0;
        for (int j = 0; j < bins; j++) {
            if (rem[j] >= w[i] && rem[j] - w[i] < min) {
                bi = j;
                min = rem[j] - w[i];
            }
        }
        if (min == c + 1) {
            rem[bins] = c - w[i];
            bins++;
        } else {
            rem[bi] -= w[i];
        }
    }
    return bins;
}

int worstFit(int w[], int n, int c) {
    int bins = 0, rem[n];
    for (int i = 0; i < n; i++) {
        int mx = -1, wi = 0;
        for (int j = 0; j < bins; j++) {
            if (rem[j] >= w[i] && rem[j] - w[i] > mx) {
                wi = j;
                mx = rem[j] - w[i];
            }
        }
        if (mx == -1) {
            rem[bins] = c - w[i];
            bins++;
        } else {
            rem[wi] -= w[i];
        }
    }
    return bins;
}

int firstFitDec(int w[], int n, int c) {
    sort(w, w + n, greater<int>());
    return firstFit(w, n, c);
}

int main() {
    int w[] = { 2, 5, 4, 7, 1, 3, 8 };
    int c = 10;
    int n = sizeof(w) / sizeof(w[0]);
    cout << "Next Fit Bins: " << nextFit(w, n, c) << endl;
    cout << "First Fit Bins: " << firstFit(w, n, c) << endl;
    cout << "Best Fit Bins: " << bestFit(w, n, c) << endl;
    cout << "Worst Fit Bins: " << worstFit(w, n, c) << endl;
    cout << "First Fit Decreasing Bins: " << firstFitDec(w, n, c) << endl;
    return 0;
}
