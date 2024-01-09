/********************************************
 * author : Jie Chen (3rd Year CS)
 * school : Rochester Institute of Technology
 * created: 01.06.2024 18:12:34
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
    vector<int> lexicographicallySmallestArray(vector<int>& a, int LIM) {
        int n = a.size();

        vector<int> ord(n);
        iota(ord.begin(), ord.end(), 0);
        sort(ord.begin(), ord.end(), [&](int i, int j) {
            return a[i] < a[j];
        });

        DSU uf(n);
        for (int i = 1; i < n; i++) {
            if (a[ord[i]] - a[ord[i - 1]] <= LIM) {
                uf.merge(ord[i], ord[i - 1]);
            }
        }

        map<int, vector<int>> group;
        for (int i = 0; i < n; i++) {
            int fa = uf.find(i);
            group[fa].push_back(i);
        }

        vector<int> res(n);
        for (auto& [_, grp] : group) {
            auto sorted = grp;
            sort(sorted.begin(), sorted.end(), [&](int i, int j) {
                return a[i] < a[j];
            });
            int m = sorted.size();
            for (int i = 0; i < m; i++) {
                int cur = grp[i];
                int to = sorted[i];
                res[cur] = a[to];
            }
        }

        return res;
    }
};

// ~ JustJie