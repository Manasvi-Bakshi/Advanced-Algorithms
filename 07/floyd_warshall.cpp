#include <bits/stdc++.h>
using namespace std;

void floydWarshall(vector<vector<int>> &graph) {
    int V = graph.size();
    
    for (int k = 0; k < V; k++)
        for (int i = 0; i < V; i++)
            for (int j = 0; j < V; j++)
                if (graph[i][k] != -1 && graph[k][j] != -1 &&
                    (graph[i][j] == -1 || graph[i][j] > graph[i][k] + graph[k][j]))
                    graph[i][j] = graph[i][k] + graph[k][j];
}

int main() {
    vector<vector<int>> graph = {
        {0, 4, -1, 5, -1},
        {-1, 0, 1, -1, 6},
        {2, -1, 0, 3, -1},
        {-1, -1, 1, 0, 2},
        {1, -1, -1, 4, 0}
    };

    floydWarshall(graph);

    for (const auto &row : graph) {
        for (int val : row)
            cout << val << " ";
        cout << "\n";
    }
    return 0;
}
