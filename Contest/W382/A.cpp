/********************************************
 * author : Jie Chen (3rd Year CS)
 * school : Rochester Institute of Technology
 * created: 01.27.2024 21:30:17
*********************************************/

using i64 = long long;

class Solution {
public:
    int countKeyChanges(string s) {
        int n = s.length();

        int ans = 0;
        char p = tolower(s[0]);
        for (int i = 1; i < n; i++) {
            char u = tolower(s[i]);
            if (u != p) {
                ans++;
            }
            p = u;
        }
        return ans;
    }
};

// ~ JustJie