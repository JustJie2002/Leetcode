/********************************************
 * author : Jie Chen (3rd Year CS)
 * school : Rochester Institute of Technology
 * created: 04.04.2024 01:58:11
*********************************************/

using i64 = long long;

class Solution {
public:
    int maxDepth(string s) {
        int open = 0;
        int ans = 0;
        for (char c : s) {
            if (c == '(') {
                open++;
            } else if (c == ')') {
                open--;
            }
            ans = max(ans, open);
        }
        return ans;
    }
};

// ~ JustJie