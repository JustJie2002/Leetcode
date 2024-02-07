    /********************************************
 * author : Jie Chen (3rd Year CS)
 * school : Rochester Institute of Technology
 * created: 01.10.2024 23:17:27
*********************************************/

using i64 = long long;

class Solution {
public:
    int minimizedMaximum(int n, vector<int>& a) {

        auto good = [&](int cutoff) -> bool {
            int res = 0;
            for (int x : a) {
                res += (x + cutoff - 1) / cutoff;
            }
            return res <= n;
        };

        int lo = 1, hi = *max_element(a.begin(), a.end()), mid;
        while (lo < hi) {
            mid = (lo + hi) / 2;
            if (good(mid)) {
                hi = mid;
            } else {
                lo = mid + 1;
            }
        }

        return hi;
    }
};

// ~ JustJie