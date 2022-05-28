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
    unordered_map<char, int> want;
    bool comp(unordered_map<char, int>& a) {
        for (const auto& [x, c] : want) {
            if (c > a[x]) return false;
        }
        return true;
    }

public:
    string minWindow(string s, string t) {
        for (char ch : t) ++want[ch];
        unordered_map<char, int> c;
        int n = sz(s);
        int mn = INF, idx = -1;
        for (int i = 0, j = 0; i < n; i++) {
            while (j < n && !comp(c)) ++c[s[j]], j++;
            // cout << i << " " << j << " " << s.substr(i, j - i + 1) << "\n";
            if (comp(c)) {
                if (ckmin(mn, j - i)) idx = i;
            } else break;
            --c[s[i]];
        }
        return idx == -1 ? "" : s.substr(idx, mn);
    }
};