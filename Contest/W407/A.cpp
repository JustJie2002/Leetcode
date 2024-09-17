/********************************************
 * author : Jie Chen (4th Year CS)
 * school : Rochester Institute of Technology
 * created: 07.21.2024 17:52:00
*********************************************/

using i64 = long long;

class Solution {
public:
    int minChanges(int n, int k) {
        int x = n ^ k;
        int ans = 0;
        for (int b = 0; b < 30; b++) {
            if (x & (1 << b)) {
                if (k & (1 << b)) {
                    return -1;
                }
                ans++;
            }
        }
        return ans;
    }
};

// ~ JustJie