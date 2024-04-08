/********************************************
 * author : Jie Chen (3rd Year CS)
 * school : Rochester Institute of Technology
 * created: 04.06.2024 22:30:15
*********************************************/

using i64 = long long;
using Edge = array<int, 2>;

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
    vector<int> minimumCost(int n, vector<vector<int>>& edges, vector<vector<int>>& queries) {
        vector<vector<Edge>> adj(n);
        DSU uf(n);
        for (const auto& edge : edges) {
            int u = edge[0], v = edge[1], w = edge[2];
            adj[u].push_back({v, w});
            adj[v].push_back({u, w});
            uf.merge(u, v);
        }

        map<int, int> grp;
        for (const auto& edge : edges) {
            int u = edge[0], v = edge[1], w = edge[2];
            int fa = uf.find(u);
            if (grp.contains(fa)) {
                grp[fa] &= w;
            } else {
                grp[fa] = w;
            }
        }

        vector<int> res;
        for (const auto& q : queries) {
            int u = q[0], v = q[1];
            if (u == v) {
                res.push_back(0);
                continue;
            }
            if (!uf.same(u, v)) {
                res.push_back(-1);
            } else {
                int fa = uf.find(u);
                res.push_back(grp[fa]);
            }
        }

        return res;
    }
};

// ~ JustJie