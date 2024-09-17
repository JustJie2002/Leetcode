/********************************************
 * author : Jie Chen (4th Year CS)
 * school : Rochester Institute of Technology
 * created: 06.29.2024 22:27:59
*********************************************/

using i64 = long long;

class Solution {
public:
    int minimumDiameterAfterMerge(vector<vector<int>>& e1, vector<vector<int>>& e2) {
        int n = e1.size() + 1;
        int m = e2.size() + 1;

        vector<vector<int>> adj1(n), adj2(m);
        for (const auto &e : e1) {
            int u = e[0];
            int v = e[1];
            adj1[u].push_back(v);
            adj1[v].push_back(u);
        }
        for (const auto &e : e2) {
            int u = e[0];
            int v = e[1];
            adj2[u].push_back(v);
            adj2[v].push_back(u);
        }

        int ans = 0;
        auto work = [&](const auto &adj) -> int {
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

            int s = max_element(dis.begin(), dis.end()) - dis.begin();
            dis[s] = 0;
            dfs(dfs, s, s);
            int d = *max_element(dis.begin(), dis.end());
            ans = max(ans, d);
            return (*max_element(dis.begin(), dis.end()) + 1) / 2;
        };

        ans = max(ans, work(adj1) + work(adj2) + 1);
        return ans;
    }
};

// ~ JustJie