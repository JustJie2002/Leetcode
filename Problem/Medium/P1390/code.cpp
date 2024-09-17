/********************************************
 * author : Jie Chen (4th Year CS)
 * school : Rochester Institute of Technology
 * created: 06.15.2024 20:25:03
*********************************************/

using i64 = long long;

class Solution {
public:
    int sumFourDivisors(vector<int>& a) {
        int ans = 0;
        for (int x : a) {
            int d = 0;
            int res = 0;
            for (int i = 1; i * i <= x; i++) {
                if (x % i == 0) {
                    res += i;
                    d++;
                    if (i * i != x) {
                        d++;
                        res += x / i;
                    }
                    if (d > 4) {
                        break;
                    }
                }
            }
            if (d == 4) {
                ans += res;
            }
        }
        return ans;
    }
};

// ~ JustJie