/********************************************
 * author : Jie Chen (3rd Year CS)
 * school : Rochester Institute of Technology
 * created: 05.04.2024 22:41:29
*********************************************/

using i64 = long long;

class Solution {
public:
    int minimumOperationsToMakeKPeriodic(string s, int k) {
        int n = s.length();

        unordered_map<string, int> occs;
        for (int i = 0; i < n; i += k) {
            occs[s.substr(i, k)]++;
        }

        int tot = n / k;
        int ans = tot;
        for (const auto& [_, f] : occs) {
            ans = min(ans, tot - f);
        }
        return ans;
    }
};

// ~ JustJie