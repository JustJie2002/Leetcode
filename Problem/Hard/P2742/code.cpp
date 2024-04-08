/********************************************
 * author : Jie Chen (3rd Year CS)
 * school : Rochester Institute of Technology
 * created: 03.27.2024 09:02:51
*********************************************/

using i64 = long long;

constexpr int inf = 1e9 + 5;

class Solution {
public:
    int paintWalls(vector<int>& cost, vector<int>& time) {
        int n = cost.size();

        // suppose we have a set of items (cost, value)
        vector<int> dp(n + 1, inf);
        dp[0] = 0;
        for (int i = 0; i < n; i++) {
            auto ndp = dp;
            for (int j = 0; j <= n; j++) {
                if (dp[j] != inf) {
                    int nex = min(n, j + time[i] + 1);
                    ndp[nex] = min(ndp[nex], dp[j] + cost[i]);
                }
            }
            swap(dp, ndp);
        }
        return dp.back();
    }
};

// ~ JustJie