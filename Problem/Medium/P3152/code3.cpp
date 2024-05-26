/********************************************
 * author : Jie Chen (3rd Year CS)
 * school : Rochester Institute of Technology
 * created: 05.19.2024 13:24:20
*********************************************/

using i64 = long long;

class Solution {
public:
    vector<bool> isArraySpecial(vector<int>& a, vector<vector<int>>& queries) {
        int n = a.size();

        vector<int> pre(n);
        for (int i = 0; i < n - 1; i++) {
            pre[i + 1] = pre[i] + int((a[i] % 2) != (a[i + 1] % 2));
        }

        int qs = queries.size();
        vector<bool> ans;
        ans.reserve(qs);
        for (const auto& q : queries) {
            int l = q[0], r = q[1];
            ans.push_back(pre[r] - pre[l] == r - l);
        }
        return ans;
    }
};

// ~ JustJie