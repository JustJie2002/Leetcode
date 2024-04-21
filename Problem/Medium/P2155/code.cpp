/********************************************
 * author : Jie Chen (3rd Year CS)
 * school : Rochester Institute of Technology
 * created: 04.15.2024 22:30:33
*********************************************/

using i64 = long long;

class Solution {
public:
    vector<int> maxScoreIndices(vector<int>& a) {
        int n = a.size();

        vector<int> pre(n + 1);
        for (int i = 0; i < n; i++) {
            pre[i + 1] = pre[i] + a[i];
        }

        int ans = pre[n];
        vector<int> ret;
        ret.push_back(0);
        for (int i = 0; i < n; i++) {
            int res = (i + 1 - pre[i + 1]) + (pre[n] - pre[i + 1]);
            if (res > ans) {
                ans = res;
                ret = {i + 1};
            } else if (res == ans) {
                ret.push_back(i + 1);
            }
        }
        return ret;
    }
};

// ~ JustJie