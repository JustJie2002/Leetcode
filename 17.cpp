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
    vector<string> letterCombinations(string digits) {
        if (digits == "") return vector<string>();
        vector<string> convert{"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        unordered_set<string> s;
        s.insert("");
        for (char ch : digits) {
            unordered_set<string> t;
            for (auto str : s)
                for (char c : convert[ch - '0'])
                    t.insert(str + c);
            s.swap(t);
        }
        return vector<string>(all(s));
    }
};