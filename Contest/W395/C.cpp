/********************************************
 * author : Jie Chen (3rd Year CS)
 * school : Rochester Institute of Technology
 * created: 04.27.2024 22:40:28
*********************************************/

using i64 = long long;

class Solution {
public:
    long long minEnd(int n, int x) {
        int lz = 31 - __builtin_clz(x);
        vector<int> e;
        for (int b = 0; b < lz; b++) {
            if (x >> b & 1) {
            } else {
                e.push_back(b);
            }
        }

        int m = e.size();
        i64 res = 1 << m;

        n--;
        int need = n / res;
        i64 ans = x;
        ans += (need << (1LL * lz + 1));
        n -= 1LL * need * res;
        for (int b = m - 1; b >= 0; b--) {
            if (n >> b & 1) {
                ans += (1LL << e[b]);
            }
        }
        return ans;
    }
};

// ~ JustJie