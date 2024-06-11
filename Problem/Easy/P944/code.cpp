/********************************************
 * author : Jie Chen (4th Year CS)
 * school : Rochester Institute of Technology
 * created: 05.27.2024 18:55:38
*********************************************/

using i64 = long long;

class Solution {
public:
    int minDeletionSize(vector<string>& s) {
        int n = s.size();
        int m = s[0].length();

        int ans = 0;
        for (int j = 0; j < m; j++) {
            bool good = true;
            for (int i = 1; i < n; i++) {
                good &= (s[i][j] >= s[i - 1][j]);
            }
            if (!good) {
                ans++;
            }
        }
        return ans;
    }
};

// ~ JustJie