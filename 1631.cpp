constexpr int INF = 1E9;
constexpr int dr[] = {-1, 1, 0, 0};
constexpr int dc[] = { 0, 0,-1, 1};

using PII = pair<int, pair<int, int>>;

class Solution {
private:
    int m, n;

public:
    bool check(int r, int c) {
        return 0 <= r && r < m && 0 <= c && c < n;
    }

    int minimumEffortPath(vector<vector<int>>& wei) {
        m = wei.size(), n = wei[0].size();
        // dist[i][j] = min adjacent difference
        vector dist(m, vector<int>(n, INF));
        vector vis(m, vector<bool>(n, false));
        priority_queue<PII, vector<PII>, greater<PII>> q;
        q.push({0, make_pair(0, 0)});
        dist[0][0] = 0;
        while (!q.empty()) {
            auto [w, u] = q.top(); q.pop();
            auto [r, c] = u;

            if (vis[r][c]) continue;
            vis[r][c] = true;

            for (int i = 0; i < 4; i++) {
                int nr = r + dr[i];
                int nc = c + dc[i];
                if (!check(nr, nc)) continue;
                // check difference between this coord and prev
                int diff = abs(wei[nr][nc] - wei[r][c]);
                if (dist[nr][nc] > diff) {
                    dist[nr][nc] = max(dist[r][c], diff);
                    q.push({dist[nr][nc], make_pair(nr, nc)});
                }
            }
        }
        return dist[m - 1][n - 1];
    }
};