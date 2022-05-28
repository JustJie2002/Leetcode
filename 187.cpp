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
public:
    vector<string> findRepeatedDnaSequences(string s) {
        int n = sz(s);
        if (n < 10) return vector<string>();
        unordered_set<i64> seen;
        unordered_set<string> ss;
        i64 hash = 0LL;
        i64 base = 27LL;
        vector<i64> pow(10);
        pow[0] = 1;
        for (int i = 1; i < 10; i++) {
            pow[i] = (pow[i - 1] * base);
        }
        for (int i = 0; i < 10; i++) {
            hash = (hash + (s[i] - 'A' + 1) * pow[i]);
        }
        seen.ins(hash);
        for (int i = 10; i < n; i++) {
            hash = (hash - (i64) (s[i - 10] - 'A' + 1) * pow[0]);
            hash /= base;
            hash = (hash + (i64) (s[i] - 'A' + 1) * pow[9]);
            if (seen.count(hash)) {
                ss.ins(s.substr(i - 9, 10));
            } else {
                seen.ins(hash);
            }
        }
        return vector<string>(all(ss));
    }
};