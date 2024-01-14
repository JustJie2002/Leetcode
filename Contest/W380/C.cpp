/********************************************
 * author : Jie Chen (3rd Year CS)
 * school : Rochester Institute of Technology
 * created: 01.13.2024 21:31:31
*********************************************/

using i64 = long long;

constexpr i64 inf = 1e18 + 10;

class Solution {
public:

    long long findMaximumNumber(long long k, int x) {

        auto solve = [&](i64 cutoff) -> i64 {
            for (int b = x; ; b += x) {
                i64 nex = 1 << (b + x - 1);
                
                if (nex > cutoff) {
                    break;
                }
            }
        };

        i64 lo = 1, hi = inf, mid;
        while (lo < hi) {
            mid = (lo + hi + 1) / 2;
            if (solve(mid) <= k) {
                lo = mid;
            } else {
                hi = mid - 1;
            }
        }
        return lo;
    }
};

// ~ JustJie