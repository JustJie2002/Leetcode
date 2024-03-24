/********************************************
 * author : Jie Chen (3rd Year CS)
 * school : Rochester Institute of Technology
 * created: 03.23.2024 22:46:18
*********************************************/

using i64 = long long;

constexpr int inf = 1e9 + 5;

class Solution {
public:
    int minOperations(int k) {
        // 1 -> [2] -> [2, 2]
        // 1 -> [1, 1] -> [1, 2]
        int ans = inf;
        // for (int i = 1; i <= k; i++) {
        //     int op = i - 1;
        //     int cnt = (k + i - 1) / i - 1;
        //     ans = min(ans, cnt + op);
        // }
        // return ans;
        for (int i = 1; i * i <= k; i++) {
            if (k % i == 0) {
                int j = k / i;
                ans = min(ans, i - 1 + j - 1);
            }
        }
        return ans;
    }
};

// ~ JustJie