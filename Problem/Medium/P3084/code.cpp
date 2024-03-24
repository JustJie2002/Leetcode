/********************************************
 * author : Jie Chen (3rd Year CS)
 * school : Rochester Institute of Technology
 * created: 03.19.2024 03:47:28
*********************************************/

using i64 = long long;

class Solution {
public:
    i64 countSubstrings(string s, char c) {
        int cnt = 0;
        for (char x : s) {
            cnt += int(x == c);
        }
        return 1LL * cnt * (cnt + 1) / 2;
    }
};

// ~ JustJie