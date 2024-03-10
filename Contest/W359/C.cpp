/********************************************
 * author : Jie Chen (3rd Year CS)
 * school : Rochester Institute of Technology
 * created: 03.08.2024 01:00:11
*********************************************/

using i64 = long long;
using Info = pair<int, int>;

class Solution {
public:
    int maximizeTheProfit(int n, vector<vector<int>>& offers) {
        set<int> s;

        vector<vector<Info>> off(n);
        for (const auto& offer : offers) {
            off[offer[0]].emplace_back(offer[1], offer[2]);
        }
        
        vector<int> dp(n + 1);
        int ans = 0;
        for (int i = n - 1; i >= 0; i--) {
            dp[i] = dp[i + 1];
            for (const auto& [end, earn] : off[i]) {
                dp[i] = max(dp[i], earn + dp[end + 1]);
            }
            ans = max(ans, dp[i]);
        }
        return ans;
    }
};

// ~ JustJie