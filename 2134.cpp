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
    int minSwaps(vector<int>& nums) {
        int o = 0;
        for (int x : nums) o += x;
        int n = sz(nums);
        for (int i = 0; i < n; i++) nums.pb(nums[i]);
        n *= 2;
        vector<int> pre(n + 1);
        for (int i = 0; i < n; i++) {
            pre[i + 1] = pre[i] + nums[i];
        }
        int mn = inf;
        for (int i = o; i <= n; i++) {
            ckmin(mn, o - (pre[i] - pre[i - o]));
        }
        return mn;
    }
};