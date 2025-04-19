#include <bits/stdc++.h>
using namespace std;

class DSU {
    vector<int> parent, rank;

public:
    DSU(int n) {
        parent.resize(n);
        rank.resize(n, 1);
        iota(parent.begin(), parent.end(), 0);
    }

    int find(int i) {
        return (parent[i] == i) ? i : (parent[i] = find(parent[i]));
    }

    void unite(int x, int y) {
        int rx = find(x), ry = find(y);
        if (rx == ry) return;
        if (rank[rx] < rank[ry]) parent[rx] = ry;
        else {
            parent[ry] = rx;
            if (rank[rx] == rank[ry]) rank[rx]++;
        }
    }
};

int kruskalsMST(int V, vector<vector<int>> &edges) {
    sort(edges.begin(), edges.end(), [](auto &a, auto &b) {
        return a[2] < b[2];
    });

    DSU dsu(V);
    int cost = 0, count = 0;

    for (auto &e : edges) {
        int u = e[0], v = e[1], w = e[2];
        if (dsu.find(u) != dsu.find(v)) {
            dsu.unite(u, v);
            cost += w;
            if (++count == V - 1) break;
        }
    }
    return cost;
}

int main() {
    vector<vector<int>> edges = {
        {0, 1, 10}, {1, 3, 15}, {2, 3, 4}, {2, 0, 6}, {0, 3, 5}
    };

    cout << kruskalsMST(4, edges) << endl;
    return 0;
}
