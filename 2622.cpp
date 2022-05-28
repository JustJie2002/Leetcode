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
    long long appealSum(string s) {
        int n = sz(s);
        i64 sum = 0;
        array<int, 26> c = {};
        for (int i = 0; i < n; i++) {
            c[s[i] - 'a'] = i + 1;
            for (int j = 0; j < 26; j++) {
                sum += (i64) c[j];
            }
        }
        return sum;
    }
};