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
    long double f(vi a, vi b) {
        return (long double) (b[1] - a[1]) / (b[0] - a[0]);
    }
public:
    int minimumLines(vector<vector<int>>& a) {
        if (sz(a) == 1) return 0;
        sort(all(a));
        long double p = f(a[1], a[0]);
        int ans = 1;
        for (int i = 1; i < sz(a); i++) {
            long double slope = f(a[i], a[i - 1]);
            if (slope != p) {
                ++ans;
                p = slope;
            }
        }
        return ans;
    }
};