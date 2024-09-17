/********************************************
 * author : Jie Chen (4th Year CS)
 * school : Rochester Institute of Technology
 * created: 08.17.2024 10:34:30
*********************************************/

using i64 = long long;

constexpr i64 inf = 1e15 + 10;

// Credit: Jiangly
template<class Info, class Tag>
struct LazySegmentTree {
    int n;
    vector<Info> info;
    vector<Tag> tag;
    LazySegmentTree() : n(0) {}
    LazySegmentTree(int n_, Info v_ = Info()) {
        init(n_, v_);
    }
    template<class T>
    LazySegmentTree(vector<T> init_) {
        init(init_);
    }
    void init(int n_, Info v_ = Info()) {
        init(vector(n_, v_));
    }
    template<class T>
    void init(vector<T> init_) {
        n = init_.size();
        info.assign(4 << __lg(n), Info());
        tag.assign(4 << __lg(n), Tag());
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
    void apply(int p, const Tag &v) {
        info[p].apply(v);
        tag[p].apply(v);
    }
    void push(int p) {
        apply(2 * p, tag[p]);
        apply(2 * p + 1, tag[p]);
        tag[p] = Tag();
    }
    void modify(int p, int l, int r, int x, const Info &v) {
        if (r - l == 1) {
            info[p] = v;
            return;
        }
        int m = (l + r) / 2;
        push(p);
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
        push(p);
        return range_query(2 * p, l, m, x, y) + range_query(2 * p + 1, m, r, x, y);
    }
    Info range_query(int l, int r) {
        return range_query(1, 0, n, l, r);
    }
    void range_apply(int p, int l, int r, int x, int y, const Tag &v) {
        if (l >= y || r <= x) {
            return;
        }
        if (l >= x && r <= y) {
            apply(p, v);
            return;
        }
        int m = (l + r) / 2;
        push(p);
        range_apply(2 * p, l, m, x, y, v);
        range_apply(2 * p + 1, m, r, x, y, v);
        pull(p);
    }
    void range_apply(int l, int r, const Tag &v) {
        return range_apply(1, 0, n, l, r, v);
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
        push(p);
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
        push(p);
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

struct Tag {
    i64 x = -inf;
    void apply(const Tag &t) {
        x = max(x, t.x);
    }
};
struct Info {
    i64 x = -inf;
    void apply(const Tag &t) {
        x = max(x, t.x);
    }
};
 
Info operator+(const Info &a, const Info &b) {
    return {max(a.x, b.x)};
}

using Pair = pair<i64, int>;

class Solution {
public:
    long long maximumValueSum(vector<vector<int>>& aa) {
        int n = aa.size();
        int m = aa[0].size();

        set<Pair> s;
        vector<i64> mx(m);
        i64 ans = -inf;
        LazySegmentTree<Info, Tag> seg(m);

        const auto update = [&](int x, int y, i64 res) {
            if (x > y) {
                swap(x, y);
            }
            Tag ins = {res};
            seg.range_apply(0, x, ins);
            seg.range_apply(x + 1, y, ins);
            seg.range_apply(y + 1, n, ins);
        };

        for (int i = 0; i < n; i++) {
            if (i > 1) {
                for (int j = 0; j < m; j++) {
                    i64 res = seg.range_query(j, j + 1).x;
                    ans = max(ans, res + aa[i][j]);
                }
            }
            if (i > 0) {
                for (int j = 0; j < m; j++) {
                    auto it = s.rbegin();
                    while (it->second == j) {
                        it++;
                    }
                    update(j, it->second, it->first + aa[i][j]);
                    do {
                        it++;
                    } while (it->second == j);
                    update(j, it->second, it->first + aa[i][j]);
                }
            }
            for (int j = 0; j < m; j++) {
                if (i == 0) {
                    s.emplace(aa[i][j], j);
                    mx[j] = aa[i][j];
                } else if (aa[i][j] > mx[j]) {
                    s.erase({mx[j], j});
                    s.emplace(aa[i][j], j);
                    mx[j] = aa[i][j];
                }
            }
        }
        return ans;
    }
};

// ~ JustJie