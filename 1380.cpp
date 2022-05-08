constexpr int INF = 1E9;

class Solution {
public:
    vector<int> luckyNumbers (vector<vector<int>>& matrix) {
        vector<int> res;
        int m = matrix.size(), n = matrix[0].size();

        auto check = [&](int row, int col) -> bool {
            int mn = INF, mx = -INF;
            for (int i = 0; i < n; i++)
                mn = min(mn, matrix[row][i]);
            for (int i = 0; i < m; i++)
                mx = max(mx, matrix[i][col]);
            return matrix[row][col] == mn && matrix[row][col] == mx;
        };

        // min in row and max in col
        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
                if (check(i, j)) 
                    res.push_back(matrix[i][j]);
        return res;
    }
};