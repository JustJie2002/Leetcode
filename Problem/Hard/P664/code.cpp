/********************************************
 * author : Jie Chen (4th Year CS)
 * school : Rochester Institute of Technology
 * created: 06.14.2024 20:18:13
*********************************************/

using i64 = long long;

constexpr int inf = 1e9 + 5;

class Solution {
public:
    int strangePrinter(string s) {
        int n = s.size();

        vector dp(n, vector<int>(n, inf));
        for (int i = 0; i < n; i++) {
            dp[i][i] = 1;
            for (int j = 0; j < i; j++) {
                dp[i][j] = 0;
            }
        }

        for (int i = n - 2; i >= 0; i--) {
            for (int j = i + 1; j < n; j++) {
                for (int k = i; k < j; k++) {
                    dp[i][j] = min(dp[i][j], dp[i][k] + dp[k + 1][j - 1] + (s[k] != s[j]));
                }
            }
        }

        return dp[0][n - 1];
    }
};

// ~ JustJie