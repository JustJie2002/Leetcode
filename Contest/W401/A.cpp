/********************************************
 * author : Jie Chen (4th Year CS)
 * school : Rochester Institute of Technology
 * created: 06.08.2024 22:39:12
*********************************************/

using i64 = long long;

class Solution {
public:
    int numberOfChild(int n, int k) {
        vector<int> a(n);
        int i = 0;
        bool good = true;
        while (k--) {
            if (good) {
                i++;
            } else {
                i--;
            }
            if (i == n - 1) {
                good = false;
            } else if (i == 0) {
                good = true;
            }
        }
        return i;
    }
};

// ~ JustJie