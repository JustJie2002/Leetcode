/********************************************
 * author : Jie Chen (3rd Year CS)
 * school : Rochester Institute of Technology
 * created: 03.24.2024 03:36:31
*********************************************/

using i64 = long long;

constexpr int inf = 1e9 + 5;

class Solution {
public:
    int minOperations(int k) {
        int ans = inf;
        for (int mx = 1; mx <= k; mx++) {
            int op1 = mx - 1;
            int op2 = (k + mx - 1) / mx - 1;
            ans = min(ans, op1 + op2);
        }
        return ans;
    }
};

// ~ JustJie