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

constexpr int dy[] = {-1, 0, 1, 0};
constexpr int dx[] = {0, -1, 0, 1};
constexpr int dir = 4;
int memo[210][210];

class Solution {
public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        memset(memo, -1, sizeof memo);
        function<int(int, int, int)> dfs;
        int ans = 0;
        int m = sz(matrix), n = sz(matrix[0]);
        vector<vector<bool>> vis(m, vector<bool>(n, false));
        auto walkable = [&](int y, int x) {
            return 0 <= y && y < m && 0 <= x && x < n && !vis[y][x];
        };
        dfs = [&](int y, int x, int p) {
            if (memo[y][x] != -1) return memo[y][x];
            vis[y][x] = true;
            int longest = 1;
            for (int i = 0; i < dir; i++) {
                int ny = y + dy[i], nx = x + dx[i];
                if (walkable(ny, nx) && matrix[ny][nx] > p) {
                    ckmax(longest, 1 + dfs(ny, nx, matrix[ny][nx]));
                }
            }
            vis[y][x] = false;
            return memo[y][x] = longest;
        };
        for (int y = 0; y < m; y++)
            for (int x = 0; x < n; x++)
                ckmax(ans, dfs(y, x, matrix[y][x]));
        return ans;
    }
};