#include <bits/stdc++.h>
using namespace std;

void addEdge(vector<pair<int, int>> adj[], int u, int v, int wt) {
    adj[u].emplace_back(v, wt);
    adj[v].emplace_back(u, wt);
}

void dijkstra(vector<pair<int, int>> adj[], int V, int src) {
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
    vector<int> dist(V, INT_MAX);

    pq.emplace(0, src);
    dist[src] = 0;

    while (!pq.empty()) {
        int u = pq.top().second;
        pq.pop();

        for (auto &[v, weight] : adj[u]) {
            if (dist[v] > dist[u] + weight) {
                dist[v] = dist[u] + weight;
                pq.emplace(dist[v], v);
            }
        }
    }

    cout << "Vertex\tDistance from Source\n";
    for (int i = 0; i < V; ++i)
        cout << i << "\t\t" << dist[i] << "\n";
}

int main() {
    int V = 9;
    vector<pair<int, int>> adj[V];

    vector<tuple<int, int, int>> edges = {
        {0, 1, 4}, {0, 7, 8}, {1, 2, 8}, {1, 7, 11}, {2, 3, 7}, {2, 8, 2},
        {2, 5, 4}, {3, 4, 9}, {3, 5, 14}, {4, 5, 10}, {5, 6, 2}, {6, 7, 1},
        {6, 8, 6}, {7, 8, 7}};

    for (auto &[u, v, w] : edges)
        addEdge(adj, u, v, w);

    dijkstra(adj, V, 0);
    return 0;
}
