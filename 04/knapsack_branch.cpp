#include <bits/stdc++.h>
using namespace std;

struct Item {
    float weight;
    int value;
};

struct Node {
    int level, profit, bound;
    float weight;
};

bool compare(Item a, Item b) {
    return (double)a.value / a.weight > (double)b.value / b.weight;
}

int getBound(Node node, int n, int capacity, Item items[]) {
    if (node.weight >= capacity) return 0;

    int profit_bound = node.profit;
    int index = node.level + 1;
    float total_weight = node.weight;

    while (index < n && total_weight + items[index].weight <= capacity) {
        total_weight += items[index].weight;
        profit_bound += items[index].value;
        index++;
    }

    if (index < n)
        profit_bound += (capacity - total_weight) * (items[index].value / items[index].weight);

    return profit_bound;
}

int knapsack(int capacity, Item items[], int n) {
    sort(items, items + n, compare);
    queue<Node> q;
    Node curr, next;
    curr.level = -1;
    curr.profit = curr.weight = 0;
    q.push(curr);

    int max_profit = 0;

    while (!q.empty()) {
        curr = q.front();
        q.pop();

        if (curr.level == n - 1) continue;

        next.level = curr.level + 1;
        next.weight = curr.weight + items[next.level].weight;
        next.profit = curr.profit + items[next.level].value;

        if (next.weight <= capacity && next.profit > max_profit)
            max_profit = next.profit;

        next.bound = getBound(next, n, capacity, items);

        if (next.bound > max_profit)
            q.push(next);

        next.weight = curr.weight;
        next.profit = curr.profit;
        next.bound = getBound(next, n, capacity, items);

        if (next.bound > max_profit)
            q.push(next);
    }

    return max_profit;
}

int main() {
    int capacity = 10;
    Item items[] = {{2, 40}, {3.14, 50}, {1.98, 100}, {5, 95}, {3, 30}};
    int n = sizeof(items) / sizeof(items[0]);

    cout << "Maximum possible profit = " << knapsack(capacity, items, n) << endl;
    return 0;
}
