/********************************************
 * author : Jie Chen (3rd Year CS)
 * school : Rochester Institute of Technology
 * created: 04.12.2024 21:11:27
*********************************************/

using i64 = long long;

class Solution {
public:
    int maximalRectangle(vector<vector<char>>& mat) {
        int n = mat.size(), m = mat[0].size();

        vector expand(n, vector<int>(m));
        int ans = 0;
        for (int s = 0; s < n; s++) {
            for (int c = 0; c < m; c++) {
                if (mat[s][c] != '1') {
                    continue;
                }
                if (c == 0) {
                    expand[s][c] = 1;
                } else {
                    expand[s][c] = expand[s][c - 1] + 1;
                }
                int mi = expand[s][c];
                for (int e = s; e >= 0 && mi; e--) {
                    mi = min(mi, expand[e][c]);
                    ans = max(ans, (s - e + 1) * mi);
                }
            }
        }

        return ans;
    }
};

// ~ JustJie