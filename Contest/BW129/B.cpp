/********************************************
 * author : Jie Chen (3rd Year CS)
 * school : Rochester Institute of Technology
 * created: 04.27.2024 14:37:21
*********************************************/

using i64 = long long;

class Solution {
public:
    long long numberOfRightTriangles(vector<vector<int>>& aa) {
        int n = aa.size(), m = aa[0].size();

        vector<int> row(n), col(m);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                row[i] += aa[i][j];
                col[j] += aa[i][j];
            }
        }

        i64 ans = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (aa[i][j]) {
                    ans += 1LL * (row[i] - 1) * (col[j] - 1);
                }
            }
        }
        return ans;
    }
};

// ~ JustJie