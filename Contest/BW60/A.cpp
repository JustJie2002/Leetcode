/********************************************
 * author : Jie Chen (3rd Year CS)
 * school : Rochester Institute of Technology
 * created: 05.19.2024 20:22:30
*********************************************/

using i64 = long long;

class Solution {
public:
    int findMiddleIndex(vector<int>& a) {
        int n = a.size();

        vector<int> pre(n + 1);
        for (int i = 0; i < n; i++) {
            pre[i + 1] = pre[i] + a[i];
        }

        for (int i = 0; i < n; i++) {
            if (pre[i] == pre[n] - pre[i + 1]) {
                return i;
            }
        }

        return -1;
    }
};

// ~ JustJie