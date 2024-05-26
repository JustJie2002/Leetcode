/********************************************
 * author : Jie Chen (3rd Year CS)
 * school : Rochester Institute of Technology
 * created: 05.22.2024 19:44:26
*********************************************/

using i64 = long long;

class Solution {
public:
    long long maximumBooks(vector<int>& a) {
        int n = a.size();

        auto sum = [&](int v) -> i64 {
            return max(1LL * v * (v + 1) / 2, 0LL);
        };

        vector<int> stk;
        vector<i64> dp(n);
        i64 ans = 0;
        for (int i = 0; i < n; i++) {
            while (!stk.empty() && a[stk.back()] >= a[i] - (i - stk.back())) {
                stk.pop_back();
            }

            dp[i] = (stk.empty() ? 0 : dp[stk.back()]);
            dp[i] += sum(a[i]) - sum(a[i] - (i - (stk.empty() ? -1 : stk.back())));
            ans = max(ans, dp[i]);
            stk.push_back(i);
        }

        return ans;
    }
};

// ~ JustJie