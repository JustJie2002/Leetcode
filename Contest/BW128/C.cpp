/********************************************
 * author : Jie Chen (3rd Year CS)
 * school : Rochester Institute of Technology
 * created: 04.13.2024 11:50:50
*********************************************/

using i64 = long long;
using Edge = array<int, 2>;

class Solution {
public:
    vector<int> minimumTime(int n, vector<vector<int>>& edges, vector<int>& disappear) {
        vector<vector<Edge>> adj(n);
        for (const auto& e : edges) {
            int u = e[0], v = e[1], w = e[2];
            adj[u].push_back({v, w});
            adj[v].push_back({u, w});
        }

        priority_queue<Edge, vector<Edge>, greater<Edge>> h;
        vector<int> dis(n, -1);

        auto enqueue = [&](int u, int d) {
            if (dis[u] == -1 || dis[u] > d) {
                dis[u] = d;
                h.push({d, u});
            }
        };

        enqueue(0, 0);
        while (!h.empty()) {
            auto [d, cur] = h.top();
            h.pop();

            if (dis[cur] != d) {
                continue;
            }

            for (const auto& [nei, w] : adj[cur]) {
                if (disappear[nei] <= d + w) {
                    continue;
                }
                enqueue(nei, d + w);
            }
        }

        return dis;
    }
};

// ~ JustJie