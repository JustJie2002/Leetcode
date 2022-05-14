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
const int dy[] = {-1, 0, 1, 0};
const int dx[] = {0, -1, 0, 1};

class Solution {
public:
    int minFlips(vector<vector<int>>& mat) {
        int m = sz(mat), n = sz(mat[0]);
        auto doo = [&](int y, int x) -> int {
            return y * n + x;
        };
        int mask = 0;
        for (int y = 0; y < m; y++) {
            for (int x = 0; x < n; x++) {
                if (!mat[y][x]) continue;
                mask |= 1 << doo(y, x);
            }
        }
        auto check = [&](int y, int x) -> int {
            return 0 <= y && y < m && 0 <= x && x < n;
        };
        unordered_map<int, int> pred;
        queue<int> q;
        q.push(mask);
        pred[mask] = 0;
        while (!q.empty()) {
            int cur = q.front(); q.pop();
            
            if (cur == 0) return pred[cur];
            
            for (int y = 0; y < m; y++) {
                for (int x = 0; x < n; x++) {
                    int m = cur;
                    m ^= 1 << doo(y, x);
                    for (int i = 0; i < 4; i++) {
                        int ny = y + dy[i];
                        int nx = x + dx[i];
                        if (check(ny, nx)) {
                            m ^= 1 << doo(ny, nx);
                        }
                    }
                    if (!pred.count(m)) {
                        q.push(m);
                        pred[m] = pred[cur] + 1;
                    }
                }
            }
        }
        return -1;
    }
};