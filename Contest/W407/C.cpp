/********************************************
 * author : Jie Chen (4th Year CS)
 * school : Rochester Institute of Technology
 * created: 07.21.2024 17:54:54
*********************************************/

using i64 = long long;

class Solution {
public:
    int maxOperations(string s) {
        int o = 0;
        int ans = 0;
        char p = '1';
        for (char c : s) {
            if (c == '1') {
                if (p != '1') {
                    ans += o;
                }
                o++;
            }
            p = c;
        }
        if (p == '0') {
            ans += o;
        }
        return ans;
    }
};

// ~ JustJie