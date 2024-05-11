/********************************************
 * author : Jie Chen (3rd Year CS)
 * school : Rochester Institute of Technology
 * created: 05.11.2024 11:08:02
*********************************************/

using i64 = long long;

class Solution {
public:
    bool satisfiesConditions(vector<vector<int>>& aa) {
        int n = aa.size(), m = aa[0].size();

        bool ok = true;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (i < n - 1) {
                    ok = ok && (aa[i][j] == aa[i + 1][j]);
                }
                if (j < m - 1) {
                    ok = ok && (aa[i][j] != aa[i][j + 1]);
                }
            }
        }
        return ok;
    }
};

// ~ JustJie