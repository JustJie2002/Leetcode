/********************************************
 * author : Jie Chen (3rd Year CS)
 * school : Rochester Institute of Technology
 * created: 03.02.2024 21:30:37
*********************************************/

using i64 = long long;

class Solution {
public:
    int countSubmatrices(vector<vector<int>>& grid, int k) {
        int n = grid.size(), m = grid[0].size();

        vector pre(n + 1, vector<int>(m + 1));
        int ans = 0;
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                pre[i][j] = grid[i - 1][j - 1] + pre[i - 1][j] + pre[i][j - 1] - pre[i - 1][j - 1];
                if (pre[i][j] <= k) {
                    ans++;
                }
            }
        }

        return ans;
    }
};

// ~ JustJie