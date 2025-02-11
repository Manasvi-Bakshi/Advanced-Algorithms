#include <iostream>
#include <algorithm>
using namespace std;

struct Item {
    int p, w;
    Item(int p, int w) : p(p), w(w) {}
};

bool cmp(Item a, Item b) {
    return (double)a.p / a.w > (double)b.p / b.w;
}

double maxProfit(int W, Item arr[], int n) {
    sort(arr, arr + n, cmp);
    double res = 0.0;

    for (int i = 0; i < n; i++) {
        if (arr[i].w <= W) {
            W -= arr[i].w;
            res += arr[i].p;
        } else {
            res += arr[i].p * ((double)W / arr[i].w);
            break;
        }
    }
    return res;
}

int main() {
    int W = 50;
    Item arr[] = {{60, 10}, {100, 20}, {120, 30}};
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << maxProfit(W, arr, n);
    return 0;
}
