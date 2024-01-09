/********************************************
 * author : Jie Chen (3rd Year CS)
 * school : Rochester Institute of Technology
 * created: 01.08.2024 20:47:42
*********************************************/

using i64 = long long;

constexpr int N = 12;

class Solution {
public:
    vector<int> maximumBobPoints(int m, vector<int>& a) {
        int ans = -1, ans_mask;
        for (int mask = 0; mask < (1 << N); mask++) {
            int res = 0, used = 0;
            for (int i = 0; i < N; i++) {
                if (mask & (1 << i)) {
                    used += a[i] + 1;
                    res += i;
                }
            }
            if (used <= m && res > ans) {
                ans = res;
                ans_mask = mask;
            }
        }

        int lst;
        vector<int> b(N);
        for (int i = 0; i < N; i++) {
            if (ans_mask & (1 << i)) {
                b[i] = a[i] + 1;
                m -= (a[i] + 1);
                lst = i;
            }
        }
        b[lst] += m;

        return b;
    }
};

// ~ JustJie