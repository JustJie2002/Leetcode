/********************************************
 * author : Jie Chen (4th Year CS)
 * school : Rochester Institute of Technology
 * created: 08.13.2024 19:34:43
*********************************************/

using i64 = long long;

class Solution {
public:
    double findMaxAverage(vector<int>& a, int k) {
        int n = a.size();

        int sum = 0;
        double ans = -1e9;
        for (int l = 0, r = 0; r < n; r++) {
            sum += a[r];
            if (r - l + 1 > k) {
                sum -= a[l];
                l++;
            }
            if (r - l + 1 == k) {
                ans = max(ans, 1. * sum / k);
            }
        }
        return ans;
    }
};

// ~ JustJie