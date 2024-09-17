/********************************************
 * author : Jie Chen (4th Year CS)
 * school : Rochester Institute of Technology
 * created: 06.17.2024 23:14:50
*********************************************/

using i64 = long long;

class Solution {
public:
    int xorAllNums(vector<int>& a, vector<int>& b) {
        int n = a.size(), m = b.size();

        int ans = 0;
        if (m & 1) {
            for (int x : a) {
                ans ^= x;
            }
        }
        if (n & 1) {
            for (int x : b) {
                ans ^= x;
            }
        }

        return ans;
    }
};

// ~ JustJie