/********************************************
 * author : Jie Chen (4th Year CS)
 * school : Rochester Institute of Technology
 * created: 08.17.2024 00:58:27
*********************************************/

using i64 = long long;

class Solution {
public:
    int minIncrements(int n, vector<int>& a) {
        int ans = 0;

        const auto dfs = [&](auto&& self, int u) -> int {
            int cur = a[u - 1];
            if (2 * u > n) {
                return cur;
            } else {
                int l = self(self, 2 * u);
                int r = self(self, 2 * u + 1);
                ans += abs(l - r);
                return max(l, r) + cur;
            }
        };
        dfs(dfs, 1);

        return ans;
    }
};

// ~ JustJie