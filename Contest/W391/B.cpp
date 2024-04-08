/********************************************
 * author : Jie Chen (3rd Year CS)
 * school : Rochester Institute of Technology
 * created: 03.30.2024 22:33:40
*********************************************/

using i64 = long long;

class Solution {
public:
    int maxBottlesDrunk(int a, int b) {
        int ans = 0;
        int e = 0;
        while (a > 0) {
            ans += a;
            e += a;
            a = 0;
            if (e >= b) {
                a = 1;
                e -= b;
                b++;
            }
        }
        return ans;
    }
};

// ~ JustJie