/********************************************
 * author : Jie Chen (3rd Year CS)
 * school : Rochester Institute of Technology
 * created: 04.02.2024 00:15:45
*********************************************/

using i64 = long long;
using Info = array<int, 2>;

constexpr int inf = 1e9 + 5;

class Solution {
public:
    int minSwap(vector<int>& a, vector<int>& b) {
        int n = a.size();

        vector<Info> dp(n);
        dp[0][0] = 0; // no swap
        dp[0][1] = 1; // swap
        for (int i = 1; i < n; i++) {
            dp[i][0] = dp[i][1] = inf;
            { // no swap
                if (a[i] > a[i - 1] && b[i] > b[i - 1]) {
                    dp[i][0] = min(dp[i][0], dp[i - 1][0]);
                }
                if (a[i] > b[i - 1] && b[i] > a[i - 1]) {
                    dp[i][0] = min(dp[i][0], dp[i - 1][1]);
                }
            }
            { // swap
                if (a[i] > a[i - 1] && b[i] > b[i - 1]) {
                    dp[i][1] = min(dp[i][1], dp[i - 1][1] + 1);
                }
                if (a[i] > b[i - 1] && b[i] > a[i - 1]) {
                    dp[i][1] = min(dp[i][1], dp[i - 1][0] + 1);
                }
            }
        }

        return min(dp[n - 1][0], dp[n - 1][1]);
    }
};

// ~ JustJie