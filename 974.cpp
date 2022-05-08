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
    int mod_add(int x, int p) {
        while (x < 0) x += p;
        return x % p;
    }

    int subarraysDivByK(vector<int>& a, int p) {
        int n = sz(a);
        vector<int> prefix(n + 1);
        unordered_map<int, int> c;
        for (int i = 0; i < n; i++) 
            prefix[i + 1] = mod_add(prefix[i] + a[i], p);
        int ret = 0;
        for (int i = 0; i < n; i++) {
            int sum = prefix[i + 1];
            if (sum == 0)
                ret++;
            ret += c[sum];
            c[sum]++;
        }
        return ret;
    }
};