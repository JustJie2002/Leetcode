/********************************************
 * author : Jie Chen (3rd Year CS)
 * school : Rochester Institute of Technology
 * created: 04.21.2024 19:43:16
*********************************************/

using i64 = long long;
using Info = array<int, 2>;

class Solution {
public:
    long long maxTaxiEarnings(int n, vector<vector<int>>& edges) {
        vector<vector<Info>> adj(n + 1);
        for (const auto& edge : edges) {
            int s = edge[0];
            int e = edge[1];
            int t = edge[2];
            adj[s].push_back({e, t});
        }

        vector<i64> dp(n + 1);
        for (int i = 1; i <= n; i++) {
            dp[i] = max(dp[i], dp[i - 1]);
            for (const auto& [e, t] : adj[i]) {
                dp[e] = max(dp[e], dp[i] + (e - i + t));
            }
        }
        return dp.back();
    }
};

// ~ JustJie