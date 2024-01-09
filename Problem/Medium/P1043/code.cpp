/********************************************
 * author : Jie Chen (3rd Year CS)
 * school : Rochester Institute of Technology
 * created: 12.28.2023 17:29:30
*********************************************/

using i64 = long long;

class Solution {
public:
    int maxSumAfterPartitioning(vector<int>& a, int k) {
        int n = a.size();

        vector<int> dp(n + 1);
        for (int i = 0; i < n; i++) {
            int segment_max = 0;
            for (int j = 0; j < k && i + j < n; j++) {
                segment_max = max(segment_max, a[i + j]);
                dp[i + j + 1] = max(dp[i + j + 1], dp[i] + segment_max * (j + 1));
            }
        }

        return dp[n];
    }
};

// ~ JustJie