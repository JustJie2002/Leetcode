/********************************************
 * author : Jie Chen (3rd Year CS)
 * school : Rochester Institute of Technology
 * created: 04.27.2024 01:45:12
*********************************************/

using i64 = long long;

constexpr int A = 26, inf = 1e9 + 5;

class Solution {
public:
    int findRotateSteps(string s, string t) {
        int n = s.length();

        vector dp(n, inf);
        dp[0] = 0;
        for (auto c : t) {
            vector ndp(n, inf);
            for (int i = 0; i < n; i++) {
                if (s[i] == c) {
                    for (int j = 0; j < n; j++) {
                        int a = min(i, j);
                        int b = max(i, j);
                        int d = min(b - a, a + n - b);
                        ndp[i] = min(ndp[i], dp[j] + d + 1);
                    }
                }
            }
            dp.swap(ndp);
        }

        return *min_element(dp.begin(), dp.end());
    }
};

// ~ JustJie