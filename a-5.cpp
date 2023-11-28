//giả sử ta có một đồ thị g không có điểm articulation.
//chọn bất kỳ hai đỉnh s và t trên đồ thị.
//tìm một đường đi p từ s đến t trên đồ thị.do g không có điểm articulation, nên không có đỉnh nào trên p khi bị loại bỏ sẽ làm đồ thị mất tính liên thông.
//bây giờ, ta sẽ xây dựng một đường đi q khác từ s đến t mà không giao với p.điều này có thể thực hiện được bằng cách đi theo các cạnh khác nhau từ s đến t mà không đi qua các đỉnh của p(trừ s và t).nếu không thể tìm thấy đường đi như vậy, ta có thể đi theo một cạnh đã được sử dụng trong p nhưng theo hướng ngược lại.
//lúc này, ta đã tìm thấy hai đường đi không giao nhau từ s đến t, cho thấy đồ thị G là biconnected.
#include <iostream>
#include <vector>
#include <list>

using namespace std;

class Graph {
public:
    int V;
    list<int>* adj; 

    Graph(int V) : V(V), adj(new list<int>[V]) {}

    void addEdge(int u, int v) {
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    bool isConnected() {
        vector<bool> visited(V, false);

        int i;
        for (i = 0; i < V; ++i) {
            if (adj[i].size() > 0)
                break;
        }

        if (i == V) return true;

        DFSUtil(i, visited);

        for (i = 0; i < V; ++i) {
            if (visited[i] == false && adj[i].size() > 0)
                return false;
        }

        return true;
    }

    bool isArticulationPoint(int v) {
        int originalSize = adj[v].size();

        adj[v].clear();
        bool connected = isConnected();

        adj[v].resize(originalSize);

        return !connected;
    }

    bool isBiconnected() {
        if (V <= 2) return true; 

        for (int v = 0; v < V; ++v) {
            if (isArticulationPoint(v))
                return false;
        }

        return true;
    }

private:
    void DFSUtil(int v, vector<bool>& visited) {
        visited[v] = true;

        for (int i : adj[v]) {
            if (!visited[i])
                DFSUtil(i, visited);
        }
    }
};

int main() {
    Graph g(5);
    g.addEdge(0, 1);
    g.addEdge(1, 2);
    g.addEdge(2, 3);
    g.addEdge(3, 0);
    g.addEdge(1, 4);
    g.addEdge(4, 2);

    bool isBiconnected = g.isBiconnected();
    cout << "The graph is " << (isBiconnected ? "biconnected." : "not biconnected.") << endl;

    return 0;
}
