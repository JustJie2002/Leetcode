/********************************************
 * author : Jie Chen (3rd Year CS)
 * school : Rochester Institute of Technology
 * created: 04.25.2024 22:44:06
*********************************************/

using i64 = long long;

constexpr int inf = 1e9 + 5;

class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& grid) {
        int n = grid.size();

        auto dp = grid[0];
        for (int i = 1; i < n; i++) {
            vector ndp(n, inf);
            for (int j = 0; j < n; j++) {
                for (int k = 0; k < n; k++) {
                    if (j == k) {
                        continue;
                    }
                    ndp[j] = min(ndp[j], grid[i][j] + dp[k]);
                }
            }
            dp.swap(ndp);
        }

        return *min_element(dp.begin(), dp.end());
    }
};

// ~ JustJie