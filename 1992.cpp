class Solution {
private:
    constexpr static int dr[4] = {0, 0, -1, 1};
    constexpr static int dc[4] = {-1, 1, 0, 0};
public:
    vector<vector<int>> findFarmland(vector<vector<int>>& a) {
        int m = a.size(), n = a[0].size();
        vector vis(m, vector<bool>(n, false));
        vector<vector<int>> res;

        auto check = [&] (int r, int c) -> bool {
            return 0 <= r && r < m && 0 <= c && c < n && !vis[r][c] && a[r][c] == 1;
        };

        for (int r = 0; r < m; r++) {
            for (int c = 0; c < n; c++) {
                if (check(r, c)) {
                    queue<pair<int, int>> q;
                    q.emplace(r, c);
                    vis[r][c] = 1;
                    int mnr = r, mnc = c, mxr = r, mxc = c;
                    while (!q.empty()) {
                        auto [r, c] = q.front();
                        q.pop();

                        for (int i = 0; i < 4; i++) {
                            int nr = r + dr[i];
                            int nc = c + dc[i];

                            if (check(nr, nc)) {
                                q.emplace(nr, nc);
                                vis[nr][nc] = 1;
                                mnr = min(mnr, nr);
                                mnc = min(mnc, nc);
                                mxr = max(mxr, nr);
                                mxc = max(mxc, nc);
                            }
                        }
                    }
                    res.push_back({mnr, mnc, mxr, mxc});
                }
            }
        }
        return res;
    }
};
