class Solution {
public:
    bool isBipartite(vector<vector<int>>& adj) {
        int n = adj.size();
        vector<bool> vis(n);
        unordered_map<int, unordered_set<int>> mp;
        
        bool bad = false;

        function<void(int, int)> dfs = [&](int u, int order) -> void {
            mp[order].insert(u);
            vis[u] = true;

            for (int v : adj[u]) {
                if (mp[order].count(v)) {
                    bad = true;
                    break;
                }
                if (vis[v]) continue;
                dfs(v, order ^ 1);
            }
        };

        for (int i = 0; i < n; i++) {
            if (!vis[i]) dfs(i, 0);
        }
        
        return !bad;
    }
};