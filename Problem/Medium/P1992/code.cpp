/********************************************
 * author : Jie Chen (3rd Year CS)
 * school : Rochester Institute of Technology
 * created: 04.19.2024 21:32:25
*********************************************/

using i64 = long long;
using Coordinate = array<int, 2>;

class Solution {
public:
    vector<vector<int>> findFarmland(vector<vector<int>>& mat) {
        int n = mat.size(), m = mat[0].size();

        vector<vector<int>> ans;
        vector match(n, vector<Coordinate>(m));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (mat[i][j]) {
                    if ((i == 0 || !mat[i - 1][j]) && (j == 0 || !mat[i][j - 1])) {
                        match[i][j] = {i, j};
                    } else if (i > 0 && mat[i - 1][j]) {
                        match[i][j] = match[i - 1][j];
                    } else if (j > 0 && mat[i][j]) {
                        match[i][j] = match[i][j - 1];
                    } else {
                        assert(false);
                    }
                    if ((i == n - 1 || !mat[i + 1][j]) && (j == m - 1 || !mat[i][j + 1])) {
                        const auto& [si, sj] = match[i][j];
                        ans.push_back({si, sj, i, j});
                    }
                }
            }
        }

        return ans;
    }
};

// ~ JustJie