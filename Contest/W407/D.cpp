/********************************************
 * author : Jie Chen (4th Year CS)
 * school : Rochester Institute of Technology
 * created: 07.21.2024 17:57:08
*********************************************/

using i64 = long long;

class Solution {
public:
    long long minimumOperations(vector<int>& a, vector<int>& b) {
        int n = a.size();

        vector<int> d(n);
        for (int i = 0; i < n; i++) {
            d[i] = b[i] - a[i];
        }
        for (int i = n - 1; i > 0; i--) {
            d[i] -= d[i - 1];
        }

        i64 ans = 0, res = 0;
        for (int i = 0; i < n; i++) {
            if (d[i] >= 0) {
                ans += d[i];
            } else {
                res -= d[i];
            }
        }

        return max(ans, res);
    }
};

// ~ JustJie