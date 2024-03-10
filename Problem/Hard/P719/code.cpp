/********************************************
 * author : Jie Chen (3rd Year CS)
 * school : Rochester Institute of Technology
 * created: 03.06.2024 22:57:04
*********************************************/

using i64 = long long;

class Solution {
public:
    int smallestDistancePair(vector<int>& a, int k) {
        int n = a.size();

        sort(a.begin(), a.end());

        auto solve = [&](int cutoff) -> bool {
            int L = 0;
            int tot = 0;
            for (int R = 1; R < n; R++) {
                while (a[R] - a[L] > cutoff) {
                    L++;
                }
                tot += (R - L);
            }
            return tot >= k;
        };

        int lo = 0, hi = a.back();
        while (lo < hi) {
            int mid = (lo + hi) / 2;
            if (solve(mid)) {
                hi = mid;
            } else {
                lo = mid + 1;
            }
        }

        return hi;
    }
};

// ~ JustJie