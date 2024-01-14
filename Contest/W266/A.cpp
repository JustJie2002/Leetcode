/********************************************
 * author : Jie Chen (3rd Year CS)
 * school : Rochester Institute of Technology
 * created: 01.10.2024 23:13:41
*********************************************/

using i64 = long long;

const string VOWELS = "aeiou";

constexpr int ord(char c) { return c - 'a'; }

class Solution {
public:
    int countVowelSubstrings(string s) {
        int n = s.size();

        int good_mask = 0;
        for (char c : VOWELS) {
            good_mask |= (1 << ord(c));
        }

        int ans = 0;
        for (int i = 0; i < n; i++) {
            for (int j = i; j < n; j++) {
                int cur_mask = 0;
                for (int k = i; k <= j; k++) {
                    cur_mask |= (1 << ord(s[k]));
                }
                ans += int(cur_mask == good_mask);
            }
        }

        return ans;
    }
};

// ~ JustJie