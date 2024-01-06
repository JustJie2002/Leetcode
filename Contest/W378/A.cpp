/********************************************
 * author : Jie Chen (3rd Year CS)
 * school : Rochester Institute of Technology
 * created: 12.30.2023 20:36:24
*********************************************/

using i64 = long long;

class Solution {
public:
    bool hasTrailingZeros(vector<int>& a) {
        int res = 0;
        for (int x : a) {
            if (x % 2 == 0) {
                res++;
            }
        }

        return res >= 2;
    }
};

// ~ JustJie