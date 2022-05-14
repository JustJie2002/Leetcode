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

constexpr int N = 9;
class Solution {
private:
    vector<array<bool, 10>> col, row, box;

    bool ck(int x, int y, int ch) {
        if (col[x][ch]) return 0;
        if (row[y][ch]) return 0;
        if (box[y / 3 * 3 + x / 3][ch]) return 0;
        return 1;
    }

    pair<int, int> nex(int x, int y) {
        x++;
        if (x == N) {
            x = 0;
            y++;
        }
        return {x, y};
    }

    bool go(int x, int y, vector<vector<char>>& board) {
        if (y == N) return true;
        auto p = nex(x, y);
        if (board[y][x] != '.') {
            return go(p.fi, p.se, board);
        }
        for (int i = 1; i <= N; i++) {
            char ch = i + '0';
            if (ck(x, y, i)) {
                board[y][x] = ch;
                col[x][i] = row[y][i] = box[y / 3 * 3 + x / 3][i] = 1;
                if (go(p.fi, p.se, board)) return true;
                col[x][i] = row[y][i] = box[y / 3 * 3 + x / 3][i] = 0;
                board[y][x] = '.';
            }
        }
        return false;
    }

public:
    void solveSudoku(vector<vector<char>>& board) {
        row.resize(N);
        col.resize(N);
        box.resize(N);
        for (int y = 0; y < N; y++)
            for (int x = 0; x < N; x++)
                if (board[y][x] != '.') {
                    int i = board[y][x] - '0';
                    col[x][i] = row[y][i] = box[y / 3 * 3 + x / 3][i] = 1;
                }
        go(0,0,board);
    }
};