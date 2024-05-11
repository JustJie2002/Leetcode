/********************************************
 * author : Jie Chen (3rd Year CS)
 * school : Rochester Institute of Technology
 * created: 05.08.2024 00:27:18
*********************************************/

using i64 = long long;
using Edge = pair<int, int>;

constexpr int inf = 1e9 + 5;

class Graph {
public:
    vector<vector<Edge>> adj;
    int n;
    Graph(int n, vector<vector<int>>& edges) {
        this->n = n;
        adj.resize(n);
        for (const auto& e : edges) {
            addEdge(e);
        }
    }
    
    void addEdge(const vector<int>& e) {
        int u = e[0], v = e[1], w = e[2];
        if (u == v) {
            return;
        }
        adj[u].emplace_back(v, w);
    }
    
    int shortestPath(int source, int destination) {
        vector<int> dis(n, inf);
        dis[source] = 0;
        priority_queue<Edge, vector<Edge>, greater<Edge>> pq;
        pq.push({0, source});
        while (!pq.empty()) {
            auto [d, u] = pq.top();
            pq.pop();
            if (dis[u] != d) {
                continue;
            }
            if (u == destination) {
                return d;
            }
            for (const auto& [v, w] : adj[u]) {
                if (dis[v] > d + w) {
                    dis[v] = d + w;
                    pq.push({dis[v], v});
                }
            }
        }
        return -1;
    }
};

/**
 * Your Graph object will be instantiated and called as such:
 * Graph* obj = new Graph(n, edges);
 * obj->addEdge(edge);
 * int param_2 = obj->shortestPath(node1,node2);
 */

// ~ JustJie