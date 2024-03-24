/********************************************
 * author : Jie Chen (3rd Year CS)
 * school : Rochester Institute of Technology
 * created: 03.20.2024 22:11:46
*********************************************/

using i64 = long long;

class Solution {
public:
    int longestSquareStreak(vector<int>& a) {
        int n = a.size();

        sort(a.begin(), a.end());

        auto is_sqrt = [&](int x) {
            int sq = int(sqrt(x));
            return sq * sq == x;
        };

        vector dp(n, 1);
        map<int, int> pre;
        for (int i = 0; i < n; i++) {
            int x = a[i];
            if (is_sqrt(x)) {
                int sq = int(sqrt(x));
                if (pre.contains(sq)) {
                    dp[i] = dp[pre[sq]] + 1;
                }
            }
            pre[x] = i;
        }

        int ans = *max_element(dp.begin(), dp.end());
        if (ans == 1) {
            ans = -1;
        }
        return ans;
    }
};

// ~ JustJie