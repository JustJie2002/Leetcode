/********************************************
 * author : Jie Chen (3rd Year CS)
 * school : Rochester Institute of Technology
 * created: 05.08.2024 23:02:48
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

class Solution {
public:
    i64 countPairs(int n, vector<vector<int>>& edges) {
        DSU uf(n);
        for (const auto& e : edges) {
            int u = e[0], v = e[1];
            uf.merge(u, v);
        }

        i64 ans = 0, cnt = 0;
        for (int i = 0; i < n; i++) {
            if (uf.find(i) == i) {
                int siz = uf.size(i);
                ans += 1LL * cnt * siz;
                cnt += siz;
            }
        }
        return ans;
    }
};

// ~ JustJie