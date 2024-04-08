/********************************************
 * author : Jie Chen (3rd Year CS)
 * school : Rochester Institute of Technology
 * created: 03.31.2024 21:42:22
*********************************************/

using i64 = long long;

class Solution {
public:
    int lengthOfLastWord(string s) {
        int cnt = 0;
        int ans = 0;
        for (char c : s) {
            if (isspace(c)) {
                cnt = 0;
            } else {
                cnt++;
                ans = cnt;
            }
        }

        return ans;
    }
};

// ~ JustJie