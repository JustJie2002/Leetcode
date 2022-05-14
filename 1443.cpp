using i64 = long long;
using pii = pair<int, int>;

#define pb push_back
#define mp make_pair
#define ins insert
#define fi first
#define se second
#define all(v) (v).begin(), (v).end()
#define rall(v) (v).rbegin(), (v).rend()
#define sz(a) int(a.size())

template <typename T> bool ckmax(T &a, T b) { return a < b ? a = b, true : false; }
template <typename T> bool ckmin(T &a, T b) { return a > b ? a = b, true : false; }

constexpr int INF = 1E9;

class Solution {
public:
    int minTime(int n, vector<vector<int>>& edges, vector<bool>& hasApple) {
        vector<vector<int>> g(n);
        for (const auto& edge : edges) {
            int u = edge[0], v = edge[1];
            g[u].pb(v);
            g[v].pb(u);
        }
        function<int(int, int)> dfs = [&](int id, int p) {
            int sum = 0;
            for (int nei : g[id]) {
                if (nei == p) continue;
                sum += dfs(nei, id);
            }
            sum += (hasApple[id] || sum) && id ? 2 : 0;
            // printf("%d %d\n", id, sum);
            return sum;
        };
        return dfs(0, -1);
    }
};