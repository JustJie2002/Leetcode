/********************************************
 * author : Jie Chen (4th Year CS)
 * school : Rochester Institute of Technology
 * created: 07.27.2024 23:29:04
*********************************************/

using i64 = long long;

struct DSU {
    vector<int> par, siz;
    int components;

    DSU() {}
    DSU(int n): components(n) {
        init(n);
    }

    void init(int n) {
        par.resize(n);
        iota(par.begin(), par.end(), 0);
        siz.assign(n, 1);
    }

    int find(int x) {
        if (x != par[x]) {
            par[x] = find(par[x]);
        }
        return par[x];
    }

    bool same(int x, int y) {
        return find(x) == find(y);
    }
    bool merge(int x, int y) {
        x = find(x);
        y = find(y);
        if (x == y) {
            return false;
        }
        if (siz[x] > siz[y]) {
            swap(x, y);
        }
        siz[x] += siz[y];
        par[y] = x;
        components--;
        return true;
    }

    int size(int x) {
        return siz[find(x)];
    }
};

constexpr int inf = int(1e9) + 5;

class Solution {
public:
    bool canReachCorner(int x, int y, vector<vector<int>>& cirs) {
        int n = cirs.size();

        const auto square = [&](i64 x) {
            return x * x;
        };

        const auto distance = [&](int i, int j) {
            return square(cirs[i][0] - cirs[j][0]) + square(cirs[i][1] - cirs[j][1]);
        };

        const auto check = [&](int i, int j) {
            // distance(i, j) <= (r_i + r_j) ^ 2
            return distance(i, j) <= square(cirs[i][2] + cirs[j][2]);
        };

        DSU uf(n);
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                if (check(i, j)) {
                    uf.merge(i, j);
                }
            }
        }

        unordered_map<int, vector<int>> groups;
        for (int i = 0; i < n; i++) {
            groups[uf.find(i)].push_back(i);
        }

        for (const auto &[_, group] : groups) {
            int p[4] {};
            // x_min, y_min, x_max, y_max
            p[0] = p[1] = inf;
            for (int i : group) {
                int rad = cirs[i][2];
                p[0] = min(p[0], cirs[i][0] - rad);
                p[1] = min(p[1], cirs[i][1] - rad);
                p[2] = max(p[2], cirs[i][0] + rad);
                p[3] = max(p[3], cirs[i][1] + rad);
            }
            if (p[0] <= 0 && p[1] <= 0) {
                return false;
            }
            if (p[2] >= x && p[3] >= y) {
                return false;
            }
            if (p[0] <= 0 && p[2] >= x) {
                return false;
            }
            if (p[1] <= 0 && p[3] >= y) {
                return false;
            }
        }
        return true;
    }
};

// ~ JustJie