/********************************************
 * author : Jie Chen (3rd Year CS)
 * school : Rochester Institute of Technology
 * created: 01.06.2024 22:01:53
*********************************************/

// using i64 = long long;

// #define foo(mask)   __builtin_popcount(mask)

constexpr int N = int(1e4) + 1, A = 26;
int dp[N][2];

constexpr int ord(char c) { return c - 'a'; }
class Solution {
public:
    int maxPartitionsAfterOperations(string s, int k) {
        int n = s.size();
        if (k == 26) {
            return 1;
        }
        memset(dp, -1, sizeof(dp));

        auto gogo = [&](const auto& self, int idx, bool remain, bool ok, bool ) -> int {
            if (idx == n) {
                return 1;
            }
            auto& res = dp[idx][used][mask];
            if (res != -1) {
                return res;
            }
            res = 0;
            int new_mask = mask | (1 << ord(s[idx]));
            if (foo(new_mask) == k + 1) {
                res = 1 + self(self, idx + 1, used, 1 << ord(s[idx]));
            }
            if (!used) {
                for (int a = 0; a < A; a++) if (a != ord(s[idx])) {
                    new_mask = mask | (1 << a);
                    res = max(res, self(self, idx + 1, true, new_mask));
                }
            }
            return res;
        };
        return gogo(gogo, 0, false, 0);
    }
};

// ~ JustJie
