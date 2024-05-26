/********************************************
 * author : Jie Chen (3rd Year CS)
 * school : Rochester Institute of Technology
 * created: 05.21.2024 11:36:43
*********************************************/

using i64 = long long;

class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& a) {
        int n = a.size();

        vector<unordered_map<int, int>> dp(n);
        int ans = 0;
        for (int i = 1; i < n; i++) {
            for (int j = 0; j < i; j++) {
                i64 dif = a[i] - a[j];
                const auto& res = dp[j][dif];
                dp[i][dif] += res + 1;
                ans += res;
            }
        }
        return ans;
    }
};

// ~ JustJie