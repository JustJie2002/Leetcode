/********************************************
 * author : Jie Chen (3rd Year CS)
 * school : Rochester Institute of Technology
 * created: 04.20.2024 22:38:54
*********************************************/

using i64 = long long;

class Solution {
public:
    int numberOfSpecialChars(string s) {
        int n = s.length();

        array<int, 26> occs {};
        for (char c : s) {
            if (isupper(c)) {
                occs[c - 'A'] |= 2;
            } else {
                occs[c - 'a'] |= 1;
            }
        }

        int ans = 0;
        for (int i = 0; i < 26; i++) {
            ans += int(occs[i] == 3);
        }
        return ans;
    }
};

// ~ JustJie