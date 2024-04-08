/********************************************
 * author : Jie Chen (3rd Year CS)
 * school : Rochester Institute of Technology
 * created: 03.30.2024 22:38:44
*********************************************/

using i64 = long long;

class Solution {
public:
    int sum(int x) {
        int res = 0;
        while (x) {
            res += (x % 10);
            x /= 10;
        }
        return res;
    }

    int sumOfTheDigitsOfHarshadNumber(int x) {
        int s = sum(x);
        return (x % s == 0 ? s : -1);
    }
};

// ~ JustJie