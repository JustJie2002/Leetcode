/********************************************
 * author : Jie Chen (3rd Year CS)
 * school : Rochester Institute of Technology
 * created: 05.11.2024 11:00:32
*********************************************/

using i64 = long long;
using P = array<int, 2>;

constexpr int A = 26, inf = 1e9 + 5;

class Solution {
public:
    int maxPointsInsideSquare(vector<vector<int>>& points, string s) {
        int n = points.size();

        vector<int> rad(n);
        for (int i = 0; i < n; i++) {
            rad[i] = max(abs(points[i][0]), abs(points[i][1]));
        }

        auto issoke = [&](int r) {
            int msk = 0;
            for (int i = 0; i < n; i++) {
                if (rad[i] > r) {
                    continue;
                }
                int o = s[i] - 'a';
                if (msk >> o & 1) {
                    return inf;
                }
                msk |= (1 << o);
            }
            return __builtin_popcount(msk);
        };

        int lo = 0, hi = inf, mid;
        while (lo < hi) {
            mid = (lo + hi + 1) / 2;
            if (issoke(mid) != inf) {
                lo = mid;
            } else {
                hi = mid - 1;
            }
        }

        return issoke(lo);
    }
};

// ~ JustJie