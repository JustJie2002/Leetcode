/********************************************
 * author : Jie Chen (4th Year CS)
 * school : Rochester Institute of Technology
 * created: 07.07.2024 01:08:19
*********************************************/

using i64 = long long;

class Solution {
public:
    int numberOfSubmatrices(vector<vector<char>>& mat) {
        int n = mat.size(), m = mat[0].size();

        vector x(n + 1, vector<int>(m + 1));
        vector y(n + 1, vector<int>(m + 1));
        int ans = 0;
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                x[i][j] = x[i - 1][j] + x[i][j - 1] - x[i - 1][j - 1] + int(mat[i - 1][j - 1] == 'X');
                y[i][j] = y[i - 1][j] + y[i][j - 1] - y[i - 1][j - 1] + int(mat[i - 1][j - 1] == 'Y');
                if (x[i][j] == y[i][j] && x[i][j] > 0) {
                    ans++;
                }
            }
        }
        return ans;
    }
};

// ~ JustJie