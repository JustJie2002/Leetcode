/********************************************
 * author : Jie Chen (3rd Year CS)
 * school : Rochester Institute of Technology
 * created: 02.06.2024 22:05:25
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
    int numSimilarGroups(vector<string>& words) {
        int n = words.size(), m = words[0].size();

        auto good = [&](const auto& a, const auto& b) -> bool {
            int dif = 0;
            for (int i = 0; i < m; i++) {
                if (a[i] != b[i]) {
                    dif++;
                }
            }
            return dif <= 2;
        };

        DSU uf(n);
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                if (good(words[i], words[j])) {
                    uf.merge(i, j);
                }
            }
        }

        unordered_set<int> s;
        for (int i = 0; i < n; i++) {
            s.insert(uf.find(i));
        }

        return int(s.size());
    }
};

// ~ JustJie