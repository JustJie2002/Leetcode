/********************************************
 * author : Jie Chen (4th Year CS)
 * school : Rochester Institute of Technology
 * created: 07.28.2024 00:57:32
*********************************************/

using i64 = long long;

class Solution {
public:
    bool canAliceWin(vector<int>& a) {
        int v = 0;
        for (int x : a) {
            if (x < 10) {
                v += x;
            } else {
                v -= x;
            }
        }
        return v != 0;
    }
};

// ~ JustJie