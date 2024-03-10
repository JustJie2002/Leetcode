/********************************************
 * author : Jie Chen (3rd Year CS)
 * school : Rochester Institute of Technology
 * created: 11.25.2023 17:56:15
 ~ Jie ♥ Jenney
*********************************************/

using i64 = long long;

class Solution {
public:
    int findMaximumLength(vector<int>& a) {
        int n = a.size();
        
        vector<i64> pre(n + 1);
        for (int i = 0; i < n; i++) {
            pre[i + 1] = pre[i] + a[i];
        }

        vector<int> lst(n + 2), dp(n + 1);
        int ptr = 0;
        for (int i = 1; i <= n; i++) {
            ptr = max(ptr, lst[i]);
            dp[i] = dp[ptr] + 1;
            int k = int(lower_bound(pre.begin(), pre.end(), 2 * pre[i] - pre[ptr]) - pre.begin());
            lst[k] = i;
        }
        return dp[n];
    }
};

// ~ JustJie