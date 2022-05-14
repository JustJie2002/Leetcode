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
private:
    vector<string> board;
    vector<vector<string>> ans;
    int size;
    unordered_map<int, bool> xs, lo, hi;

    bool check(int y, int x) {
        if (xs.count(x) && xs[x]) return 0;
        if (lo.count(x - y) && lo[x - y]) return 0;
        if (hi.count(-y - x) && hi[-y - x]) return 0;
        return 1;
    }

    void go(int y) {
        if (y == size) return void(ans.pb(board));
        for (int x = 0; x < size; x++) {
            if (check(y, x)) {
                xs[x] = 1;
                lo[x - y] = 1;
                hi[-y - x] = 1;
                board[y][x] = 'Q';
                go(y + 1);
                xs[x] = 0;
                lo[x - y] = 0;
                hi[-y - x] = 0;
                board[y][x] = '.';
            }
        }
    }

public:
    vector<vector<string>> solveNQueens(int n) {
        board.resize(n, string(n, '.'));
        size = n;
        go(0);
        return ans;
    }
};