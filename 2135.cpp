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
private:
    int ord(char ch) { return ch - 'a'; }

    int get_mask(const string &word) {
        int mask = 0;
        for (char ch : word) mask |= 1 << ord(ch);
        return mask;
    }

public:
    int wordCount(vector<string>& startWords, vector<string>& targetWords) {
        multiset<int> m;
        for (const auto& word : targetWords) m.ins(get_mask(word));
        for (const auto& word : startWords) {
            int mask = get_mask(word);
            for (int i = 0; i < 26; i++) {
                if (mask >> i & 1) continue;
                int nmask = mask | (1 << i);
                if (m.count(nmask)) m.erase(nmask);
            }
        }
        return sz(targetWords) - sz(m);
    }
};