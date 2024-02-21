/********************************************
 * author : Jie Chen (3rd Year CS)
 * school : Rochester Institute of Technology
 * created: 02.12.2024 10:30:57
*********************************************/

using i64 = long long;
using Info = pair<int, int>;

// http://www.open-std.org/jtc1/sc22/wg21/docs/papers/2016/p0200r0.html
template<class Fun> class y_combinator_result {
    Fun fun_;
public:
    template<class T> explicit y_combinator_result(T &&fun): fun_(std::forward<T>(fun)) {}
    template<class ...Args> decltype(auto) operator()(Args &&...args) { return fun_(std::ref(*this), std::forward<Args>(args)...); }
};
template<class Fun> decltype(auto) y_combinator(Fun &&fun) { return y_combinator_result<std::decay_t<Fun>>(std::forward<Fun>(fun)); }

class Solution {
public:
    int numOfMinutes(int n, int root, vector<int>& parent, vector<int>& t) {
        vector<vector<Info>> adj(n);
        for (int i = 0; i < n; i++) if (i != root) {
            int par = parent[i];
            adj[par].emplace_back(i, t[par]);
        }

        return y_combinator([&](auto&& dfs, int cur) -> int {
            int res = 0;
            for (const auto& [nei, w] : adj[cur]) {
                res = max(res, dfs(nei) + w);
            }
            return res;
        })(root);
    }
};

// ~ JustJie