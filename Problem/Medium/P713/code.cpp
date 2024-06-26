/********************************************
 * author : Jie Chen (3rd Year CS)
 * school : Rochester Institute of Technology
 * created: 03.26.2024 21:46:17
*********************************************/

using i64 = long long;

class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& a, int k) {
        int n = a.size();

        int ans = 0;
        int p = 1;
        for (int l = 0, r = 0; r < n; r++) {
            p *= a[r];
            while (l <= r && p >= k) {
                p /= a[l++];
            }
            ans += r - l + 1;
        }

        return ans;
    }
};

// ~ JustJie