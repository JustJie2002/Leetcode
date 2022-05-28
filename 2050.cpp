using i64 = long long;
using pii = pair<int, int>;
using vi = vector<int>;

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
    int minimumTime(int n, vector<vector<int>>& relations, vector<int>& time) {
        vector<vector<int>> adj(n);
        vector<int> indegree(n);
        for (const auto& relation : relations) {
            int from = relation[0] - 1, to = relation[1] - 1;
            adj[from].pb(to);
            indegree[to]++;
        }
        priority_queue<pii, vector<pii>, greater<pii>> pq;
        for (int i = 0; i < n; i++) {
            if (!indegree[i]) pq.emplace(time[i], i);
        }
        vector<int> dist(n);
        int mx = 0;
        while (!pq.empty()) {
            auto [w, x] = pq.top(); pq.pop();
            
            ckmax(mx, w);
            
            for (int nei : adj[x]) {
                --indegree[nei];
                ckmax(dist[nei], w);
                if (!indegree[nei]) {
                    pq.emplace(dist[nei] + time[nei], nei);
                }
            }
        }
        return mx;
    }
};