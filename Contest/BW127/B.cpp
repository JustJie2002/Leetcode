/********************************************
 * author : Jie Chen (3rd Year CS)
 * school : Rochester Institute of Technology
 * created: 03.30.2024 12:25:55
*********************************************/

using i64 = long long;

class Solution {
public:
    int minimumLevels(vector<int>& a) {
        int n = a.size();

        for (int& x : a) {
            if (x == 0) {
                x = -1;
            }
        }

        vector<int> pre(n + 1);
        for (int i = 0; i < n; i++) {
            pre[i + 1] = pre[i] + a[i];
        }

        for (int i = 1; i < n; i++) {
            if (pre[i] > pre.back() - pre[i]) {
                return i;
            }
        }

        // vector<int> suf(n);
        // int mi = 0;
        // int cur = 0;
        // for (int i = n - 1; i >= 1; i--) {
        //     cur += a[i];
        // }
        return -1;
    }
};

// ~ JustJie