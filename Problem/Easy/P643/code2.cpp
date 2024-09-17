/********************************************
 * author : Jie Chen (4th Year CS)
 * school : Rochester Institute of Technology
 * created: 08.13.2024 19:52:39
*********************************************/

using i64 = long long;

class Solution {
public:
    double findMaxAverage(vector<int>& a, int k) {
        int n = a.size();

        vector<int> pre(n + 1);
        for (int i = 0; i < n; i++) {
            pre[i + 1] = pre[i] + a[i];
        }

        double ans = -1e9;
        for (int i = k; i <= n; i++) {
            ans = max(ans, 1. * (pre[i] - pre[i - k]) / k);
        }
        return ans;
    }
};

// ~ JustJie