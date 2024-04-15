/********************************************
 * author : Jie Chen (3rd Year CS)
 * school : Rochester Institute of Technology
 * created: 04.08.2024 21:50:17
*********************************************/

using i64 = long long;

constexpr int inf = 1e9 + 5;

class Solution {
public:
    int maximumSum(vector<int>& a) {
        int n = a.size();

        vector<int> pre(n + 1), suf(n + 1);
        for (int i = 0; i < n; i++) {
            pre[i + 1] = max(a[i], pre[i] + a[i]);
        }
        for (int i = n - 1; i >= 0; i--) {
            suf[i] = max(a[i], suf[i + 1] + a[i]);
        }

        int ans = -inf;
        for (int i = 0; i < n; i++) {
            ans = max(ans, pre[i] + suf[i + 1]);
            ans = max(ans, pre[i]);
            ans = max(ans, suf[i + 1]);
        }
        return ans;
    }
};

// ~ JustJie