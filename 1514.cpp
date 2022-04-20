class Solution {
public:
    vector<double> dijkstra(vector<vector<pair<int, double>>> adj, int start) {
        int n = adj.size();
        vector<double> dist(n, 0);
        vector<bool> vis(n);
        priority_queue<pair<double, int>> pq;
        pq.emplace(1., start);
        dist[start] = 1.;
        while (!pq.empty()) {
            auto [p, u] = pq.top(); pq.pop();

            if (vis[u]) continue;
            vis[u] = 1;
            dist[u] = p;

            for (auto& [v, pro] : adj[u]) {
                if (vis[v]) continue;
                if (dist[v] < dist[u] * pro) {
                    dist[v] = dist[u] * pro;
                    pq.emplace(dist[v], v);
                }
            }
        }
        return dist;
    }

    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start, int end) {
        int m = succProb.size();
        vector<vector<pair<int, double>>> adj(n);
        for (int i = 0; i < m; i++) {
            int u = edges[i][0], v = edges[i][1];
            double w = succProb[i];
            adj[u].emplace_back(v, w);
            adj[v].emplace_back(u, w);
        }
        auto dist = dijkstra(adj, start);
        return dist[end];
    }
};