#include <iostream>
#include <vector>

using namespace std;

class Graph {
public:
    int V; 
    int E;  
    vector<vector<bool>> adjMatrix;  

    Graph(int v, int e) : V(v), E(e), adjMatrix(v, vector<bool>(v, false)) {}

    bool canAddEdge(int u, int v) {
        if (u < 0 || v < 0 || u >= V || v >= V || u == v || adjMatrix[u][v] || adjMatrix[v][u])
            return false;
        return true;
    }

    int countGraphs() {
        vector<bool> visited(V, false);
        return countGraphsUtil(0, visited);
    }

private:
    int countGraphsUtil(int v, vector<bool>& visited) {
        if (v == V) {
            return 1;  
        }

        int count = 0;

        for (int u = 0; u < V; ++u) {
            if (!visited[u]) {
                for (int i = 0; i < V; ++i) {
                    if (!visited[i] && canAddEdge(u, i)) {
                        adjMatrix[u][i] = adjMatrix[i][u] = true;
                        visited[u] = visited[i] = true;
                        count += countGraphsUtil(v + 2, visited);
                        visited[u] = visited[i] = false;
                        adjMatrix[u][i] = adjMatrix[i][u] = false;
                    }
                }
            }
        }

        return count;
    }
};

int main() {
    int V, E;

    cout << "Enter the number of vertices (V): ";
    cin >> V;

    cout << "Enter the number of edges (E): ";
    cin >> E;

    if (E < V - 1 || E >(V * (V - 1)) / 2) {
        cout << "Invalid input. Number of edges should be between " << V - 1 << " and " << (V * (V - 1)) / 2 << ".\n";
        return 1;
    }

    Graph graph(V, E);

    int count = graph.countGraphs();
    cout << "Number of different undirected graphs with " << V << " vertices and " << E << " edges: " << count << endl;

    return 0;
}
