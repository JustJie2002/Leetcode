/********************************************
 * author : Jie Chen (3rd Year CS)
 * school : Rochester Institute of Technology
 * created: 03.21.2024 00:00:44
*********************************************/

using i64 = long long;

int gcd(int a, int b) {
    return b == 0 ? a : gcd(b, a % b);
}

class Solution {
public:
    int minimizeSet(int div1, int div2, int uc1, int uc2) {
        int l = div1 / gcd(div1, div2) * div2;

        // that means 
    }
};

// ~ JustJie