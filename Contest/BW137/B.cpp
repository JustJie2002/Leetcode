/********************************************
 * author : Jie Chen (4th Year CS)
 * school : Rochester Institute of Technology
 * created: 08.17.2024 10:31:37
*********************************************/

using i64 = long long;

class Solution {
public:
    vector<int> resultsArray(vector<int>& a, int k) {
        int n = a.size();
        vector<int> pre(n);
        pre[0] = 1;
        for (int i = 1; i < n; i++) {
            if (a[i] == a[i - 1] + 1) {
                pre[i] = pre[i - 1] + 1;
            } else {
                pre[i] = 1;
            }
        }

        vector<int> ans;
        for (int i = k - 1; i < n; i++) {
            if (pre[i] < k) {
                ans.push_back(-1);
            } else {
                ans.push_back(a[i]);
            }
        }
        return ans;
    }
};

// ~ JustJie