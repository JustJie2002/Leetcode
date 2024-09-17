/********************************************
 * author : Jie Chen (4th Year CS)
 * school : Rochester Institute of Technology
 * created: 09.06.2024 01:26:54
*********************************************/

using i64 = long long;

class Solution {
public:
    bool checkTwoChessboards(string coord1, string coord2) {
        bool res = (coord1[0] & 1) ^ (coord2[0] & 1) ^ (coord1[1] & 1) ^ (coord2[1] & 1);
        return !res;
    }
};

// ~ JustJie