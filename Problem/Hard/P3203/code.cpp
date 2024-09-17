/********************************************
 * author : Jie Chen (4th Year CS)
 * school : Rochester Institute of Technology
 * created: 06.30.2024 17:29:26
*********************************************/

using i64 = long long;

class Solution {
public:
    int minimumDiameterAfterMerge(vector<vector<int>>& e1, vector<vector<int>>& e2) {
        const auto construct = [&](const auto &edges) {
            int n = edges.size() + 1;
            vector<vector<int>> adj(n);
            for (const auto &e : edges) {
                int u = e[0];
                int v = e[1];
                adj[u].push_back(v);
                adj[v].push_back(u);
            }
            return adj;
        };

        const auto work = [&](const auto &edges) -> int {
            const auto& adj = construct(edges);
            int n = adj.size();

            vector<int> dis(n);

            const auto dfs = [&](auto &&self, int x, int p) -> void {
                for (int y : adj[x]) {
                    if (y == p) {
                        continue;
                    }
                    dis[y] = dis[x] + 1;
                    self(self, y, x);
                }
            };
            
            dfs(dfs, 0, 0);
            int u = max_element(dis.begin(), dis.end()) - dis.begin();
            dis[u] = 0;
            dfs(dfs, u, u);
            return *max_element(dis.begin(), dis.end());
        };

        int a = work(e1);
        int b = work(e2);

        return max({a, b, (a + 1) / 2 + (b + 1) / 2 + 1});
    }
};

// ~ JustJie