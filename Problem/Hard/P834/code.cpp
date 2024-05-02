/********************************************
 * author : Jie Chen (3rd Year CS)
 * school : Rochester Institute of Technology
 * created: 04.28.2024 01:55:23
*********************************************/

// http://www.open-std.org/jtc1/sc22/wg21/docs/papers/2016/p0200r0.html
template<class Fun> class y_combinator_result {
    Fun fun_;
public:
    template<class T> explicit y_combinator_result(T &&fun): fun_(std::forward<T>(fun)) {}
    template<class ...Args> decltype(auto) operator()(Args &&...args) { return fun_(std::ref(*this), std::forward<Args>(args)...); }
};
template<class Fun> decltype(auto) y_combinator(Fun &&fun) { return y_combinator_result<std::decay_t<Fun>>(std::forward<Fun>(fun)); }

using i64 = long long;
using Info = array<int, 2>;

Info operator+(const Info& a, const Info& b) {
    return {a[0] + b[0], a[1] + b[1]};
}

class Solution {
public:
    vector<int> sumOfDistancesInTree(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);
        for (const auto& e : edges) {
            int u = e[0];
            int v = e[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        // use dp on tree
        vector<Info> dp(n);
        for (int i = 0; i < n; i++) {
            dp[i] = {};
        }
        y_combinator([&](auto&& dfs, int cur, int fa) -> Info {
            for (int nei : adj[cur]) {
                if (nei != fa) {
                    dp[cur] = dp[cur] + dfs(nei, cur);
                }
            }
            Info res = dp[cur];
            res[1]++;
            res[0] += res[1];
            return res;
        })(0, 0);

        vector<int> dis(n);
        for (int i = 0; i < n; i++) {
            dis[i] = dp[i][0];
        }
        Info base = {0, 0};
        y_combinator([&](auto&& dfs, int cur, int fa, Info info) -> void {
            dis[cur] += info[0];
            for (int nei : adj[cur]) {
                if (nei != fa) {
                    int other_dis = dp[cur][0] - (dp[nei][0] + dp[nei][1]) - 1;
                    int other = dp[cur][1] - dp[nei][1];
                    Info new_info = info;
                    new_info[1] += other;
                    new_info[0] += new_info[1] + other_dis;
                    dfs(nei, cur, new_info);
                }
            }
        })(0, 0, base);
        return dis;
    }
};

// ~ JustJie
