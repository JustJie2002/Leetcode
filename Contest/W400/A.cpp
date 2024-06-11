/********************************************
 * author : Jie Chen (4th Year CS)
 * school : Rochester Institute of Technology
 * created: 06.02.2024 13:05:54
*********************************************/

using i64 = long long;

class Solution {
public:
    int minimumChairs(string s) {
        int ans = 0;
        int res = 0;
        for (auto c : s) {
            if (c == 'E') {
                res++;
            } else {
                res--;
            }
            ans = max(ans, res);
        }
        return ans;
    }
};

// ~ JustJie