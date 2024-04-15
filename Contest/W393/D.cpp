/********************************************
 * author : Jie Chen (3rd Year CS)
 * school : Rochester Institute of Technology
 * created: 04.13.2024 21:53:17
*********************************************/

using i64 = long long;

constexpr int inf = 1e9 + 5;

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

template <class Info>
struct SegmentTree {
    int n;
    vector<Info> info;
    SegmentTree() : n(0) {}
    SegmentTree(int n_, Info v_ = Info()) {
        init(n_, v_);
    }
    template<class T>
    SegmentTree(vector<T> init_) {
        init(init_);
    }
    void init(int n_, Info v_ = Info()) {
        init(vector(n_, v_));
    }
    template<class T>
    void init(vector<T> init_) {
        n = init_.size();
        info.assign(4 << __lg(n), Info());
        function<void(int, int, int)> build = [&](int p, int l, int r) {
            if (r - l == 1) {
                info[p] = init_[l];
                return;
            }
            int m = (l + r) / 2;
            build(2 * p, l, m);
            build(2 * p + 1, m, r);
            pull(p);
        };
        build(1, 0, n);
    }
    void pull(int p) {
        info[p] = info[2 * p] + info[2 * p + 1];
    }
    void modify(int p, int l, int r, int x, const Info &v) {
        if (r - l == 1) {
            info[p] = v;
            return;
        }
        int m = (l + r) / 2;
        if (x < m) {
            modify(2 * p, l, m, x, v);
        } else {
            modify(2 * p + 1, m, r, x, v);
        }
        pull(p);
    }
    void modify(int p, const Info &v) {
        modify(1, 0, n, p, v);
    }
    Info range_query(int p, int l, int r, int x, int y) {
        if (l >= y || r <= x) {
            return Info();
        }
        if (l >= x && r <= y) {
            return info[p];
        }
        int m = (l + r) / 2;
        return range_query(2 * p, l, m, x, y) + range_query(2 * p + 1, m, r, x, y);
    }
    Info range_query(int l, int r) {
        return range_query(1, 0, n, l, r);
    }
    template<class F>
    int find_first(int p, int l, int r, int x, int y, F pred) {
        if (l >= y || r <= x || !pred(info[p])) {
            return -1;
        }
        if (r - l == 1) {
            return l;
        }
        int m = (l + r) / 2;
        int res = find_first(2 * p, l, m, x, y, pred);
        if (res == -1) {
            res = find_first(2 * p + 1, m, r, x, y, pred);
        }
        return res;
    }
    template<class F>
    int find_first(int l, int r, F pred) {
        return find_first(1, 0, n, l, r, pred);
    }
    template<class F>
    int find_last(int p, int l, int r, int x, int y, F pred) {
        if (l >= y || r <= x || !pred(info[p])) {
            return -1;
        }
        if (r - l == 1) {
            return l;
        }
        int m = (l + r) / 2;
        int res = find_last(2 * p + 1, m, r, x, y, pred);
        if (res == -1) {
            res = find_last(2 * p, l, m, x, y, pred);
        }
        return res;
    }
    template<class F>
    int find_last(int l, int r, F pred) {
        return find_last(1, 0, n, l, r, pred);
    }
};

struct Info {
    int x = inf;
};
 
Info operator+(const Info& a, const Info& b) {
    Info c;
    c.x = min(a.x, b.x);
    return c;
}

class Solution {
public:
    int minimumValueSum(vector<int>& a, vector<int>& av) {
        int n = a.size(), m = av.size();

        SparseTable<int> st(a, [&](int x, int y) { return x & y; });

        auto find_first = [&](int i, int w) -> int {
            int lo = 0, hi = i, mid, ans = -1;
            while (lo <= hi) {
                mid = (lo + hi) / 2;
                int v = st.query(mid, i);
                if (v == w) {
                    ans = mid;
                    hi = mid - 1;
                } else if (v < w) {
                    lo = mid + 1;
                } else {
                    hi = mid - 1;
                }
            }
            return ans;
        };

        auto find_last = [&](int i, int w) -> int {
            int lo = 0, hi = i, mid, ans = -1;
            while (lo <= hi) {
                mid = (lo + hi) / 2;
                int v = st.query(mid, i);
                if (v == w) {
                    ans = mid;
                    lo = mid + 1;
                } else if (v < w) {
                    lo = mid + 1;
                } else {
                    hi = mid - 1;
                }
            }
            return ans;
        };

        vector<Info> init(n);
        for (int i = 0; i < n - m + 1; i++) {
            if (st.query(0, i) == av[0]) {
                init[i] = {a[i]};
            }
        }

        SegmentTree<Info> seg(init);
        for (int k = 1; k < m; k++) {
            vector<Info> new_init(n);
            for (int i = k; i < n; i++) {
                int l = find_first(i, av[k]);
                int r = find_last(i, av[k]);
                if (l != -1) {
                    int v = seg.range_query(max(0, l - 1), r).x + a[i];
                    new_init[i] = {v};
                }
            }
            seg = SegmentTree<Info>(new_init);
        }

        int ans = seg.range_query(n - 1, n).x;
        if (ans == inf) {
            ans = -1;
        }
        return ans;
    }
};

// ~ JustJie