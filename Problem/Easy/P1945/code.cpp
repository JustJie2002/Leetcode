/********************************************
 * author : Jie Chen (3rd Year CS)
 * school : Rochester Institute of Technology
 * created: 04.15.2024 22:27:19
*********************************************/

using i64 = long long;

class Solution {
public:
    int getLucky(string s, int k) {
        int res = 0;
        for (char c : s) {
            int o = c - 'a' + 1;
            while (o) {
                res += o % 10;
                o /= 10;
            }
        }
        for (int op = 1; op < k; op++) {
            int new_res = 0;
            while (res) {
                new_res += res % 10;
                res /= 10;
            }
            swap(new_res, res);
        }
        return res;
    }
};

// ~ JustJie