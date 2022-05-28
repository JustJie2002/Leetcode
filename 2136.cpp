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
    int earliestFullBloom(vector<int>& plant, vector<int>& grow) {
        int n = sz(plant);
        vpi a;
        for (int i = 0; i < n; i++) {
            a.eb(grow[i], plant[i]);
        }
        sort(all(a), [&](const auto& p1, const auto& p2) {
            if (p1.fi != p2.fi) return p1.fi > p2.fi;
            return p1.se < p2.se;
        });
        int par = 0;
        int ans = 0;
        for (const auto& p : a) {
            ckmax(ans, par + p.se + p.fi);
            par += p.se;
        }
        return ans;
    }
};