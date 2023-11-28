#include <iostream>
#include <vector>

using namespace std;

class Graph {
public:
    int V;  
    vector<vector<int>> adjList;  

    Graph(int v) : V(v), adjList(v) {}

    void addEdge(int u, int v) {
        adjList[u].push_back(v);
        adjList[v].push_back(u);
    }

    int countParallelEdges() {
        vector<int> degree(V, 0);
        int count = 0;

        for (int i = 0; i < V; ++i) {
            degree[i] = adjList[i].size();
        }

        for (int i = 0; i < V; ++i) {
            for (int j : adjList[i]) {
                if (degree[i] % 2 == 0 && degree[j] % 2 == 0) {
                    cout << "Parallel Edge: " << i << " - " << j << endl;
                    count++;
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

    Graph graph(V);

    cout << "Enter the edges (format: u v):" << endl;
    for (int i = 0; i < E; ++i) {
        int u, v;
        cin >> u >> v;
        graph.addEdge(u, v);
    }

    int parallelEdges = graph.countParallelEdges();
    cout << "Number of parallel edges: " << parallelEdges << endl;

    return 0;
}
