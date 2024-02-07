/********************************************
 * author : Jie Chen (3rd Year CS)
 * school : Rochester Institute of Technology
 * created: 01.27.2024 21:37:18
*********************************************/

using i64 = long long;

class Solution {
public:
    i64 flowerGame(int n, int m) {
        // sum odd
        i64 ans = 0;
        {
            int ne = n / 2;
            int mo = (m + 1) / 2;
            ans += 1LL * ne * mo;
        }
        {
            int no = (n + 1) / 2;
            int me = m / 2;
            ans += 1LL * no * me;
        }

        return ans;
    }
};

// ~ JustJie