/********************************************
 * author : Jie Chen (4th Year CS)
 * school : Rochester Institute of Technology
 * created: 05.27.2024 18:57:28
*********************************************/

using i64 = long long;
using Info = array<int, 2>;

constexpr int inf = 1e9 + 5;

class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {

        vector<vector<Info>> adj(n);
        for (const auto& e : edges) {
            int u = e[0];
            int v = e[1];
            int w = e[2];
            adj[u].push_back({v, w});
            adj[v].push_back({u, w});
        }
        
        auto dij = [&](int src) {
            vector dis(n, inf);
            priority_queue<Info, vector<Info>, greater<Info>> pq;
            pq.push({0, src});
            dis[src] = 0;
            while (!pq.empty()) {
                auto [d, cur] = pq.top();
                pq.pop();

                if (d != dis[cur]) {
                    continue;
                }

                for (const auto& [nei, w] : adj[cur]) {
                    if (dis[nei] > d + w) {
                        dis[nei] = d + w;
                        pq.push({d + w, nei});
                    }
                }
            }

            int ans = -1;
            for (int i = 0; i < n; i++) {
                if (dis[i] <= distanceThreshold) {
                    ans++;
                }
            }

            return ans;
        };

        int ans = -1;
        int val = inf;
        for (int i = n - 1; i >= 0; i--) {
            auto x = dij(i);
            if (x < val) {
                val = x;
                ans = i;
            }
        }
        return ans;
    }
};

// ~ JustJie