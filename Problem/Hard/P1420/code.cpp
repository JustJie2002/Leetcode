/********************************************
 * author : Jie Chen (3rd Year CS)
 * school : Rochester Institute of Technology
 * created: 02.24.2024 14:56:05
*********************************************/

using i64 = long long;

// Insert MInt.cpp
 
constexpr int P = 1'000'000'007; // 998'244'353;
using Z = MInt<P>;

constexpr int N = 51, M = 101;

Z dp[N][M][N];

class Solution {
public:
    int numOfArrays(int n, int m, int k) {
        memset(dp, 0, sizeof(dp));

        for (int e = 1; e <= m; e++) {
            dp[1][e][1] = 1;
        }

        for (int i = 2; i <= n; i++) {
            for (int e = 1; e <= m; e++) {
                for (int s = 1; s <= k; s++) {
                    dp[i][e][s] += e * dp[i - 1][e][s];
                    for (int x = 1; x < e; x++) {
                        dp[i][e][s] += dp[i - 1][x][s - 1];
                    }
                }
            }
        }

        Z ans = 0;
        for (int e = 1; e <= m; e++) {
            ans += dp[n][e][k];
        }
        return ans.val();
    }
};

// ~ JustJie