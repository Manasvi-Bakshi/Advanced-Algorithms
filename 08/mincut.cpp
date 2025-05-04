#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

struct Edge { int src, dest; };
struct Graph {
    int V, E;
    Edge* edge;
};

struct subset {
    int parent, rank;
};

int find(subset subsets[], int i) {
    if (subsets[i].parent != i)
        subsets[i].parent = find(subsets, subsets[i].parent);
    return subsets[i].parent;
}

void Union(subset subsets[], int x, int y) {
    int xroot = find(subsets, x);
    int yroot = find(subsets, y);
    if (subsets[xroot].rank < subsets[yroot].rank)
        subsets[xroot].parent = yroot;
    else if (subsets[xroot].rank > subsets[yroot].rank)
        subsets[yroot].parent = xroot;
    else {
        subsets[yroot].parent = xroot;
        subsets[xroot].rank++;
    }
}


int kargerMinCut(Graph* graph) {
    int V = graph->V, E = graph->E;
    Edge* edge = graph->edge;
    subset* subsets = new subset[V];

    for (int v = 0; v < V; ++v)
        subsets[v] = {v, 0};

    int vertices = V;
    while (vertices > 2) {
        int i = rand() % E;
        int u = find(subsets, edge[i].src);
        int v = find(subsets, edge[i].dest);
        if (u == v) continue;
        vertices--;
        Union(subsets, u, v);
    }

    int cutEdges = 0;
    for (int i = 0; i < E; i++) {
        int u = find(subsets, edge[i].src);
        int v = find(subsets, edge[i].dest);
        if (u != v) cutEdges++;
    }

    delete[] subsets;
    return cutEdges;
}

Graph* createGraph(int V, int E) {
    Graph* graph = new Graph;
    graph->V = V;
    graph->E = E;
    graph->edge = new Edge[E];
    return graph;
}

int main() {
    int V = 4, E = 5;
    Graph* graph = createGraph(V, E);

    graph->edge[0] = {0, 1};
    graph->edge[1] = {0, 2};
    graph->edge[2] = {0, 3};
    graph->edge[3] = {1, 3};
    graph->edge[4] = {2, 3};

    srand(time(NULL));
    cout << "Cut found by Karger's algorithm: " << kargerMinCut(graph) << endl;

    delete[] graph->edge;
    delete graph;
    return 0;
}

