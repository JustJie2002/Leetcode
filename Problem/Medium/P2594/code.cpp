/********************************************
 * author : Jie Chen (4th Year CS)
 * school : Rochester Institute of Technology
 * created: 06.10.2024 22:35:17
*********************************************/

using i64 = long long;

constexpr i64 inf = 1e15;

class Solution {
public:
    i64 repairCars(vector<int>& ranks, int cars) {
        auto work = [&](i64 x) {
            i64 res = 0;
            for (int r : ranks) {
                res += sqrtl(x / r);
            }
            return res >= cars;
        };

        i64 lo = 1, hi = inf;
        while (lo < hi) {
            i64 x = (lo + hi) / 2;
            if (work(x)) {
                hi = x;
            } else {
                lo = x + 1;
            }
        }

        return hi;
    }
};

// ~ JustJie