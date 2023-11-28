#include <iostream>
#include <vector>
#include <map>

using namespace std;

class Graph {
public:
    map<int, vector<int>> adjList;

    void addEdge(int u, int v) {
        adjList[u].push_back(v);
        adjList[v].push_back(u);
    }

    bool isEulerian() {
        for (auto& pair : adjList) {
            if (pair.second.size() % 2 != 0)
                return false;
        }
        return true;
    }

    bool isHamiltonian() {
        vector<bool> visited(adjList.size(), false);
        return hamiltonianUtil(0, visited, 1);
    }

private:
    bool hamiltonianUtil(int v, vector<bool>& visited, int count) {
        visited[v] = true;
        if (count == adjList.size())
            return true;

        for (int u : adjList[v]) {
            if (!visited[u]) {
                if (hamiltonianUtil(u, visited, count + 1))
                    return true;
            }
        }

        visited[v] = false;
        return false;
    }
};

int main() {
    Graph graph1, graph2, graph3, graph4;

    graph1.addEdge(0, 1);
    graph1.addEdge(0, 2);
    graph1.addEdge(0, 3);
    graph1.addEdge(1, 3);
    graph1.addEdge(1, 4);
    graph1.addEdge(2, 5);
    graph1.addEdge(2, 9);
    graph1.addEdge(3, 6);
    graph1.addEdge(4, 7);
    graph1.addEdge(4, 8);
    graph1.addEdge(5, 8);
    graph1.addEdge(5, 9);
    graph1.addEdge(6, 7);
    graph1.addEdge(6, 9);
    graph1.addEdge(7, 8);

    graph2.addEdge(0, 1);
    graph2.addEdge(0, 2);
    graph2.addEdge(0, 3);
    graph2.addEdge(1, 3);
    graph2.addEdge(0, 3);
    graph2.addEdge(2, 5);
    graph2.addEdge(5, 6);
    graph2.addEdge(3, 6);
    graph2.addEdge(4, 7);
    graph2.addEdge(4, 8);
    graph2.addEdge(5, 8);
    graph2.addEdge(5, 9);
    graph2.addEdge(6, 7);
    graph2.addEdge(6, 9);
    graph2.addEdge(8, 8);

    graph3.addEdge(0, 1);
    graph3.addEdge(1, 2);
    graph3.addEdge(1, 3);
    graph3.addEdge(0, 3);
    graph3.addEdge(0, 4);
    graph3.addEdge(2, 5);
    graph3.addEdge(2, 9);
    graph3.addEdge(3, 6);
    graph3.addEdge(4, 7);
    graph3.addEdge(4, 8);
    graph3.addEdge(5, 8);
    graph3.addEdge(5, 9);
    graph3.addEdge(6, 7);
    graph3.addEdge(6, 9);
    graph3.addEdge(7, 8);

    graph4.addEdge(4, 1);
    graph4.addEdge(7, 9);
    graph4.addEdge(6, 2);
    graph4.addEdge(7, 3);
    graph4.addEdge(5, 0);
    graph4.addEdge(0, 2);
    graph4.addEdge(0, 8);
    graph4.addEdge(1, 6);
    graph4.addEdge(3, 9);
    graph4.addEdge(6, 3);
    graph4.addEdge(2, 8);
    graph4.addEdge(1, 5);
    graph4.addEdge(9, 8);
    graph4.addEdge(4, 5);
    graph4.addEdge(4, 7);

    if (graph1.isEulerian()) {
        cout << "Graph 1 has Eulerian cycle: Yes" << endl;
    }
    else {
        cout << "Graph 1 has Eulerian cycle: No" << endl;
    }

    if (graph1.isHamiltonian()) {
        cout << "Graph 1 has Hamiltonian cycle: Yes" << endl;
    }
    else {
        cout << "Graph 1 has Hamiltonian cycle: No" << endl;
    }

    if (graph2.isEulerian()) {
        cout << "Graph 2 has Eulerian cycle: Yes" << endl;
    }
    else {
        cout << "Graph 2 has Eulerian cycle: No" << endl;
    }

    if (graph2.isHamiltonian()) {
        cout << "Graph 2 has Hamiltonian cycle: Yes" << endl;
    }
    else {
        cout << "Graph 2 has Hamiltonian cycle: No" << endl;
    }

    if (graph3.isEulerian()) {
        cout << "Graph 3 has Eulerian cycle: Yes" << endl;
    }
    else {
        cout << "Graph 3 has Eulerian cycle: No" << endl;
    }

    if (graph3.isHamiltonian()) {
        cout << "Graph 3 has Hamiltonian cycle: Yes" << endl;
    }
    else {
        cout << "Graph 3 has Hamiltonian cycle: No" << endl;
    }

    if (graph4.isEulerian()) {
        cout << "Graph 4 has Eulerian cycle: Yes" << endl;
    }
    else {
        cout << "Graph 4 has Eulerian cycle: No" << endl;
    }

    if (graph4.isHamiltonian()) {
        cout << "Graph 4 has Hamiltonian cycle: Yes" << endl;
    }
    else {
        cout << "Graph 4 has Hamiltonian cycle: No" << endl;
    }


    return 0;
}
