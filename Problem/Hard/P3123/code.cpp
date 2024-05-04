/********************************************
 * author : Jie Chen (3rd Year CS)
 * school : Rochester Institute of Technology
 * created: 05.02.2024 02:00:53
*********************************************/

using i64 = long long;
using Edge = array<int, 2>;
using Info = pair<i64, int>;

constexpr i64 inf = 1e11 + 10;

class Solution {
public:
    vector<bool> findAnswer(int n, vector<vector<int>>& edges) {
        vector<vector<Edge>> adj(n);
        for (const auto& e : edges) {
            int u = e[0], v = e[1], w = e[2];
            adj[u].push_back({v, w});
            adj[v].push_back({u, w});
        }

        auto dij = [&](int src) -> vector<i64> {
            vector<i64> dis(n, inf);
            priority_queue<Info, vector<Info>, greater<Info>> pq;
            
            auto add = [&](int u, i64 d) {
                if (dis[u] > d) {
                    dis[u] = d;
                    pq.emplace(d, u);
                }
            };

            add(src, 0);
            while (!pq.empty()) {
                auto [d, cur] = pq.top();
                pq.pop();

                if (dis[cur] != d) {
                    continue;
                }

                for (const auto& [nei, w] : adj[cur]) {
                    add(nei, d + w);
                }
            }

            return dis;
        };

        auto a = dij(0);
        auto b = dij(n - 1);

        int m = edges.size();
        vector<bool> ans(m);

        if (a.back() == inf) {
            return ans;
        }

        for (int e = 0; e < m; e++) {
            int u = edges[e][0], v = edges[e][1], w = edges[e][2];
            ans[e] = (a[u] + b[v] + w == a[n - 1]) || (a[v] + b[u] + w == a[n - 1]);
        }

        return ans;
    }
};

// ~ JustJie