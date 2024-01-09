/********************************************
 * author : Jie Chen (3rd Year CS)
 * school : Rochester Institute of Technology
 * created: 01.06.2024 18:25:22
*********************************************/

using i64 = long long;

constexpr int inf = 1e9 + 5;

class Solution {
public:
    int minimumCoins(vector<int>& a) {
        int n = a.size();

        vector<int> dp(n + 1, inf);
        dp[n] = 0;
        for (int i = n - 1; i >= 0; i--) {
            for (int j = i + 1; j <= min(n, 2 * (i + 1)); j++) {
                dp[i] = min(dp[i], a[i] + dp[j]);
            }
        }

        return dp[0];
    }
};

// ~ JustJie