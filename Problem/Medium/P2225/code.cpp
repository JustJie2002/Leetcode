/********************************************
 * author : Jie Chen (3rd Year CS)
 * school : Rochester Institute of Technology
 * created: 05.25.2024 16:58:47
*********************************************/

using i64 = long long;

class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& aa) {
        unordered_map<int, int> losses;
        for (const auto& a : aa) {
            losses[a[0]];
            losses[a[1]]++;
        }

        vector<vector<int>> ans(2);
        for (const auto& [k, v] : losses) {
            if (v <= 1) {
                ans[v].push_back(k);
            }
        }
        for (auto& a : ans) {
            sort(a.begin(), a.end());
        }
        return ans;
    }
};

// ~ JustJie