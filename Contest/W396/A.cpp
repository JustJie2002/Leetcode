/********************************************
 * author : Jie Chen (3rd Year CS)
 * school : Rochester Institute of Technology
 * created: 05.04.2024 22:43:26
*********************************************/

using i64 = long long;

class Solution {
public:
    bool isValid(string s) {
        int n = s.length();
        if (n < 3) {
            return false;
        }

        bool has_vowel = false;
        bool has_consonant = false;
        for (char c : s) {
            if (isalnum(c)) {
                c = tolower(c);
                if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') {
                    has_vowel = true;
                } else if (isalpha(c)) {
                    has_consonant = true;
                }
            } else {
                return false;
            }
        }
        return has_consonant && has_vowel;
    }
};

// ~ JustJie