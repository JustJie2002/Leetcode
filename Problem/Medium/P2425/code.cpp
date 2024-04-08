/********************************************
 * author : Jie Chen (3rd Year CS)
 * school : Rochester Institute of Technology
 * created: 03.27.2024 02:38:39
*********************************************/

using i64 = long long;

class Solution {
public:
    int xorAllNums(vector<int>& a, vector<int>& b) {
        int n = a.size(), m = b.size();
        int ans = 0;
        if (m % 2 == 1) {
            for (int x : a) {
                ans ^= x;
            }
        }
        if (n % 2 == 1) {
            for (int x : b) {
                ans ^= x;
            }
        }
        return ans;
    }
};

// ~ JustJie