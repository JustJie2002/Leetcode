/********************************************
 * author : Jie Chen (3rd Year CS)
 * school : Rochester Institute of Technology
 * created: 03.20.2024 00:12:41
*********************************************/

using i64 = long long;

constexpr int inf = 1e9 + 5;

class Solution {
public:
    int getMoneyAmount(int n) {
        vector dp(n + 1, vector<int>(n + 1, inf));

        // dp[L][R] - the min amount of money we need
        for (int i = 1; i <= n; i++) {
            dp[i][i] = 0;
        }
        for (int sz = 2; sz <= n; sz++) {
            for (int l = 1; l <= n - sz + 1; l++) {
                int r = l + sz - 1;
                dp[l][r] = min(l + dp[l + 1][r], r + dp[l][r - 1]);
                for (int k = l + 1; k < r; k++) {
                    dp[l][r] = min(dp[l][r], k + max(dp[l][k - 1], dp[k + 1][r]));
                }
            }
        }

        return dp[1][n];
    }
};

// ~ JustJie