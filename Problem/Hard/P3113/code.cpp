/********************************************
 * author : Jie Chen (3rd Year CS)
 * school : Rochester Institute of Technology
 * created: 04.13.2024 17:23:28
*********************************************/

using i64 = long long;
using Info = array<int, 2>;

class Solution {
public:
    i64 numberOfSubarrays(vector<int>& a) {
        stack<Info> stk;
        i64 ans = 0;
        for (int x : a) {
            while (!stk.empty() && stk.top()[0] < x) {
                stk.pop();
            }

            if (!stk.empty() && stk.top()[0] == x) {
                stk.top()[1]++;
            } else {
                stk.push({x, 1});
            }
            ans += stk.top()[1];
        }
        return ans;
    }
};

// ~ JustJie