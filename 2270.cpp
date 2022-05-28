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
    int waysToSplitArray(vector<int>& nums) {
        int n = sz(nums);
        vector<i64> prefix(n + 1);
        for (int i = 0; i < n; i++) {
            prefix[i + 1] = (i64) prefix[i] + nums[i];
        }
        int ans = 0;
        for (int i = 0; i < n - 1; i++) {
            if (prefix[i + 1] >= prefix[n] - prefix[i + 1]) ans++;
        }
        return ans;
    }
};