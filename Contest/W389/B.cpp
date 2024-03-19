/********************************************
 * author : Jie Chen (3rd Year CS)
 * school : Rochester Institute of Technology
 * created: 03.16.2024 22:31:31
*********************************************/

using i64 = long long;

class Solution {
public:
    long long countSubstrings(string s, char c) {
        i64 ans = 0;

        int seen = 0;
        for (char x : s) {
            if (x == c) {
                seen++;
                ans += seen;
            }
        }

        return ans;
    }
};

// ~ JustJie