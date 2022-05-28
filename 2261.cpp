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

constexpr int MOD = 1E9 + 7;

class Solution {
private:
    int calc(vector<int>& a, int n, int k, int p) {
        unordered_set<i64> seen;
        int c = 0;
        i64 base = 201;
        i64 power = 1;
        i64 hash = 0;
        for (int i = 0; i < n; i++) {
            power = (power * base) % MOD;
        }
        for (int i = 0; i < n; i++) {
            hash = (hash * base) % MOD;
            hash = (hash + a[i]) % MOD;
            if (a[i] % p == 0) c++;
            if (i >= n) {
                hash -= power * a[i - n];
                if (a[i - n] % p == 0) c++;
            }
            if (i >= n - 1 && c <= k) seen.ins(hash);
        }
        return sz(seen);
    }

public:
    int countDistinct(vector<int>& nums, int k, int p) {
        int n = sz(nums);
        int ans = 0;
        for (int i = 1; i <= n; i++) {
            ans += calc(nums, i, k, p);
        }
        return ans;
    }
};