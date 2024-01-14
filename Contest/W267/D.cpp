/********************************************
 * author : Jie Chen (3rd Year CS)
 * school : Rochester Institute of Technology
 * created: 01.10.2024 23:56:25
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
    vector<bool> friendRequests(int n, vector<vector<int>>& res, vector<vector<int>>& req) {
        int Q = req.size();

        DSU uf(n);
        vector<bool> ans(Q, true);
        for (int q = 0; q < Q; q++) {
            DSU uf2 = uf;
            uf2.merge(req[q][0], req[q][1]);
            for (const auto& bad : res) {
                if (uf2.same(bad[0], bad[1])) {
                    ans[q] = false;
                    break;
                }
            }
            if (ans[q]) {
                uf.merge(req[q][0], req[q][1]);
            }
        }

        return ans;
    }
};

// ~ JustJie