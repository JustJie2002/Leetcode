#ifdef DEBUG
#include "debug.h"
#else
#define debug(...) 42
#endif

using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;
using vs = vector<string>;
using vpi = vector<pii>;
using vl = vector<ll>;

#define pb push_back
#define mp make_pair
#define eb emplace_back
#define ins insert
#define fi first
#define se second
#define all(v) (v).begin(), (v).end()
#define rall(v) (v).rbegin(), (v).rend()
#define sz(a) int(a.size())

const int inf = 1E9;
const ll INF = 1E18;
const int MOD = 1E9 + 7;
const char nl = '\n';

template <typename T> bool ckmax(T &a, T b) { return a < b ? a = b, true : false; }
template <typename T> bool ckmin(T &a, T b) { return a > b ? a = b, true : false; }

class Solution {
public:
    bool checkValid(vector<vector<int>>& matrix) {
        int n = sz(matrix);
        vector<unordered_set<int>> row(n), col(n);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) row[i].ins(matrix[i][j]);
            if (sz(row[i]) != n) return false;
        }
        for (int j = 0; j < n; j++) {
            for (int i = 0; i < n; i++) col[j].ins(matrix[i][j]);
            if (sz(col[j]) != n) return false;
        }
        return true;
    }
};