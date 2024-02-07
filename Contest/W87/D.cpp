/********************************************
 * author : Jie Chen (3rd Year CS)
 * school : Rochester Institute of Technology
 * created: 02.01.2024 21:13:14
*********************************************/

using i64 = long long;

// http://www.open-std.org/jtc1/sc22/wg21/docs/papers/2016/p0200r0.html
template<class Fun> class y_combinator_result {
    Fun fun_;
public:
    template<class T> explicit y_combinator_result(T &&fun): fun_(std::forward<T>(fun)) {}
    template<class ...Args> decltype(auto) operator()(Args &&...args) { return fun_(std::ref(*this), std::forward<Args>(args)...); }
};
template<class Fun> decltype(auto) y_combinator(Fun &&fun) { return y_combinator_result<std::decay_t<Fun>>(std::forward<Fun>(fun)); }

constexpr int N = 12, MAX_MASK = 1 << N, INF = int(1e9) + 5;

int dp[N][MAX_MASK];

using Pair = pair<int, int>;

class Solution {
public:
    int shortestPathLength(vector<vector<int>>& adj) {
        int n = adj.size();

        queue<Pair> q;
        for (int i = 0; i < n; i++) {
            for (int msk = 0; msk < (1 << n); msk++) {
                dp[i][msk] = INF;
            }
            dp[i][1 << i] = 0;
            q.emplace(i, 1 << i);
        }

        while (!q.empty()) {
            auto [cur, msk] = q.front();
            q.pop();

            for (int nei : adj[cur]) {
                int nex_msk = msk | (1 << nei);
                if (dp[nei][nex_msk] > dp[cur][msk] + 1) {
                    dp[nei][nex_msk] = dp[cur][msk] + 1;
                    q.emplace(nei, nex_msk);
                }
            }
        }

        int ans = INF;
        const int all_visited = (1 << n) - 1;
        for (int i = 0; i < n; i++) {
            ans = min(ans, dp[i][all_visited]);
        }
        return ans;
    }
};

// ~ JustJie