/********************************************
 * author : Jie Chen (3rd Year CS)
 * school : Rochester Institute of Technology
 * created: 02.22.2024 20:01:46
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

using Position = pair<int, int>;

constexpr int di[] = {0, 1, 0, -1};
constexpr int dj[] = {1, 0, -1, 0};

class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();

        map<int, vector<Position>> t;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                t[grid[i][j]].emplace_back(i, j);
            }
        }

        auto good = [&](int i, int j) -> bool {
            bool ok = (0 <= i && i < n);
            ok &= (0 <= j && j < m);
            return ok;
        };

        auto encrypt = [&](int i, int j) -> int {
            return i * m + j;
        };

        DSU uf(n * m);
        for (const auto& [time, pos] : t) {
            for (const auto& [i, j] : pos) {
                for (int d = 0; d < 4; d++) {
                    int ni = i + di[d];
                    int nj = j + dj[d];
                    if (good(ni, nj) && grid[i][j] >= grid[ni][nj]) {
                        uf.merge(
                            encrypt(i, j),
                            encrypt(ni, nj)
                        );
                    }
                }
            }

            if (uf.same(0, n * m - 1)) {
                return time;
            }
        }

        assert(false);
    }
};

// ~ JustJie