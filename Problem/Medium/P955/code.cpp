/********************************************
 * author : Jie Chen (3rd Year CS)
 * school : Rochester Institute of Technology
 * created: 05.07.2024 17:48:51
*********************************************/

using i64 = long long;

class Solution {
public:
    int minDeletionSize(vector<string>& s) {
        int n = s.size(), m = s[0].length();

        int ans = 0;
        vector<bool> sorted(n - 1); // sorted[i] = cur[i] < cur[i + 1]
        for (int j = 0; j < m; j++) {
            bool good = true;
            for (int i = 0; i < n - 1; i++) {
                good &= (sorted[i] || (s[i][j] <= s[i + 1][j]));
            }
            if (good) {
                for (int i = 0; i < n - 1; i++) {
                    sorted[i] = sorted[i] || (s[i][j] < s[i + 1][j]);
                }
            } else {
                ans++;
            }
        }

        return ans;
    }
};

// ~ JustJie