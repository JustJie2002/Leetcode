/********************************************
 * author : Jie Chen (3rd Year CS)
 * school : Rochester Institute of Technology
 * created: 12.14.2023 02:11:15
*********************************************/

using i64 = long long;

class Solution {
public:
    vector<int> findIntersectionValues(vector<int>& a, vector<int>& b) {
        set<int> sa(a.begin(), a.end()), sb(b.begin(), b.end());

        vector<int> ans(2);
        for (int x : a) {
            ans[0] += sb.count(x);
        }
        for (int x : b) {
            ans[1] += sa.count(x);
        }

        return ans;
    }
};

// ~ JustJie