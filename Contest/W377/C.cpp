/********************************************
 * author : Jie Chen (3rd Year CS)
 * school : Rochester Institute of Technology
 * created: 12.23.2023 21:48:34
*********************************************/

using i64 = long long;
using Edge = pair<int, int>;

constexpr int A = 26, inf = int(1e9) + 5;
int w[A][A];

constexpr int ord(char c) {
    return c -'a';
}

class Solution {
public:
    long long minimumCost(string s, string t, vector<char>& a, vector<char>& b, vector<int>& c) {
        int n = s.size();
        int m = a.size();

        vector<vector<Edge>> adj(A);

        for (int i = 0; i < A; i++) {
            for (int j = 0; j < A; j++) {
                w[i][j] = inf;
            }
        }

        for (int i = 0; i < m; i++) {
            int from = ord(a[i]), to = ord(b[i]);
            adj[from].emplace_back(to, c[i]);
        }

        auto ckmin = [&](int& a, int b) -> bool {
            if (b < a) {
                a = b;
                return true;
            }
            return false;
        };

        auto dijkstra = [&](int src) -> void {
            w[src][src] = 0;
            priority_queue<Edge, vector<Edge>, greater<Edge>> pq;
            pq.emplace(0, src);
            while (!pq.empty()) {
                auto [cur_cost, from] = pq.top();
                pq.pop();
                if (cur_cost != w[src][from]) {
                    continue;
                }
                for (const auto& [to, cost] : adj[from]) {
                    if (ckmin(w[src][to], cur_cost + cost)) {
                        pq.emplace(w[src][to], to);
                    }
                }
            }
        };

        for (int i = 0; i < A; i++) {
            dijkstra(i);
        }

        i64 ans = 0;
        for (int i = 0; i < n; i++) {
            int from = ord(s[i]), to = ord(t[i]);
            if (w[from][to] == inf) {
                return -1;
            }
            ans += w[from][to];
        }

        return ans;
    }
};

// ~ JustJie