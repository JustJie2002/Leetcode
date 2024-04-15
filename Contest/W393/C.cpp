/********************************************
 * author : Jie Chen (3rd Year CS)
 * school : Rochester Institute of Technology
 * created: 04.13.2024 22:53:30
*********************************************/

using i64 = long long;

constexpr i64 inf = 1e15 + 10;

class Solution {
public:
    long long findKthSmallest(vector<int>& a, int k) {
        int n = a.size();

        vector<i64> add, sub;
        for (int msk = 1; msk < (1 << n); msk++) {
            i64 l = 1;
            int p = 0;
            for (int i = 0; i < n; i++) {
                if (msk >> i & 1) {
                    l = lcm(l, a[i]);
                    p ^= 1;
                }
            }
            if (p % 2 == 0) {
                sub.push_back(l);
            } else {
                add.push_back(l);
            }
        }

        auto issoke = [&](i64 x) -> i64 {
            i64 res = 0;
            for (i64 v : add) {
                res += x / v;
            }
            for (i64 v : sub) {
                res -= x / v;
            }
            return res >= k;
        };

        i64 lo = 1, hi = inf, mid;
        while (lo < hi) {
            mid = (lo + hi) / 2;
            if (issoke(mid)) {
                hi = mid;
            } else {
                lo = mid + 1;
            }
        }
        return hi;
    }
};

// ~ JustJie