/********************************************
 * author : Jie Chen (3rd Year CS)
 * school : Rochester Institute of Technology
 * created: 03.16.2024 19:33:51
*********************************************/

using i64 = long long;

// Insert MInt.cpp

constexpr int P = 1'000'000'007; // 998244353;
using Z = MInt<P>;

class Solution {
public:
    int sumOfPower(vector<int>& a, int k) {
        int n = a.size();

        vector dp(n + 1, vector<Z>(k + 1));
        dp[0][0] = 1;
        for (int i = 1; i <= n; i++) {
            vector ndp(n + 1, vector<Z>(k + 1));
            for (int sz = 0; sz < n; sz++) {
                for (int j = 0; j <= k; j++) {
                    ndp[sz][j] += dp[sz][j];
                    if (j + a[i - 1] <= k) {
                        ndp[sz + 1][j + a[i - 1]] += dp[sz][j];
                    }
                }
            }
            swap(dp, ndp);
        }

        Z ans = 0;
        for (int i = 1; i <= n; i++) {
            ans += power(Z(2), n - i) * dp[i][k];
        }
        return ans.val();
    }
};

// ~ JustJie