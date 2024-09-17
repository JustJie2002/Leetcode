/********************************************
 * author : Jie Chen (4th Year CS)
 * school : Rochester Institute of Technology
 * created: 06.30.2024 17:34:33
*********************************************/

using i64 = long long;

class Solution {
public:
    int maximumLength(vector<int>& a, int k) {
        int n = a.size();

        for (int i = 0; i < n; i++) {
            a[i] %= k;
        }

        vector dp(n, vector<int>(k + 1, 1));
        int ans = 1;
        for (int i = 1; i < n; i++) {
            for (int j = 0; j < i; j++) {
                int x = (a[i] + a[j]) % k;
                dp[i][x] = max(dp[i][x], dp[j][x] + 1);
                ans = max(ans, dp[i][x]);
            }
        }
        return ans;
    }
};

// ~ JustJie