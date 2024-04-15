/********************************************
 * author : Jie Chen (3rd Year CS)
 * school : Rochester Institute of Technology
 * created: 04.12.2024 00:55:37
*********************************************/

using i64 = long long;

class Solution {
public:
    int trap(vector<int>& a) {
        int n = a.size();

        int l = 0, r = n - 1;
        int pre_greater = 0, suf_greater = 0;
        int ans = 0;
        while (l <= r) {
            if (a[l] <= a[r]) {
                pre_greater = max(pre_greater, a[l]);
                ans += pre_greater - a[l];
                l++;
            } else {
                suf_greater = max(suf_greater, a[r]);
                ans += suf_greater - a[r];
                r--;
            }
        }
        return ans;
    }
};

// ~ JustJie