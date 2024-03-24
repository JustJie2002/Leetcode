/********************************************
 * author : Jie Chen (3rd Year CS)
 * school : Rochester Institute of Technology
 * created: 03.20.2024 00:41:34
*********************************************/

using i64 = long long;

class Solution {
public:
    int hIndex(vector<int>& a) {
        int n = a.size();

        if (a[0] >= n) {
            return n;
        }
        if (a[n - 1] < 1) {
            return 0;
        }

        int lo = 0, hi = n - 1, mid;
        while (lo < hi) {
            mid = (lo + hi) / 2;
            if (a[mid] >= n - mid) {
                hi = mid;
            } else {
                lo = mid + 1;
            }
        }

        return n - hi;
    }
};

// ~ JustJie