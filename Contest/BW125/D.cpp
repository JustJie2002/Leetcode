/********************************************
 * author : Jie Chen (3rd Year CS)
 * school : Rochester Institute of Technology
 * created: 03.02.2024 09:30:16
*********************************************/

string to_string(string s) {
    return '"' + s + '"';
}

string to_string(const char* s) {
    return to_string((string) s);
}

string to_string(bool b) {
    return (b ? "true" : "false");
}

template <typename A, typename B>
string to_string(pair<A, B> p) {
    return "(" + to_string(p.first) + ", " + to_string(p.second) + ")";
}

template <typename A>
string to_string(A v) {
    bool first = true;
    string res = "{";
    for (const auto &x : v) {
        if (!first) {
            res += ", ";
        }
        first = false;
        res += to_string(x);
    }
    res += "}";
    return res;
}

void debug_out() { cout << endl; }

template <typename Head, typename... Tail>
void debug_out(Head H, Tail... T) {
    cout << " " << to_string(H);
    debug_out(T...);
}

// #define BROKEN_CODE

#ifdef BROKEN_CODE
    #define dbg(...) cout << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)
    #define dbp(...) cout << __VA_ARGS__ << "\n";
#else
    #define dbg(...) 10082002
    #define dbp(...) "Gimme Internship"
#endif

// http://www.open-std.org/jtc1/sc22/wg21/docs/papers/2016/p0200r0.html
template<class Fun> class y_combinator_result {
    Fun fun_;
public:
    template<class T> explicit y_combinator_result(T &&fun): fun_(std::forward<T>(fun)) {}
    template<class ...Args> decltype(auto) operator()(Args &&...args) { return fun_(std::ref(*this), std::forward<Args>(args)...); }
};
template<class Fun> decltype(auto) y_combinator(Fun &&fun) { return y_combinator_result<std::decay_t<Fun>>(std::forward<Fun>(fun)); }

using i64 = long long;
using Pair = pair<i64, i64>;

constexpr i64 INF = 1e18 + 10;

class Solution {
public:
    long long maximumValueSum(vector<int>& a, int k, vector<vector<int>>& edges) {
        int n = a.size();

        vector<vector<int>> adj(n);
        // always a tree
        for (const auto& edge : edges) {
            int u = edge[0], v = edge[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        vector<array<i64, 2>> dp(n);
        for (int i = 0; i < n; i++) {
            for (int c = 0; c < 2; c++) {
                dp[i][c] = -1;
            }
        }

        return y_combinator([&](auto&& dfs, int cur, int fa, bool changed) -> i64 {
            if (dp[cur][changed] != -1) {
                return dp[cur][changed];
            }
            int cur_v = (changed ? a[cur] ^ k : a[cur]);
            bool is_leaf = true;
            vector<Pair> res;
            for (int nei : adj[cur]) {
                if (nei == fa) continue;
                is_leaf = false;
                i64 op1 = dfs(nei, cur, false);
                i64 op2 = dfs(nei, cur, true);
                res.emplace_back(op1, op2);
            }
            if (is_leaf) {
                return dp[cur][changed] = cur_v;
            }
            // suppose we want xor
            int free = 0;
            int c = int(changed);
            i64 tot = 0;
            i64 dif1 = INF;
            i64 dif2 = INF;
            for (const auto& [r1, r2] : res) {
                tot += max(r1, r2);
                if (r1 == r2) {
                    free++;
                } else if (r2 > r1) {
                    dif1 = min(dif1, r2 - r1);
                    c++;
                } else {
                    dif2 = min(dif2, r1 - r2);
                }
            }
            { // odd # of c
                i64 want_xor = tot;
                if (c % 2 == 0 && free == 0) {
                    want_xor -= min(dif1, dif2);
                }
                dbg(cur, want_xor);
                dp[cur][changed] = max(dp[cur][changed], want_xor + (a[cur] ^ k));
            }
            { // even # of c
                i64 no_xor = tot;
                if (c % 2 == 1 && free == 0) {
                    no_xor -= min(dif1, dif2);
                }
                dbg(cur, no_xor);
                dp[cur][changed] = max(dp[cur][changed], no_xor + a[cur]);
            }
            return dp[cur][changed];
        })(0, 0, false);
    }
};

// ~ JustJie