/********************************************
 * author : Jie Chen (3rd Year CS)
 * school : Rochester Institute of Technology
 * created: 05.25.2024 16:43:27
*********************************************/

using i64 = long long;

vector<string> split(string s) {
    s += " ";
    vector<string> words;
    string t;
    for (auto c : s) {
        if (isspace(c)) {
            words.push_back(t);
            t.clear();
        } else {
            t += c;
        }
    }
    return words;
}

int ord(char c) {
    return c - 'a';
}

class Solution {
public:
    int canBeTypedWords(string text, string brokenLetters) {
        int bad_mask = 0;
        for (auto c : brokenLetters) {
            bad_mask |= (1 << ord(c));
        }

        const auto& words = split(text);
        int ans = 0;
        for (const auto& word : words) {
            int cur_mask = 0;
            for (auto c : word) {
                cur_mask |= (1 << ord(c));
            }
            ans += int((cur_mask & bad_mask) == 0);
        }
        return ans;
    }
};

// ~ JustJie