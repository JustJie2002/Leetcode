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

template<typename T_vector>
void output_vector(const T_vector &v, bool add_one = false, int start = -1, int end = -1) {
    if (start < 0) start = 0;
    if (end < 0) end = int(v.size());

    for (int i = start; i < end; i++) {
        cout << v[i] + (add_one ? 1 : 0) << " \n"[i == end - 1];
    }
}

template <typename T> bool ckmax(T &a, T b) { return a < b ? a = b, true : false; }
template <typename T> bool ckmin(T &a, T b) { return a > b ? a = b, true : false; }

class Solution {
private:
    vector<int> calc(string word, char a, char b) {
        int n = sz(word);
        cout << a << " " << b << "\n";
        // maximize a and minimize b
        vector<int> prefix(n + 1);
        // prefix[0] = -1;
        for (int i = 0; i < n; i++) {
            prefix[i + 1] = prefix[i];
            if (word[i] == a) prefix[i + 1]++;
            if (word[i] == b) prefix[i + 1]--;
        }
        output_vector(prefix);
        return prefix;
        // int best = 0;
        // vector<pii> s;
        // for (int i = 0; i < n; i++) {
            // if (word[i] != a && word[i] != b) continue;
            // ckmax(best, prefix[i + 1]);
            // for (const auto& pr : s) {
                // if (pr.se + 1 == i) continue;
                // ckmax(best, prefix[i + 1] - pr.fi);
            // }
            // s.emplace_back(prefix[i + 1], i);
            // sort(all(s));
            // s.resize(2);
        // }
        
    }

public:
    int largestVariance(string s) {
        vector<bool> exist(26, false);
        for (char& ch : s) exist[ch - 'a'] = true;
        int n = sz(s);
        int mx = 0;
        // O(26*26*N);
        for (char a = 'a'; a <= 'z'; a++) {
            if (!exist[a - 'a']) continue;
            vector<vector<int>> ps;
            for (char b = 'a'; b <= 'z'; b++) {
                if (!exist[b - 'a'] || a == b) continue;
                ps.pb(calc(s, a, b));
            }
        }
        return mx;
    }
};