/********************************************
 * author : Jie Chen (3rd Year CS)
 * school : Rochester Institute of Technology
 * created: 12.23.2023 10:07:53
*********************************************/

using i64 = long long;

struct Info {
    multiset<int> s;
    Info() {}
    void update(int x) {
        s.insert(x);
        if (s.size() > 5) {
            auto it = next(next(s.begin()));
            s.erase(it);
        }
    }
    int pop() {
        assert(!s.empty());
        auto it = s.begin();
        int x = *it;
        s.erase(it);
        return x;
    }
};

class Solution {
public:
    vector<long long> placedCoins(vector<vector<int>>& edges, vector<int>& w) {
        int n = w.size();

        vector<vector<int>> adj(n);
        for (const auto& edge : edges) {
            int u = edge[0], v = edge[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        // we just have top 5 and bot 5
        vector<i64> res(n);
        vector<int> cnt(n);
        // 2 smallest 3 largest
        function<Info(int, int)> dfs = [&](int u, int fa) -> Info {
            Info info;
            info.update(w[u]);
            cnt[u] = 1;
            for (int v : adj[u]) if (v != fa) {
                Info o = dfs(v, u);
                cnt[u] += cnt[v];
                while (!o.s.empty()) {
                    info.update(o.pop());
                }
            }
            if (cnt[u] < 3) {
                res[u] = 1;
            } else {
                i64 a = 1, b = 1;
                auto it1 = info.s.begin();
                for (int i = 0; i < info.s.size() - 1; i++) {
                    it1 = next(it1);
                }
                b = b * (*it1);
                for (int i = 0; i < 3; i++, it1 = prev(it1)) {
                    a = a * (*it1);
                }
                auto it2 = info.s.begin();
                for (int i = 0; i < 2; i++, it2 = next(it2)) {
                    b = b * (*it2);
                }
                i64 p = max(a, b);
                if (p > 0) {
                    res[u] = p;
                }
            }
            return info;
        };
        dfs(0, 0);

        return res;
    }
};

// ~ JustJie