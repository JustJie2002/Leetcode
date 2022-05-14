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
    int ans;
    int n;
    unordered_map<int, bool> lo, hi, xs;

    bool check(int y, int x) {
        if (xs.count(x) && xs[x]) return 0;
        if (lo.count(x - y) && lo[x - y]) return 0;
        if (hi.count(-y - x) && hi[-y - x]) return 0;
        return 1;
    }

    void recurse(int y) {
        if (y == n) return void(ans++);
        for (int x = 0; x < n; x++) {
            if (check(y, x)) {
                xs[x] = 1;
                lo[x - y] = 1;
                hi[-y - x] = 1;
                recurse(y + 1);
                xs[x] = 0;
                lo[x - y] = 0;
                hi[-y - x] = 0;
            }
        }
    }

public:
    int totalNQueens(int n) {
        this->n = n;
        recurse(0);
        return ans;
    }
};