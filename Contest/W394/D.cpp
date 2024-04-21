/********************************************
 * author : Jie Chen (3rd Year CS)
 * school : Rochester Institute of Technology
 * created: 04.20.2024 22:29:26
*********************************************/

using i64 = long long;
using Edge = pair<i64, i64>;

constexpr i64 inf = 1e10 + 5;

class Solution {
public:
    vector<bool> findAnswer(int n, vector<vector<int>>& edges) {
        int m = edges.size();

        vector<vector<Edge>> adj(n);
        for (int e = 0; e < m; e++) {
            int u = edges[e][0];
            int v = edges[e][1];
            int w = edges[e][2];
            adj[u].push_back({v, w});
            adj[v].push_back({u, w});
        }

        auto dij = [&](int src) -> vector<i64> {
            vector<i64> dis(n, inf);
            priority_queue<Edge, vector<Edge>, greater<Edge>> h;

            auto add = [&](int u, i64 d) {
                if (d < dis[u]) {
                    dis[u] = d;
                    h.emplace(d, u);
                }
            };
            add(src, 0);

            while (!h.empty()) {
                auto [d, cur] = h.top();
                h.pop();

                if (dis[cur] != d) {
                    continue;
                }

                for (const auto& [nei, w] : adj[cur]) {
                    add(nei, d + w);
                }
            }

            return dis;
        };

        auto dis = dij(0);
        auto rdis = dij(n - 1);

        vector<bool> ans(m);
        for (int e = 0; e < m; e++) {
            int u = edges[e][0];
            int v = edges[e][1];
            int w = edges[e][2];
            ans[e] = (dis[u] + w + rdis[v] == dis[n - 1] || dis[v] + w + rdis[u] == dis[n - 1]);
        }

        return ans;
    }
};

// ~ JustJie