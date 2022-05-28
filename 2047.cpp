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

vector<string> split(const string &word) {
    vector<string> words;
    string sb;
    for (char ch : word) {
        if (isspace(ch)) {
            if (sb != "") words.pb(sb);
            sb.clear();
        } else {
            sb += ch;
        }
    }
    if (sb != "") words.pb(sb);
    return words;
}

class Solution {
private:
    const string punc = "!.,";
    
    bool isalpha(char ch) {
        int alpha = ch - 'a';
        return alpha >= 0 && alpha < 26;
    }
    
    bool validify(const string& word) {
        int m = sz(word);
        bool hypseen = false;
        for (int i = 0; i < m; i++) {
            char ch = word[i];
            int alpha = ch - 'a';
            if (ch == '-') {
                // can have hyphen but at most one
                if (hypseen) return false;
                if (i == 0 || i == m - 1) return false;
                if (!isalpha(word[i - 1]) || !isalpha(word[i + 1])) return false;
                hypseen = true;
            } else if (isalpha(ch)) {
            } else if (punc.find(ch) != string::npos) {
                // punctuation at the end
                if (i != m - 1) return false;
            } else return false;
        }
        return true;
    }
    
public:
    int countValidWords(string sentence) {
        vector<string> words = split(sentence);
        int ans = 0;
        for (const auto& word : words) {
            if (validify(word)) ++ans;
        }
        return ans;
    }
};