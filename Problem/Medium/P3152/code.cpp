/********************************************
 * author : Jie Chen (3rd Year CS)
 * school : Rochester Institute of Technology
 * created: 05.19.2024 13:13:15
*********************************************/

using i64 = long long;

class Solution {
public:
    vector<bool> isArraySpecial(vector<int>& a, vector<vector<int>>& queries) {
        int n = a.size();

        vector<int> breaks;
        for (int i = 0; i < n - 1; i++) {
            if ((a[i] % 2) == (a[i + 1] % 2)) {
                breaks.push_back(i);
            }
        }

        int qs = queries.size();
        vector<bool> ans;
        ans.reserve(qs);
        for (const auto& q : queries) {
            int l = q[0], r = q[1];
            auto it = lower_bound(breaks.begin(), breaks.end(), l);
            bool connected = true;
            if (it != breaks.end()) {
                connected = (*it + 1 > r);
            }
            ans.push_back(connected);
        }
        return ans;
    }
};

// ~ JustJie