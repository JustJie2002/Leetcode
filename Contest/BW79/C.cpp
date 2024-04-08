/********************************************
 * author : Jie Chen (3rd Year CS)
 * school : Rochester Institute of Technology
 * created: 04.02.2024 22:31:32
*********************************************/

using i64 = long long;

class Solution {
public:
    long long maximumImportance(int n, vector<vector<int>>& roads) {
        vector<int> used(n);
        for (const auto& road : roads) {
            int u = road[0], v = road[1];
            used[u]++;
            used[v]++;
        }

        sort(used.begin(), used.end());

        i64 ans = 0;
        for (int i = 1; i <= n; i++) {
            ans += 1LL * i * used[i - 1];
        }
        return ans;
    }
};

// ~ JustJie