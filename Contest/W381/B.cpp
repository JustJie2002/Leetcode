/********************************************
 * author : Jie Chen (3rd Year CS)
 * school : Rochester Institute of Technology
 * created: 01.20.2024 21:37:39
*********************************************/

using i64 = long long;
using Info = pair<int, int>;

constexpr int INF = int(1e9) + 5;

class Solution {
public:
    vector<int> countOfPairs(int n, int x, int y) {
        x--, y--;
        vector<vector<int>> adj(n);
        for (int i = 0; i < n - 1; i++) {
            adj[i].push_back(i + 1);
            adj[i + 1].push_back(i);
        }
        adj[x].push_back(y);
        adj[y].push_back(x);

        vector<int> ans(n);
        int m = n - 1;
        if (x == y) {
            int cur = 2 * m;
            for (int i = 0; i < n; i++) {
                ans[i] = cur;
                cur -= 2;
            }
            return ans;
        }

        auto dij = [&](int src) -> void {
            vector<int> dis(n, INF);
            dis[src] = 0;
            priority_queue<Info, vector<Info>, greater<Info>> pq;
            pq.emplace(0, src);
            while (!pq.empty()) {
                auto [d, u] = pq.top();
                pq.pop();
                if (dis[u] != d) {
                    continue;
                }
                for (int nei : adj[u]) {
                    int nex_d = d + 1;
                    if (dis[nei] > nex_d) {
                        dis[nei] = nex_d;
                        pq.emplace(dis[nei], nei);
                    }
                }
            }
            for (int i = 0; i < n; i++) if (i != src) {
                ans[dis[i] - 1]++;
            }
        };

        for (int i = 0; i < n; i++) {
            dij(i);
        }
        return ans;
    }
};

// ~ JustJie