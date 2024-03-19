/********************************************
 * author : Jie Chen (3rd Year CS)
 * school : Rochester Institute of Technology
 * created: 03.06.2024 22:31:14
*********************************************/

using i64 = long long;
using Pair = pair<int, int>;

#define f   first
#define s   second

constexpr int di[] = {0, 1, 0, -1};
constexpr int dj[] = {1, 0, -1, 0};

class Solution {
public:
    int longestIncreasingPath(vector<vector<int>>& mat) {
        int n = mat.size(), m = mat[0].size();

        vector<Pair> ord;
        ord.reserve(n * m);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                ord.emplace_back(i, j);
            }
        }

        sort(ord.begin(), ord.end(), [&](auto&& a, auto&& b) {
            return mat[a.f][a.s] > mat[b.f][b.s];
        });

        vector dp(n, vector<int>(m, 1));
        int ans = 1;
        for (auto& [i, j] : ord) {
            int longest = 0;
            for (int d = 0; d < 4; d++) {
                int neighbor_i = i + di[d];
                int neighbor_j = j + dj[d];
                if (neighbor_i < 0 || neighbor_i >= n) {
                    continue;
                }
                if (neighbor_j < 0 || neighbor_j >= m) {
                    continue;
                }
                if (mat[neighbor_i][neighbor_j] > mat[i][j]) {
                    longest = max(longest, dp[neighbor_i][neighbor_j]);
                }
            }
            dp[i][j] = 1 + longest;
            ans = max(ans, dp[i][j]);
        }

        return ans;
    }
};

// ~ JustJie