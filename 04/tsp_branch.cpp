#include <bits/stdc++.h>
using namespace std;

const int SIZE = 4;
int best_path[SIZE + 1];
bool visited[SIZE];
int min_cost = INT_MAX;

void savePath(int temp_path[]) {
    for (int i = 0; i < SIZE; i++)
        best_path[i] = temp_path[i];
    best_path[SIZE] = temp_path[0];
}

int getMinEdge(int graph[SIZE][SIZE], int node) {
    int min_edge = INT_MAX;
    for (int i = 0; i < SIZE; i++)
        if (graph[node][i] < min_edge && node != i)
            min_edge = graph[node][i];
    return min_edge;
}

int getSecondMinEdge(int graph[SIZE][SIZE], int node) {
    int first = INT_MAX, second = INT_MAX;
    for (int i = 0; i < SIZE; i++) {
        if (node == i) continue;
        if (graph[node][i] <= first) {
            second = first;
            first = graph[node][i];
        } else if (graph[node][i] <= second && graph[node][i] != first) {
            second = graph[node][i];
        }
    }
    return second;
}

void findRoute(int graph[SIZE][SIZE], int bound, int weight, int level, int temp_path[]) {
    if (level == SIZE) {
        if (graph[temp_path[level - 1]][temp_path[0]] != 0) {
            int total_cost = weight + graph[temp_path[level - 1]][temp_path[0]];
            if (total_cost < min_cost) {
                savePath(temp_path);
                min_cost = total_cost;
            }
        }
        return;
    }

    for (int i = 0; i < SIZE; i++) {
        if (graph[temp_path[level - 1]][i] != 0 && !visited[i]) {
            int temp_bound = bound;
            weight += graph[temp_path[level - 1]][i];

            if (level == 1)
                bound -= (getMinEdge(graph, temp_path[level - 1]) + getMinEdge(graph, i)) / 2;
            else
                bound -= (getSecondMinEdge(graph, temp_path[level - 1]) + getMinEdge(graph, i)) / 2;

            if (bound + weight < min_cost) {
                temp_path[level] = i;
                visited[i] = true;
                findRoute(graph, bound, weight, level + 1, temp_path);
            }

            weight -= graph[temp_path[level - 1]][i];
            bound = temp_bound;

            memset(visited, false, sizeof(visited));
            for (int j = 0; j <= level - 1; j++)
                visited[temp_path[j]] = true;
        }
    }
}

void solveTSP(int graph[SIZE][SIZE]) {
    int temp_path[SIZE + 1];
    int bound = 0;

    memset(temp_path, -1, sizeof(temp_path));
    memset(visited, 0, sizeof(visited));

    for (int i = 0; i < SIZE; i++)
        bound += (getMinEdge(graph, i) + getSecondMinEdge(graph, i));

    bound = (bound & 1) ? bound / 2 + 1 : bound / 2;

    visited[0] = true;
    temp_path[0] = 0;

    findRoute(graph, bound, 0, 1, temp_path);
}

int main() {
    int graph[SIZE][SIZE] = { {0, 10, 15, 20},
                              {10, 0, 35, 25},
                              {15, 35, 0, 30},
                              {20, 25, 30, 0} };

    solveTSP(graph);

    cout << "Minimum cost: " << min_cost << endl;
    cout << "Path Taken: ";
    for (int i = 0; i <= SIZE; i++)
        cout << best_path[i] << " ";
    cout << endl;

    return 0;
}
