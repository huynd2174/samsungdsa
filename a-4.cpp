#include <iostream>
#include <vector>
#include <queue>

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

    bool isBipartite() {
        vector<int> colors(V, -1); 

        for (int i = 0; i < V; ++i) {
            if (colors[i] == -1) {
                if (!bipartiteUtil(i, colors)) {
                    return false;
                }
            }
        }

        return true;
    }

private:
    bool bipartiteUtil(int src, vector<int>& colors) {
        colors[src] = 0; 

        queue<int> q;
        q.push(src);

        while (!q.empty()) {
            int u = q.front();
            q.pop();

            for (int v : adjList[u]) {
                if (colors[v] == -1) {
                    colors[v] = 1 - colors[u]; 
                    q.push(v);
                }
                else if (colors[v] == colors[u]) {
                    return false; 
                }
            }
        }

        return true;
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

    bool isBipartite = graph.isBipartite();
    if (isBipartite) {
        cout << "The graph is Bipartite." << endl;
    }
    else {
        cout << "The graph is Not Bipartite." << endl;
    }

    return 0;
}

//1. Nếu đồ thị là đồ thị hai mầu, thì nó không chứa chu trình độ dài lẻ.
//Giả sử đồ thị G là đồ thị hai mầu với hai mầu là A và B.Chọn một đỉnh bất kỳ u và tô mầu u là A.Tất cả các đỉnh kề với u sẽ được tô mầu B.Tiếp tục quy trình này, mỗi lần đi qua một cạnh, chuyển đổi mầu của đỉnh đó.Như vậy, mỗi chu trình đều có số bước chẵn, và không có chu trình độ dài lẻ.
//
//2. Nếu đồ thị không chứa chu trình độ dài lẻ, thì nó là đồ thị hai mầu.Giả sử đồ thị G không chứa chu trình độ dài lẻ.Chúng ta sẽ chứng minh rằng mỗi đỉnh của G có thể được tô mầu sao cho không có cạnh nào nối giữa hai đỉnh cùng mầu.Bắt đầu tô mầu từ một đỉnh bất kỳ, chẳng hạn là u.Tô mầu u là A.Các đỉnh kề với u sẽ được tô mầu B, các đỉnh kề với các đỉnh mầu B sẽ được tô mầu A, và tiếp tục quy trình này.
//Nếu có một cạnh nối giữa hai đỉnh cùng mầu, thì đó là một cạnh thuộc một chu trình độ dài lẻ, điều này mâu thuẫn với giả định ban đầu.