/********************************************
 * author : Jie Chen (3rd Year CS)
 * school : Rochester Institute of Technology
 * created: 01.06.2024 22:01:53
*********************************************/

using i64 = long long;

#define popcount(mask)   __builtin_popcount(mask)

// credit: tourist
template <typename T, class F = function<T(const T&, const T&)>> struct SparseTable {
    int n;
    vector<vector<T>> st;
    F merge;

    SparseTable(const vector<T>& a, const F& f): merge(f) {
        n = a.size();
        int max_log = 32 - __builtin_clz(n);
        st.resize(max_log);
        st[0] = a;
        for (int lg = 1; lg < max_log; lg++) {
            st[lg].resize(n - (1 << lg) + 1);
            for (int i = 0; i <= n - (1 << lg); i++) {
                st[lg][i] = merge(st[lg - 1][i], st[lg - 1][i + (1 << (lg - 1))]);
            }
        }
    }

    T query(int from, int to) const {
        assert(0 <= from && from <= to && to <= n - 1);
        int lg = 32 - __builtin_clz(to - from + 1) - 1;
        return merge(st[lg][from], st[lg][to - (1 << lg) + 1]);
    }
};

constexpr int A = 26;
constexpr int ord(char c) { return c - 'a'; }

pair<int, int> groupby(string s) {
    s += '$';
    char p = s[0];
    int cnt = 0, ans = 1, comp = 0;
    for (char c : s) {
        if (c == p) {
            cnt++;
        } else {
            cnt = 1;
            comp++;
        }
        p = c;
        ans = max(ans, cnt);
    }
    return make_pair(comp, ans);
}

class Solution {
public:
    int maxPartitionsAfterOperations(string s, int k) {
        int n = s.size();

        vector<int> init(n);
        for (int i = 0; i < n; i++) {
            init[i] = 1 << ord(s[i]);
        }
        SparseTable<int> rmq(init, [&](int a, int b) { return a | b; });

        vector<int> dp(n + 1);
        for (int i = n - 1; i >= 0; i--) {
            int lo = i, hi = n - 1, mid;
            while (lo < hi) {
                mid = (lo + hi + 1) / 2;
                int segment_mask = rmq.query(i, mid);
                if (popcount(segment_mask) <= k) {
                    lo = mid;
                } else {
                    hi = mid - 1;
                }
            }
            dp[i] = 1 + dp[lo + 1];
        }

        int cur_mask = 0;
        int ans = 1, res = 1;
        for (int i = 0; i < n; i++) {
            int o = ord(s[i]);

            for (int a = 0; a < A; a++) {
                if ((cur_mask & (1 << a)) == 0) {
                    int nex_mask = cur_mask | (1 << a);
                    if (popcount(nex_mask) == k + 1) {
                        int lo = min(n - 1, i), hi = n - 1, mid;
                        while (lo < hi) {
                            mid = (lo + hi + 1) / 2;
                            int new_mask = (1 << a) | rmq.query(i + 1, mid);
                            if (popcount(new_mask) <= k) {
                                lo = mid;
                            } else {
                                hi = mid - 1;
                            }
                        }
                        ans = max(ans, res + 1 + dp[lo + 1]);
                    } else {
                        int lo = min(n - 1, i), hi = n - 1, mid;
                        while (lo < hi) {
                            mid = (lo + hi + 1) / 2;
                            int new_mask = nex_mask | rmq.query(i + 1, mid);
                            if (popcount(new_mask) <= k) {
                                lo = mid;
                            } else {
                                hi = mid - 1;
                            }
                        }
                        ans = max(ans, res + dp[lo + 1]);
                    }
                }
            }

            cur_mask |= (1 << o);
            if (popcount(cur_mask) == k + 1) {
                res++;
                cur_mask = (1 << o);
            }
            ans = max(ans, res);
        }

        return ans;
    }
};

// ~ JustJie