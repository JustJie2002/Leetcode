/********************************************
 * author : Jie Chen (3rd Year CS)
 * school : Rochester Institute of Technology
 * created: 12.14.2023 02:11:15
*********************************************/

using i64 = long long;

class Solution {
public:
    int countTestedDevices(vector<int>& a) {
        int res = 0;
        for (int x : a) if (x - res > 0) {
            res++;
        }
        return res;
    }
};

// ~ JustJie