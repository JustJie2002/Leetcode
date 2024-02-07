/********************************************
 * author : Jie Chen (3rd Year CS)
 * school : Rochester Institute of Technology
 * created: 02.04.2024 20:46:33
*********************************************/

using i64 = long long;

class Solution {
public:
    int minBitFlips(int start, int goal) {
        int res = 0;
        for (int i = 0; i < 31; i++) {
            int a = start >> i & 1;
            int b = goal >> i & 1;
            if (a != b) {
                res++;
            }
        }
        return res;
    }
};

// ~ JustJie