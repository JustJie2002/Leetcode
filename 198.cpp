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
    vector<int> a, memo;
    int n;

    int go(int i) {
        if (i >= n) return 0;
        if (memo[i] != -1) return memo[i];
        int mx = a[i];
        ckmax(mx, go(i + 1));
        for (int nex = i + 2; nex < n; nex++) {
            ckmax(mx, a[i] + go(nex));
        }
        return memo[i] = mx;
    }

public:
    int rob(vector<int>& nums) {
        a = nums;
        n = sz(nums);
        memo.resize(n, -1);
        return go(0);
    }
};