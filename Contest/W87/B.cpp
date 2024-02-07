/********************************************
 * author : Jie Chen (3rd Year CS)
 * school : Rochester Institute of Technology
 * created: 02.01.2024 21:07:49
*********************************************/

using i64 = long long;

class Solution {
public:
    int longestMountain(vector<int>& a) {
        int n = a.size();

        vector<int> L(n), R(n);
        for (int i = 1; i < n; i++) {
            if (a[i] > a[i - 1]) {
                L[i] = L[i - 1] + 1;
            } else {
                L[i] = 0;
            }
        }
        for (int i = n - 2; i >= 0; i--) {
            if (a[i] > a[i + 1]) {
                R[i] = R[i + 1] + 1;
            } else {
                R[i] = 0;
            }
        }

        int ans = 0;
        for (int i = 1; i < n - 1; i++) {
            if (a[i] > a[i - 1] && a[i] > a[i + 1]) {
                ans = max(ans, L[i] + R[i] + 1);
            }
        }

        return ans;
    }
};

// ~ JustJie