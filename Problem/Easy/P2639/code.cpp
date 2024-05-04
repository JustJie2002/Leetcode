/********************************************
 * author : Jie Chen (3rd Year CS)
 * school : Rochester Institute of Technology
 * created: 05.02.2024 21:45:37
*********************************************/

using i64 = long long;

class Solution {
public:
    int get(int x) {
        if (x == 0) {
            return 1;
        }
        int res = 0;
        if (x < 0) {
            res++;
            x = -x;
        }
        for (; x; x /= 10) {
            res++;
        }
        return res;
    }

    vector<int> findColumnWidth(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();

        vector<int> ans(m);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                ans[j] = max(ans[j], get(grid[i][j]));
            }
        }

        return ans;
    }
};

// ~ JustJie