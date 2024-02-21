/********************************************
 * author : Jie Chen (3rd Year CS)
 * school : Rochester Institute of Technology
 * created: 02.10.2024 21:30:28
*********************************************/

using i64 = long long;

class Solution {
public:
    vector<vector<int>> modifiedMatrix(vector<vector<int>>& mat) {
        int n = mat.size(), m = mat[0].size();

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (mat[i][j] == -1) {
                    int mx = 0;
                    for (int k = 0; k < n; k++) {
                        mx = max(mx, mat[k][j]);
                    }
                    mat[i][j] = mx;
                }
            }
        }

        return mat;
    }
};

// ~ JustJie