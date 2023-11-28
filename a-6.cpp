#include <iostream>
#include <vector>

using namespace std;

class Graph {
    int V;
    vector<vector<int>> adj;

public:
    Graph(int vertices) : V(vertices) {
        adj.resize(V, vector<int>());
    }

    void addEdge(int u, int v) {
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    void DFS(int v, vector<bool>& visited) {
        visited[v] = true;
        for (int i : adj[v]) {
            if (!visited[i]) {
                DFS(i, visited);
            }
        }
    }

    bool isEdgeConnected() {
        if (V <= 1) {
            return true; 
        }

        for (int i = 0; i < V; ++i) {
            for (int j : adj[i]) {
                int temp = adj[i][j];
                adj[i].erase(adj[i].begin() + j);
                adj[j].erase(remove(adj[j].begin(), adj[j].end(), i), adj[j].end());

                vector<bool> visited(V, false);
                DFS(0, visited);

                adj[i].insert(adj[i].begin() + j, temp);
                adj[j].push_back(i);

                if (find(visited.begin(), visited.end(), false) != visited.end()) {
                    return false;
                }
            }
        }

        return true;
    }
};

int main() {
    Graph g(5);
    g.addEdge(0, 1);
    g.addEdge(1, 2);
    g.addEdge(2, 3);
    g.addEdge(3, 0);
    g.addEdge(3, 4);

    bool isEdgeConnected = g.isEdgeConnected();

    if (isEdgeConnected) {
        cout << "Graph is edge connected." << endl;
    }
    else {
        cout << "Graph is not edge connected." << endl;
    }

    return 0;
}
