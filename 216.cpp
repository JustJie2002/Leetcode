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
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        if (k == 0 || n < 0) return vector<vector<int>>();
        vector<vector<int>> w;
        for (int mask = 0; mask < (1 << 9); mask++) {
            if (__builtin_popcount(mask) == k) {
                int sum = 0;
                vector<int> v;
                for (int i = 0; i < 9; i++) {
                    if (mask >> i & 1) {
                        sum += (i + 1);
                        v.pb(i + 1);
                    }
                }
                if (sum == n) w.pb(v);
            }
        }
        return w;
    }
};