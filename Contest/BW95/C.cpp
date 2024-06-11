/********************************************
 * author : Jie Chen (4th Year CS)
 * school : Rochester Institute of Technology
 * created: 05.31.2024 23:24:51
*********************************************/

using i64 = long long;

constexpr int B = 31;

class Solution {
public:
    int xorBeauty(vector<int>& a) {
        int ans = 0;
        for (int x : a) {
            ans ^= x;
        }
        return ans;
    }
};

// ~ JustJie