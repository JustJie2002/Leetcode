/********************************************
 * author : Jie Chen (4th Year CS)
 * school : Rochester Institute of Technology
 * created: 08.13.2024 19:01:36
*********************************************/

using i64 = long long;

class Solution {
public:
    int minSubArrayLen(int target, vector<int>& a) {
        int n = a.size();

        int sum = 0, ans = n + 1;
        for (int l = 0, r = 0; r < n; r++) {
            sum += a[r];
            while (sum >= target) {
                ans = min(ans, r - l + 1);
                sum -= a[l];
                l++;
            }
        }

        if (ans == n + 1) {
            ans = 0;
        }
        return ans;
    }
};

// ~ JustJie