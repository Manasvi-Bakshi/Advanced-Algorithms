#include <iostream>
#include <vector>
#include <list>

using namespace std;

class Graph {
private:
    int V; // Number of vertices
    vector<list<int>> adj; // Adjacency list

public:
    // Constructor
    Graph(int vertices) : V(vertices), adj(vertices) {}

    // Add an undirected edge
    void addEdge(int u, int v) {
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    // Print an approximate vertex cover
    void printVertexCover() const {
        vector<bool> visited(V, false);

        for (int u = 0; u < V; ++u) {
            // If u is not yet visited
            if (!visited[u]) {
                for (int v : adj[u]) {
                    if (!visited[v]) {
                        // Pick the edge (u, v) and mark both as visited
                        visited[u] = true;
                        visited[v] = true;
                        break; // Move to next vertex
                    }
                }
            }
        }

        // Print the vertex cover
        cout << "Approximate Vertex Cover: ";
        for (int i = 0; i < V; ++i) {
            if (visited[i]) {
                cout << i << " ";
            }
        }
        cout << endl;
    }
};

// Driver Code
int main() {
    Graph g(7);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 3);
    g.addEdge(3, 4);
    g.addEdge(4, 5);
    g.addEdge(5, 6);

    g.printVertexCover();

    return 0;
}
