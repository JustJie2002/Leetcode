class Solution {
private:
    unordered_map<string, vector<pair<string, double>>> adj;
    unordered_set<string> seen;

    double dfs1(string u, string want, double wei = 1.0) {
        if (u == want)
            return wei;
        seen.insert(u);
        for (const auto& [v, w] : adj[u]) {
            if (seen.count(v)) continue;
            double ans = dfs1(v, want, wei * w);
            if (ans != -1.0)
                return ans;
        }
        return -1.0;
    }

public:
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        int n = values.size();
        for (int i = 0; i < n; i++) {
            string a = equations[i][0];
            string b = equations[i][1];
            double w = values[i];
            adj[a].push_back({b, w});
            adj[b].push_back({a, 1 / w});
        }
        int m = queries.size();
        vector<double> rets(m);
        for (int i = 0; i < m; i++) {
            string a = queries[i][0];
            string b = queries[i][1];
            if (adj.count(a) && adj.count(b))
                rets[i] = dfs1(a, b);
            else
                rets[i] = -1.0;
            seen.clear();
        }
        return rets;
    }
};