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
    vector<int> avoidFlood(vector<int>& rains) {
        int n = sz(rains);
        vector<int> ans(n);
        unordered_map<int, int> lst;
        set<int> s;
        for (int i = 0; i < n; i++) {
            int x = rains[i];
            if (x == 0)
                s.ins(i);
            else {
                ans[i] = -1;
                if (lst.count(x)) {
                    int last = lst[x];
                    auto it =  s.lower_bound(last);
                    if (it == s.end())
                        return vector<int>();
                    else {
                        ans[*it] = x;
                        s.erase(it);
                    }
                }
                lst[x] = i;
            }
        }
        for (int x : s) ans[x] = 1;
        return ans;
    }
};