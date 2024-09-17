/********************************************
 * author : Jie Chen (4th Year CS)
 * school : Rochester Institute of Technology
 * created: 07.13.2024 22:27:21
*********************************************/

using i64 = long long;

class Solution {
public:
    i64 minimumCost(int n, int m, vector<int>& a, vector<int>& b) {
        vector<array<int, 2>> res;
        for (int i = 0; i < n - 1; i++) {
            res.push_back({a[i], 0});
        }
        for (int i = 0; i < m - 1; i++) {
            res.push_back({b[i], 1});
        }

        sort(res.rbegin(), res.rend());
        int par[2] {1, 1};
        i64 ans = 0;
        for (const auto &[x, p] : res) {
            ans += 1LL * x * par[p ^ 1];
            par[p]++;
        }
        return ans;
    }
};

// ~ JustJie