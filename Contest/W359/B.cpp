/********************************************
 * author : Jie Chen (3rd Year CS)
 * school : Rochester Institute of Technology
 * created: 03.08.2024 00:57:56
*********************************************/

using i64 = long long;

class Solution {
public:
    int minimumSum(int n, int k) {
        int sum = 0;
        for (int i = 1; i <= k / 2 && n; i++, n--) {
            sum += i;
        }
        for (int i = k; n; i++, n--) {
            sum += i;
        }
        return sum;
    }
};

// ~ JustJie