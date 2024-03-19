/********************************************
 * author : Jie Chen (3rd Year CS)
 * school : Rochester Institute of Technology
 * created: 03.18.2024 17:28:13
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
    int numberOfGoodPaths(vector<int>& a, vector<vector<int>>& edges) {
        int n = a.size();

        map<int, vector<int>> groups;
        for (int i = 0; i < n; i++) {
            groups[a[i]].push_back(i);
        }

        vector<vector<int>> adj(n);
        for (const auto& edge : edges) {
            int u = edge[0], v = edge[1];
            for (int _ = 0; _ < 2; _++) {
                if (a[u] >= a[v]) {
                    adj[u].push_back(v);
                }
                swap(u, v);
            }
        }

        DSU uf(n);
        int ans = 0;
        for (const auto& [_, same] : groups) {
            for (int cur : same) {
                for (int nei : adj[cur]) {
                    uf.merge(cur, nei);
                }
            }

            unordered_map<int, int> comps;
            for (int cur : same) {
                ans += ++comps[uf.find(cur)];
            }
        }

        return ans;
    }
};

// ~ JustJie