/********************************************
 * author : Jie Chen (3rd Year CS)
 * school : Rochester Institute of Technology
 * created: 02.10.2024 21:07:18
*********************************************/

using i64 = long long;

constexpr int INF = int(1e9) + 5;

class Solution {
public:
    int cherryPickup(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();

        auto dp = vector(n, vector(m, vector<int>(m, -INF)));
        dp[0][0][m - 1] = grid[0][0] + grid[0][m - 1];
        for (int i = 1; i < n; i++) {
            for (int j = 0; j < m; j++) {
                for (int k = 0; k < m; k++) {
                    for (int dj = -1; dj < 2; dj++) {
                        int nj = j + dj;
                        if (nj < 0 || nj >= m) {
                            continue;
                        }
                        for (int dk = -1; dk < 2; dk++) {
                            int nk = k + dk;
                            if (nk < 0 || nk >= m) {
                                continue;
                            }
                            if (nj == nk) {
                                dp[i][nj][nk] = max(dp[i][nj][nk], dp[i - 1][j][k] + grid[i][nk]);
                            } else {
                                dp[i][nj][nk] = max(dp[i][nj][nk], dp[i - 1][j][k] + grid[i][nj] + grid[i][nk]);
                            }
                        }
                    }
                }
            }
        }

        int ans = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < m; j++) {
                ans = max(ans, dp[n - 1][i][j]);
            }
        }

        return ans;
    }
};

// ~ JustJie