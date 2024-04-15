/********************************************
 * author : Jie Chen (3rd Year CS)
 * school : Rochester Institute of Technology
 * created: 04.09.2024 12:37:45
*********************************************/

using i64 = long long;

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

        vector<int> dis(n);
        vector<int> seen(n, -1);
        auto bfs = [&](int src) {
            queue<int> q;
            q.push(src);
            seen[src] = src;
            for (int l = 0; !q.empty(); l++) {
                int siz = q.size();
                if (l) dis[l - 1] += siz;
                while (siz--) {
                    auto cur = q.front();
                    q.pop();

                    for (int nei : adj[cur]) {
                        if (seen[nei] != src) {
                            seen[nei] = src;
                            q.push(nei);
                        }
                    }
                }
            }
        };

        for (int i = 0; i < n; i++) {
            bfs(i);
        }

        return dis;
    }
};

// ~ JustJie