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
    int networkDelayTime(vector<vector<int>>& edges, int n, int start) {
        start--;
        vector<vector<pii>> g(n);
        for (auto& edge : edges) {
            int from = edge[0] - 1, to = edge[1] - 1, wei = edge[2];
            g[from].emplace_back(to, wei);    
        }
        // dijkstra
        vector<int> dist(n, INF);
        priority_queue<pii, vector<pii>, greater<pii>> q;
        q.emplace(0, start);
        dist[start] = 0;
        while (!q.empty()) {
            auto [w, cur] = q.top(); q.pop();
            // printf("cur: %d w: %d\n", cur, w);
            
            for (const auto& nei : g[cur]) {
                if (ckmin(dist[nei.fi], w + nei.se)) {
                    q.emplace(dist[nei.fi], nei.fi);
                }
            }
        }
        int mx = -1;
        for (int i = 0; i < n; i++) ckmax(mx, dist[i]);
        return mx == INF ? -1 : mx;
    }
};