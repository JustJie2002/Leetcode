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

constexpr int INF = 1E9;

class Solution {
private:
    array<int, 26> m;

public:
    int maxScoreWords(vector<string>& words, vector<char>& letters, vector<int>& score) {
        for (char& ch : letters) m[ch - 'a']++;
        int n = sz(words);
        int mx = 0;
        for (int mask = 0; mask < (1 << n); mask++) {
            bool ok = true;
            array<int, 26> c = {};
            int tot = 0;
            for (int i = 0; i < n && ok; i++) {
                if (mask >> i & 1) {
                    for (char& ch : words[i]) {
                        int idx = ch - 'a';
                        if (++c[idx] > m[idx]) {
                            ok = false;
                            break;
                        }
                        tot += score[idx];
                    }
                }
            }
            if (ok) ckmax(mx, tot);
        }
        return mx;
    }
};