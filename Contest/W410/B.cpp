/********************************************
 * author : Jie Chen (4th Year CS)
 * school : Rochester Institute of Technology
 * created: 08.13.2024 03:53:44
*********************************************/

using i64 = long long;

class Solution {
public:
    int countGoodNodes(vector<vector<int>>& edges) {
        int n = edges.size() + 1;

        vector<vector<int>> adj(n);
        for (const auto& e : edges) {
            int u = e[0], v = e[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        vector<int> sz(n);
        int ans = 0;
        const auto dfs = [&](auto&& self, int u, int p) -> void {
            sz[u] = 1;
            int mx = 0, mi = n;
            for (int v : adj[u]) {
                if (v == p) {
                    continue;
                }
                self(self, v, u);
                sz[u] += sz[v];
                mx = max(mx, sz[v]);
                mi = min(mi, sz[v]);
            }

            if (mx == 0 || mx == mi) {
                ans++;
            }
        };
        dfs(dfs, 0, 0);

        return ans;
    }
};

// ~ JustJie