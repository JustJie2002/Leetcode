/********************************************
 * author : Jie Chen (3rd Year CS)
 * school : Rochester Institute of Technology
 * created: 03.09.2024 20:32:16
*********************************************/

using i64 = long long;

constexpr int inf = 1e9 + 5;

class Solution {
public:
    int minimumCost(vector<int>& a) {
        int n = a.size();

        int ans = inf;
        for (int i = 1; i < n - 1; i++) {
            for (int j = i + 1; j < n; j++) {
                ans = min(ans, a[0] + a[i] + a[j]);
            }
        }

        return ans;
    }
};

// ~ JustJie