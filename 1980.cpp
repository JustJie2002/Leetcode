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
    string bin(int x) {
        string sb;
        do {
            sb += '0' + (x & 1);
            x >>= 1;
        } while (x);
        return sb;
    }
public:
    string findDifferentBinaryString(vector<string>& nums) {
        unordered_set<string> seen(all(nums));
        int n = sz(nums);
        for (int i = (1 << (n - 1)) - (n == 1 ? 1 : 0); i < (1 << n); i++) {
            string sb = bin(i);
            if (seen.count(sb))
                continue;
            return sb;
        }
        assert(false);
    }
};