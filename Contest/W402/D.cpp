/********************************************
 * author : Jie Chen (4th Year CS)
 * school : Rochester Institute of Technology
 * created: 06.15.2024 19:27:56
*********************************************/

using i64 = long long;

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
        if (l >= x && r <= y) {
            return info[p];
        }
        int m = (l + r) / 2;
        if (y <= m) {
            return range_query(2 * p, l, m, x, y);
        } else if (x >= m) {
            return range_query(2 * p + 1, m, r, x, y);
        }
        return range_query(2 * p, l, m, x, m) + range_query(2 * p + 1, m, r, m, y);
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

constexpr int inf = 1e9 + 5;
 
struct Info {
    int cnt, l, r, siz;
    bool l_good, r_good;
};

Info operator+(const Info& a, const Info& b) {
    Info c;
    c.cnt = a.cnt + b.cnt;
    c.l = a.l;
    c.r = b.r;
    c.siz = a.siz + b.siz;
    if (a.r_good && a.r > b.l) {
        c.cnt++;
    }
    if (b.l_good && b.l > a.r) {
        c.cnt++;
    }
    if (a.siz == 1) {
        c.l_good = (a.r > b.l);
    } else {
        c.l_good = a.l_good;
    }
    if (b.siz == 1) {
        c.r_good = (b.l > a.r);
    } else {
        c.r_good = b.r_good;
    }
    return c;
}

class Solution {
public:
    vector<int> countOfPeaks(vector<int>& a, vector<vector<int>>& queries) {
        int n = a.size(), Q = queries.size();

        vector<Info> init(n);
        for (int i = 0; i < n; i++) {
            init[i] = {0, a[i], a[i], 1, false, false};
        }

        SegmentTree<Info> seg(init);
        vector<int> ans;
        for (int q = 0; q < Q; q++) {
            if (queries[q][0] == 1) {
                auto res = seg.range_query(queries[q][1], queries[q][2] + 1);
                ans.push_back(res.cnt);
            } else {
                int x = queries[q][2];
                const Info& to = {0, x, x, 1, false, false};
                seg.modify(queries[q][1], to);
            }
        }
        return ans;
    }
};

// ~ JustJie