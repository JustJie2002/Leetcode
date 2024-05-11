/********************************************
 * author : Jie Chen (3rd Year CS)
 * school : Rochester Institute of Technology
 * created: 05.07.2024 20:11:03
*********************************************/

using i64 = long long;

class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& a) {
        int n = a.size();

        vector<int> ord(n);
        iota(ord.begin(), ord.end(), 0);
        sort(ord.begin(), ord.end(), 
            [&](int i, int j) {
                return a[i] > a[j];
            });

        vector<string> ans(n);
        for (int p = 1; p <= n; p++) {
            int i = ord[p - 1];
            if (p == 1) {
                ans[i] = "Gold Medal";
            } else if (p == 2) {
                ans[i] = "Silver Medal";
            } else if (p == 3) {
                ans[i] = "Bronze Medal";
            } else {
                ans[i] = to_string(p);
            }
        }
        return ans;
    }
};

// ~ JustJie