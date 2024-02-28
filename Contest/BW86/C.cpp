/********************************************
 * author : Jie Chen (3rd Year CS)
 * school : Rochester Institute of Technology
 * created: 02.27.2024 21:49:33
*********************************************/

using i64 = long long;

class Solution {
public:
    int maximumRows(vector<vector<int>>& matrix, int b) {
        int n = matrix.size(), m = matrix[0].size();

        vector<int> mask(n);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (matrix[i][j]) {
                    mask[i] |= (1 << j);
                }
            }
        }

        int ans = 0;
        for (int submask = 0; submask < (1 << m); submask++) {
            if (__builtin_popcount(submask) == b) {
                int res = 0;
                for (int i = 0; i < n; i++) {
                    if ((mask[i] | submask) == submask) {
                        res++;
                    }
                }
                ans = max(ans, res);
            }
        }

        return ans;
    }
};

// ~ JustJie