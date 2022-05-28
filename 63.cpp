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
    int uniquePathsWithObstacles(vector<vector<int>>& g) {
        int m = sz(g), n = sz(g[0]);
        vector<vector<int>> dp(m, vector<int>(n));
        if (g[0][0] == 1) return 0;
        dp[0][0] = 1;
        for (int y = 0; y < m; y++) {
            for (int x = 0; x < n; x++) {
                if (g[y][x] == 1) continue;
                if (y && g[y - 1][x] == 0)
                    dp[y][x] += dp[y - 1][x];
                if (x && g[y][x - 1] == 0)
                    dp[y][x] += dp[y][x - 1];
            }
        }
        return dp[m - 1][n - 1];
    }
};