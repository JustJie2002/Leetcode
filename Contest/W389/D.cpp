/********************************************
 * author : Jie Chen (3rd Year CS)
 * school : Rochester Institute of Technology
 * created: 03.16.2024 22:39:01
*********************************************/

using i64 = long long;

constexpr i64 inf = 1e15 + 10;

class Solution {
public:
    long long minimumMoves(vector<int>& a, int k, int mc) {
        int n = a.size();

        vector<int> pos;
        for (int i = 0; i < n; i++) {
            if (a[i] == 1) {
                pos.push_back(i);
            }
        }

        int m = pos.size();
        vector<i64> pre(m + 1);
        for (int i = 0; i < m; i++) {
            pre[i + 1] = pre[i] + pos[i];
        }

        if (k == 1) {
            return m ? 0 : 2;
        }

        i64 ans;
        {
            i64 res = 0;
            int score = a[0];
            if (a[1]) {
                res++;
                score++;
            }
            if (score + mc >= k) {
                int need = k - score;
                res += 2LL * need;
            } else {
                res += 2LL * mc;
                score += mc;
                int need = k - score;
                res += pre[need + score - mc] - pre[score - mc];
            }
            ans = res;
        }
        {
            i64 res = 0;
            int score = a[n - 1];
            if (a[n - 2]) {
                res++;
                score++;
            }
            if (score + mc >= k) {
                int need = k - score;
                res += 2LL * need;
            } else {
                res += 2LL * mc;
                score += mc;
                int need = k - score;

                res += 1LL * need * (n - 1) - (pre[m - (score - mc)] - pre[m - (need + score - mc)]);
            }
            ans = min(ans, res);
        }
        for (int pivot = 1, j = 0; pivot < n - 1; pivot++) {
            while (j < m && pos[j] < pivot) {
                j++;
            }
            // pos[j] >= pivot
            i64 res = 0;
            int score = a[pivot];
            int L = (score ? j + 1 : j), R = j - 1;
            if (a[pivot - 1]) {
                score++;
                res++;
                R--;
            }
            if (score == k) {
                ans = min(ans, res);
                continue;
            }
            if (a[pivot + 1]) {
                score++;
                res++;
                L++;
            }
            if (score == k) {
                ans = min(ans, res);
                continue;
            }
            if (score + mc >= k) {
                int need = k - score;
                res += 2LL * need;
            } else {
                res += 2LL * mc;
                score += mc;
                int need = k - score;

                auto get = [&](int v) -> i64 {
                    i64 tot = 0;
                    tot += 1LL * (R + 1 - v) * pivot - (pre[R + 1] - pre[v]);
                    int req = need - (R + 1 - v);
                    if (req == 0) {
                        return tot;
                    }
                    if (L + req > m) {
                        return inf;
                    }
                    tot += (pre[L + req] - pre[L]) - 1LL * req * pivot;
                    return tot;
                };

                int lo = max(0, R - need + 1), hi = R + 1, mid;
                while (lo < hi) {
                    mid = (lo + hi) / 2;
                    if (get(mid) <= get(mid + 1)) {
                        hi = mid;
                    } else {
                        lo = mid + 1;
                    }
                }
                res += get(lo);
            }
            ans = min(ans, res);
        }

        return ans;
    }
};

// ~ JustJie
