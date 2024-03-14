/********************************************
 * author : Jie Chen (3rd Year CS)
 * school : Rochester Institute of Technology
 * created: 03.14.2024 00:38:38
*********************************************/

using i64 = long long;

// Insert MInt.cpp

constexpr int P = 1'000'000'007; // 998244353;
using Z = MInt<P>;

class Solution {
public:
    int numRollsToTarget(int n, int k, int t) {
        vector<Z> dp(t + 1);
        dp[0] = 1;
        for (int i = 0; i < n; i++) {
            vector<Z> ndp(t + 1);
            for (int j = 0; j <= t; j++) {
                for (int r = 1; r <= k; r++) {
                    if (j + r > t) {
                        break;
                    }
                    ndp[j + r] += dp[j];
                }
            }
            swap(dp, ndp);
        }

        return dp[t].val();
    }
};

// ~ JustJie