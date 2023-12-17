/********************************************
 * author : Jie Chen (3rd Year CS)
 * school : Rochester Institute of Technology
 * created: 12.16.2023 21:54:14
*********************************************/

using i64 = long long;

class Solution {
public:
    int maxFrequencyScore(vector<int>& a, i64 k) {
        int n = a.size();

        sort(a.begin(), a.end());

        vector<i64> pre(n + 1);
        for (int i = 0; i < n; i++) {
            pre[i + 1] = pre[i] + a[i];
        }

        int ans = 0;
        for (int L = 0, R = 0; L < n; L++) {
            while (R < n) {
                int med = (L + R) / 2;
                int Lcnt = med - L;
                i64 Lside = 1LL * a[med] * Lcnt - (pre[med] - pre[L]);
                int Rcnt = R - med;
                i64 Rside = (pre[R + 1] - pre[med + 1]) - 1LL * a[med] * Rcnt;

                if (Lside + Rside <= k) {
                    R++;
                } else {
                    med = (L + R + 1) / 2;
                    Lcnt = med - L;
                    Lside = 1LL * a[med] * Lcnt - (pre[med] - pre[L]);
                    Rcnt = R - med;
                    Rside = (pre[R + 1] - pre[med + 1]) - 1LL * a[med] * Rcnt;
                    if (Lside + Rside <= k) {
                        R++;
                    } else {
                        break;
                    }
                }
            }

            ans = max(ans, R - L);
        }

        return ans;
    }
};

// ~ JustJie