/********************************************
 * author : Jie Chen (3rd Year CS)
 * school : Rochester Institute of Technology
 * created: 01.06.2024 17:55:01
*********************************************/

using i64 = long long;

class Solution {
public:
    int minimumAddedCoins(vector<int>& a, int t) {
        sort(a.begin(), a.end());

        int res = 0;
        i64 mex = 1;
        for (int x : a) {
            while (mex < x) {
                mex *= 2LL;
                res++;
            }
            mex += x;
        }

        while (mex <= t) {
            mex *= 2LL;
            res++;
        }

        return res;
    }
};

// ~ JustJie