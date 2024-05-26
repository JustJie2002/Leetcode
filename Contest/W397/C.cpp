/********************************************
 * author : Jie Chen (3rd Year CS)
 * school : Rochester Institute of Technology
 * created: 05.11.2024 23:02:46
*********************************************/

using i64 = long long;

constexpr int inf = 1e9 + 5;

class Solution {
public:
    int maxScore(vector<vector<int>>& aa) {
        int n = aa.size(), m = aa[0].size();

        vector dp(n + 1, vector<int>(m + 1));
        int ans = -inf;
        for (int i = n - 1; i >= 0; i--) {
            for (int j = m - 1; j >= 0; j--) {
                for (int k = i + 1; k < n; k++) {
                    int v = aa[k][j] - aa[i][j] + dp[k][j];
                    ans = max(ans, v);
                    dp[i][j] = max(dp[i][j], v);
                }
                for (int k = j + 1; k < m; k++) {
                    int v = aa[i][k] - aa[i][j] + dp[i][k];
                    ans = max(ans, v);
                    dp[i][j] = max(dp[i][j], v);
                }
            }
        }
        return ans;
    }
};

// ~ JustJie