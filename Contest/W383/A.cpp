/********************************************
 * author : Jie Chen (3rd Year CS)
 * school : Rochester Institute of Technology
 * created: 02.03.2024 21:21:51
*********************************************/

using i64 = long long;

class Solution {
public:
    int returnToBoundaryCount(vector<int>& a) {
        int cur = 0, res = 0;
        for (int x : a) {
            cur += x;
            if (cur == 0) {
                res++;
            }
        }
        return res;
    }
};

// ~ JustJie