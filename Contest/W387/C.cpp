/********************************************
 * author : Jie Chen (3rd Year CS)
 * school : Rochester Institute of Technology
 * created: 03.02.2024 21:32:09
*********************************************/

using i64 = long long;

class Solution {
public:
    int minimumOperationsToWriteY(vector<vector<int>>& grid) {
        int n = grid.size();

        unordered_map<int, int> freq;
        int m = n / 2;
        vector mark(n, vector<int>(n));
        for (int i = 0; i < m; i++) {
            freq[grid[i][i]]++;
            freq[grid[i][n - i - 1]]++;
            mark[i][i] = mark[i][n - i - 1] = 1;
        }

        for (int i = m; i < n; i++) {
            freq[grid[i][m]]++;
            mark[i][m] = 1;
        }

        unordered_map<int, int> other;
        int o = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (!mark[i][j]) {
                    other[grid[i][j]]++;
                    o++;
                }
            }
        }
        int y = n * n - o;

        int ans = n * n;
        for (const auto& [c1, f1] : freq) {
            for (const auto& [c2, f2] : other) {
                if (c1 != c2) {
                    ans = min(ans, (o - f2) + (y - f1));
                } else {
                    ans = min(ans, o + (y - f1));
                    ans = min(ans, (o - f2) + y);
                }
            }
        }

        return ans;
    }
};

// ~ JustJie