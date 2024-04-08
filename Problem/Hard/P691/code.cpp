/********************************************
 * author : Jie Chen (3rd Year CS)
 * school : Rochester Institute of Technology
 * created: 03.26.2024 21:54:27
*********************************************/

using i64 = long long;

constexpr int A = 26, inf = 1e9 + 5;

class Solution {
public:
    int minStickers(vector<string>& a, string t) {
        int n = a.size();
        int m = t.length();
        int M = 1 << m;

        auto ord = [&](char c) -> int {
            return c - 'a';
        };

        vector<array<int, A>> freq(n);
        for (int i = 0; i < n; i++) {
            freq[i] = {};
            for (char c : a[i]) {
                freq[i][ord(c)]++;
            }
        }

        auto bit = [&](int msk, int nth) -> int {
            return msk >> nth & 1;
        };

        vector<int> dp(M, inf);
        dp[0] = 0;
        array<int, A> used {};
        for (int msk = 0; msk < M - 1; msk++) if (dp[msk] != inf) {
            for (int i = 0; i < n; i++) {
                int super_msk = msk;
                used.fill(0);
                for (int j = 0; j < m; j++) if (!bit(super_msk, j)) {
                    int o = ord(t[j]);
                    if (freq[i][o] - used[o] > 0) {
                        super_msk |= (1 << j);
                        used[o]++;
                    }
                }
                dp[super_msk] = min(dp[super_msk], dp[msk] + 1);
            }
        }

        int ans = dp.back();
        if (ans == inf) {
            ans = -1;
        }
        return ans;
    }
};

// ~ JustJie