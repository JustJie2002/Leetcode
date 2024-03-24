/********************************************
 * author : Jie Chen (3rd Year CS)
 * school : Rochester Institute of Technology
 * created: 03.20.2024 00:27:22
*********************************************/

using i64 = long long;

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& mat, int target) {
        int n = mat.size(), m = mat[0].size();

        int i = 0, j = m - 1;
        while (i < n && j >= 0) {
            int x = mat[i][j];
            if (x == target) {
                return true;
            } else if (x > target) {
                j--;
            } else {
                i++;
            }
        }

        return false;
    }
};

// ~ JustJie