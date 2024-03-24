/********************************************
 * author : Jie Chen (3rd Year CS)
 * school : Rochester Institute of Technology
 * created: 03.20.2024 22:08:10
*********************************************/

using i64 = long long;

class Solution {
public:
    int deleteGreatestValue(vector<vector<int>>& aa) {
        int n = aa.size(), m = aa[0].size();

        vector<int> ma(m);
        for (auto& a : aa) {
            sort(a.begin(), a.end());
            for (int j = 0; j < m; j++) {
                ma[j] = max(ma[j], a[j]);
            }
        }

        return accumulate(ma.begin(), ma.end(), 0);
    }
};

// ~ JustJie