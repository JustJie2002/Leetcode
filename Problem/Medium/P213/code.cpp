/********************************************
 * author : Jie Chen (3rd Year CS)
 * school : Rochester Institute of Technology
 * created: 01.01.2024 20:46:11
*********************************************/

using i64 = long long;

constexpr int inf = 1e9 + 5;

class Solution {
public:
    int rob(vector<int>& a) {
        int n = a.size();

        vector<array<int, 2>> dp(n);
        dp[0][0] = a[0];
        dp[0][1] = -inf;
        int ans = a[0];
        for (int i = 1; i < n; i++) {
            dp[i][0] = dp[i][1] = a[i];
            if (i == n - 1) {
                dp[i][0] = -inf;
            }
            int x = 0, y = 0;
            for (int j = i - 2; j >= 0; j--) {
                if (dp[j][0] != -inf) {
                    x = max(x, dp[j][0]);
                }
                if (dp[j][1] != -inf) {
                    y = max(y, dp[j][1]);
                }
            }
            dp[i][0] += x;
            dp[i][1] += y;
            ans = max({ans, dp[i][0], dp[i][1]});
        }

        return ans;
    }
};

// ~ JustJie