using i64 = long long;

class Solution {
public:
    i64 gcd(i64 x, i64 y) {
        if (y == 0)
            return x;
        return gcd(y, x % y);
    }

    int nthUglyNumber(int n, i64 a, i64 b, i64 c) {
        i64 lo = 1, hi = 1E10, mi;

        vector<i64> fs = {a, b, c};

        vector<i64> ls;
        int m = fs.size();
        for (int mask = 0; mask < (1 << m); mask++) {
            if (__builtin_popcount(mask) >= 2) {
                i64 l = 1;
                for (int i = 0; i < m; i++) {
                    if (mask >> i & 1) {
                        l = lcm(l, fs[i]);
                    }
                }
                ls.push_back(l);
            }
        }

        sort(ls.begin(), ls.end());
        int z = ls.size();
        vector<int> seen(z);
        vector<i64> sub;

        for (int i = 0; i < z; i++) {
            if (seen[i] < 2) {
                sub.push_back(ls[i]);
                for (int j = i + 1; j < z; j++) {
                    if (ls[j] % ls[i] == 0) {
                        seen[j] += 1;
                    }
                }
            }
        }

        auto solve = [&] (i64 x) -> i64 {
            i64 res = 0;
            for (i64& f : fs) res += x / f;
            for (i64& l : sub) res -= x / l;
            return res;
        };

        while (lo <= hi) {
            mi = (lo + hi) >> 1LL;
            i64 count = solve(mi);
            if (count == n && (mi % a == 0 || mi % b == 0 || mi % c == 0)) {
                return mi;
            } else if (count >= n) {
                hi = mi - 1;
            } else {
                lo = mi + 1;
            }
        }
        assert(false);
    }
};