/********************************************
 * author : Jie Chen (3rd Year CS)
 * school : Rochester Institute of Technology
 * created: 04.23.2024 04:09:47
*********************************************/

using i64 = long long;

class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);
        vector<int> deg(n);
        for (const auto& edge : edges) {
            int u = edge[0];
            int v = edge[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
            deg[u]++, deg[v]++;
        }

        if (n == 1) {
            return {0};
        }

        queue<int> q;
        for (int i = 0; i < n; i++) if (deg[i] == 1) {
            q.push(i);
        }

        vector<int> roots;
        while (!q.empty()) {
            int q_siz = q.size();
            while (q_siz--) {
                auto cur = q.front();
                q.pop();
                roots.push_back(cur);

                for (int nei : adj[cur]) if (--deg[nei] == 1) {
                    q.push(nei);
                }
            }

            if (!q.empty()) {
                roots.clear();
            }
        }

        return roots;
    }
};

// ~ JustJie