/********************************************
 * author : Jie Chen (3rd Year CS)
 * school : Rochester Institute of Technology
 * created: 03.28.2024 23:40:44
*********************************************/

using i64 = long long;

constexpr int LIM = 1001, CENTER = LIM - 1;

class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        vector<int> dp(2 * LIM);
        dp[CENTER] = 1;
        for (int x : nums) {
            vector<int> ndp(2 * LIM);
            for (int i = 0; i < 2 * LIM; i++) {
                if (dp[i]) {
                    ndp[i - x] += dp[i];
                    ndp[i + x] += dp[i];
                }
            }
            swap(dp, ndp);
        }
        return dp[CENTER + target];
    }
};

// ~ JustJie