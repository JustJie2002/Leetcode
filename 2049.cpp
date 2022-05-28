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

class Solution {
public:
    int countHighestScoreNodes(vector<int>& parents) {
        function<int(int, int)> dfs;
        int n = sz(parents);
        vector<vector<int>> adj(n);
        for (int i = 0; i < n; i++) {
            if (parents[i] == -1) continue;
            adj[parents[i]].pb(i);
        }
        vector<int> nodes(n);
        dfs = [&](int id, int p) {
            int total = 1;
            for (int nei : adj[id]) if (nei != p) total += dfs(nei, id);
            return nodes[id] = total;
        };
        dfs(0, -1);
        i64 best = 0;
        unordered_map<i64, int> m;
        for (int i = 0; i < n; i++) {
            // what if we remove i
            i64 p = 1LL;
            for (int nei : adj[i]) p *= nodes[nei];
            if (i != 0) p *= nodes[0] - nodes[i];
            m[p]++;
            ckmax(best, p);
        }
        return m[best];
    }
};