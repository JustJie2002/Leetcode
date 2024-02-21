/********************************************
 * author : Jie Chen (3rd Year CS)
 * school : Rochester Institute of Technology
 * created: 02.12.2024 16:30:11
*********************************************/

using i64 = long long;

constexpr int INF = int(1e9) + 5;

class Solution {
public:
    int minSessions(vector<int>& tasks, int t) {
        int n = tasks.size();

        const int M = 1 << n;

        vector dp(n + 1, vector<int>(M, INF));
        dp[0][0] = 0;
        for (int i = 0; i < n; i++) { // O(N)
            for (int m = 0; m < M; m++) {
                int rem_mask = M ^ m;
                for (int sub_mask = rem_mask; sub_mask; sub_mask = (sub_mask - 1) & rem_mask) { // O(3^N)
                    for (int j = 0; j < n; j++) { // O(N)

                    }
                }
            }
        }

        // O(N^2 * 3^N)

        return hi;
    }
};

// ~ JustJie