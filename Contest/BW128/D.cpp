/********************************************
 * author : Jie Chen (3rd Year CS)
 * school : Rochester Institute of Technology
 * created: 04.13.2024 11:47:59
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
    i64 numberOfSubarrays(vector<int>& a) {
        int n = a.size();

        map<int, vector<int>> pos;
        for (int i = 0; i < n; i++) {
            pos[a[i]].push_back(i);
        }

        DSU uf(n);
        i64 ans = 0;
        unordered_map<int, int> grp;
        for (const auto& [x, v] : pos) {
            for (int cur : v) {
                for (int j : {-1, +1}) {
                    int nei = cur + j;
                    if (0 <= nei && nei < n && a[nei] <= a[cur]) {
                        uf.merge(cur, nei);
                    }
                }
            }
            for (int cur : v) {
                int fa = uf.find(cur);
                ans += ++grp[fa];
            }
            grp.clear();
        }
        return ans;
    }
};

// ~ JustJie