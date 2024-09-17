/********************************************
 * author : Jie Chen (4th Year CS)
 * school : Rochester Institute of Technology
 * created: 07.06.2024 11:16:14
*********************************************/

using i64 = long long;

// Credit: tourist
template<typename T, class F = function<T(const T&, const T&)>>
struct SparseTable {
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

class Solution {
public:
    long long countSubarrays(vector<int>& a, int k) {
        int n = a.size();

        SparseTable<int> st(a, 
            [&](int x, int y) {
                return x & y;
            });

        i64 ans = 0;
        for (int i = 0; i < n; i++) {
            int lo = i, hi = n - 1, mid;
            while (lo < hi) {
                mid = (lo + hi + 1) / 2;
                if (st.query(i, mid) >= k) {
                    lo = mid;
                } else {
                    hi = mid - 1;
                }
            }
            if (st.query(i, lo) != k) {
                continue;
            }
            int res = lo;
            lo = i, hi = n - 1, mid;
            while (lo < hi) {
                mid = (lo + hi) / 2;
                if (st.query(i, mid) <= k) {
                    hi = mid;
                } else {
                    lo = mid + 1;
                }
            }
            ans += (res - hi + 1);
        }
        return ans;
    }
};

// ~ JustJie