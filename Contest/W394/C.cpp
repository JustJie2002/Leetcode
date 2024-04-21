/********************************************
 * author : Jie Chen (3rd Year CS)
 * school : Rochester Institute of Technology
 * created: 04.20.2024 22:38:28
*********************************************/

using i64 = long long;

class Solution {
public:
    int minimumOperations(vector<vector<int>>& mat) {
        int n = mat.size(), m = mat[0].size();

        int ans = 0;
        vector<array<int, 10>> freq(m);
        vector<array<int, 10>> dp(m);
        for (int i = 0; i < m; i++) {
            freq[i] = {};
            dp[i].fill(n * m);
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                freq[j][mat[i][j]]++;
            }
        }

        for (int i = 0; i < m; i++) {
            array<int, 10> c {};
            for (int x = 0; x < 10; x++) {
                // everything to x
                c[x] = n - freq[i][x];
            }
            if (i == 0) {
                dp[i] = c;
            } else {
                for (int x = 0; x < 10; x++) {
                    for (int y = 0; y < 10; y++) {
                        if (x != y) {
                            dp[i][x] = min(dp[i][x], c[x] + dp[i - 1][y]);
                        }
                    }
                }
            }
        }

        return *min_element(dp.back().begin(), dp.back().end());
    }
};

// ~ JustJie