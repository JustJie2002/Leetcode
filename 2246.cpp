class Solution {
public:
    int longestPath(vector<int>& parent, string s) {
        int n = parent.size();
        vector<vector<int>> adj(n);
        
        for (int i = 1; i < n; i++) {
            if (s[i] == s[parent[i]]) continue;
            adj[parent[i]].push_back(i);
        }

        vector<int> memo(n);

        int ans = 1;

        function<int(int)> dfs = [&](int idx) -> int {
            if (memo[idx]) return memo[idx];

            vector<int> depth = {1};
            
            for (const auto& i : adj[idx]) {
                depth.push_back(1 + dfs(i));
            }

            sort(depth.rbegin(), depth.rend());

            int m = depth.size();

            if (m == 1) {
                ans = max(ans, 1);
            } else {
                ans = max(ans, depth[0] + depth[1] - 1);
            }
            return memo[idx] = depth[0];
        };

        for (int i = 0; i < n; i++) dfs(i);

        return ans;
    }
};