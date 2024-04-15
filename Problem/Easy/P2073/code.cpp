/********************************************
 * author : Jie Chen (3rd Year CS)
 * school : Rochester Institute of Technology
 * created: 04.08.2024 22:16:20
*********************************************/

using i64 = long long;

class Solution {
public:
    int timeRequiredToBuy(vector<int>& a, int k) {
        int n = a.size();
        int v = a[k];
        int ans = 0;
        for (int i = 0; i < n; i++) {
            if (i <= k) {
                ans += min(a[i], v);
            } else {
                ans += min(a[i], v - 1);
            }
        }
        return ans;
    }
};

// ~ JustJie