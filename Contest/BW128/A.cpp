/********************************************
 * author : Jie Chen (3rd Year CS)
 * school : Rochester Institute of Technology
 * created: 04.13.2024 11:47:32
*********************************************/

using i64 = long long;

class Solution {
public:
    int scoreOfString(string s) {
        int n = s.length();

        int ans = 0;
        for (int i = 0; i < n - 1; i++) {
            ans += abs(s[i] - s[i + 1]);
        }
        return ans;
    }
};

// ~ JustJie