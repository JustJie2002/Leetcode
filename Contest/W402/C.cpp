/********************************************
 * author : Jie Chen (4th Year CS)
 * school : Rochester Institute of Technology
 * created: 06.15.2024 22:49:04
*********************************************/

using i64 = long long;

class Solution {
public:
    long long maximumTotalDamage(vector<int>& p) {
        sort(p.begin(), p.end());

        map<int, int> res;
        for (int x : p) {
            res[x]++;
        }
        p.erase(unique(p.begin(), p.end()), p.end());

        int n = p.size();
        vector<i64> dp(n);
        i64 ans = 0;
        for (int i = 0; auto x : p) {
            int j = i - 1;
            while (j >= 0 && p[i] - p[j] <= 2) {
                j--;
            }
            i64 tot = (j >= 0 ? dp[j] : 0);
            dp[i] = max(dp[i], tot + 1LL * res[x] * x);
            if (i) {
                dp[i] = max(dp[i], dp[i - 1]);
            }
            ans = max(ans, dp[i]);
            i++;
        }
        return ans;
    }
};

// ~ JustJie