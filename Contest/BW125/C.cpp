/********************************************
 * author : Jie Chen (3rd Year CS)
 * school : Rochester Institute of Technology
 * created: 03.02.2024 14:02:39
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
using Edge = pair<int, int>;

class Solution {
public:
    vector<int> countPairsOfConnectableServers(vector<vector<int>>& edges, int ss) {
        int n = edges.size() + 1;

        vector<vector<Edge>> adj(n);
        for (const auto& edge : edges) {
            int u = edge[0], v = edge[1], w = edge[2];
            adj[u].emplace_back(v, w);
            adj[v].emplace_back(u, w);
        }

        auto work = [&](int u) -> int {
            int res = 0;
            int p = 0;
            for (const auto& [nei, w] : adj[u]) {
                int tot = 0;
                y_combinator([&](auto&& dfs, int cur, int fa, int val) -> void {
                    if (val > 0 && val % ss == 0) {
                        tot++;
                    }
                    for (const auto& [nei, w] : adj[cur]) {
                        if (nei == fa) continue;
                        dfs(nei, cur, val + w);
                    }
                })(nei, u, w);
                res += p * tot;
                p += tot;
            }
            return res;
        };

        vector<int> ans(n);
        for (int i = 0; i < n; i++) {
            ans[i] = work(i);
        }

        return ans;
    }
};

// ~ JustJie