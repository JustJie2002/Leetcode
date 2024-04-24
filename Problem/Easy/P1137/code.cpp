/********************************************
 * author : Jie Chen (3rd Year CS)
 * school : Rochester Institute of Technology
 * created: 04.23.2024 20:34:08
*********************************************/

using i64 = long long;

constexpr int N = 38;
int dp[N];

void Init() {
    dp[0] = 0;
    dp[1] = dp[2] = 1;
    for (int i = 3; i < N; i++) {
        dp[i] = 0;
        for (int j = 1; j <= 3; j++) {
            dp[i] += dp[i - j];
        }
    }
}

class Solution {
public:
    Solution() {
        Init();
    }

    int tribonacci(int n) {
        return dp[n];
    }
};

// ~ JustJie