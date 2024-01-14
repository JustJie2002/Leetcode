/********************************************
 * author : Jie Chen (3rd Year CS)
 * school : Rochester Institute of Technology
 * created: 01.10.2024 23:16:02
*********************************************/

using i64 = long long;

const string VOWELS = "aeiou";

bool good(char c) {
    return VOWELS.find(c) != string::npos;
}

class Solution {
public:
    long long countVowels(string s) {
        int n = s.length();

        i64 ans = 0;
        for (int i = 0; i < n; i++) {
            if (good(s[i])) {
                int L = i + 1;
                int R = n - i;
                ans += 1LL * L * R;
            }
        }

        return ans;
    }
};

// ~ JustJie