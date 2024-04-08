/********************************************
 * author : Jie Chen (3rd Year CS)
 * school : Rochester Institute of Technology
 * created: 03.30.2024 12:31:49
*********************************************/

using i64 = long long;

constexpr int B = 31, inf = 1e9 + 5;

class Solution {
public:
    int minimumSubarrayLength(vector<int>& a, int k) {
        int n = a.size();
        if (k == 0) {
            return 1;
        }
        
        array<int, B> cnt {};

        auto get = [&]() -> int {
            int res = 0;
            for (int b = 0; b < B; b++) {
                if (cnt[b]) {
                    res |= (1 << b);
                }
            }
            return res;
        };
        auto add = [&](int x) -> void {
            for (int b = 0; b < B; b++) {
                if (x >> b & 1) {
                    cnt[b]++;
                }
            }
        };
        auto sub = [&](int x) -> void {
            for (int b = 0; b < B; b++) {
                if (x >> b & 1) {
                    assert(cnt[b]);
                    cnt[b]--;
                }
            }
        };

        int ans = inf;
        for (int l = 0, r = 0; l < n; l++) {
            while (r < n && get() < k) {
                add(a[r++]);
            }
            if (get() >= k) {
                ans = min(ans, r - l);
            }
            sub(a[l]);
        }
        
        if (ans == inf) {
            ans = -1;
        }
        return ans;
    }
};

// ~ JustJie