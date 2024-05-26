/********************************************
 * author : Jie Chen (3rd Year CS)
 * school : Rochester Institute of Technology
 * created: 05.11.2024 23:07:26
*********************************************/

using i64 = long long;

constexpr int inf = 1e9 + 5;

class Solution {
public:
    int maximumEnergy(vector<int>& e, int k) {
        int n = e.size();
        vector<int> res(k);
        int ans = -inf;
        for (int i = n - 1; i >= 0; i--) {
            res[i % k] += e[i];
            ans = max(ans, res[i % k]);
        }
        return ans;
    }
};

// ~ JustJie