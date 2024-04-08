/********************************************
 * author : Jie Chen (3rd Year CS)
 * school : Rochester Institute of Technology
 * created: 04.02.2024 22:33:56
*********************************************/

using i64 = long long;

template<class Info> struct SegmentTree {
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
    i64 x;
    int max_size;
};

Info operator+(const Info& a, const Info& b) {
    Info c;
    c.x = a.x + b.x;
    c.max_size = max(a.max_size, b.max_size);
    return c;
}

class BookMyShow {
public:
    SegmentTree<Info> tr;
    int n, m, L;
    vector<int> rem;
    BookMyShow(int _n, int _m): n(_n), m(_m), rem(_n) {
        tr.init(n, {m, m});
        L = 0;
    }

    void _norm() {
        while (L < n && rem[L] == m) L++;
    }
    
    vector<int> gather(int k, int max_row) {
        if (tr.range_query(L, max_row + 1).max_size < k) {
            return {};
        }

        vector<int> ans(2);
        int idx = tr.find_first(L, max_row + 1,
            [&](const Info& info) {
                return info.max_size >= k;
            });

        ans[0] = idx;
        ans[1] = rem[idx];
        rem[idx] += k;
        int seat_rem = m - rem[idx];
        tr.modify(idx, {seat_rem, seat_rem});
        _norm();
        return ans;
    }
    
    bool scatter(int k, int max_row) {
        if (tr.range_query(L, max_row + 1).x < k) {
            return false;
        }

        for (int i = L; i <= max_row && k > 0; i++) {
            int tot = m - rem[i];
            if (tot != 0) {
                int use = min(k, tot);
                rem[i] += use;
                k -= use;
                int seat_rem = tot - use;
                tr.modify(i, {seat_rem, seat_rem});
            }
        }

        _norm();
        return true;
    }
};

/**
 * Your BookMyShow object will be instantiated and called as such:
 * BookMyShow* obj = new BookMyShow(n, m);
 * vector<int> param_1 = obj->gather(k,maxRow);
 * bool param_2 = obj->scatter(k,maxRow);
 */

// ~ JustJie