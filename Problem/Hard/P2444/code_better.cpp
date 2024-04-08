/********************************************
 * author : Jie Chen (3rd Year CS)
 * school : Rochester Institute of Technology
 * created: 03.30.2024 22:16:01
*********************************************/

using i64 = long long;

class Solution {
public:
    i64 countSubarrays(vector<int>& a, int minK, int maxK) {
        int n = a.size();

        i64 ans = 0;
        int bad = -1, mi = -1, ma = -1;
        for (int i = 0; i < n; i++) {
            if (a[i] < minK || a[i] > maxK) {
                bad = i;
            }
            if (a[i] == minK) {
                mi = i;
            }
            if (a[i] == maxK) {
                ma = i;
            }
            ans += max(
                0,
                min(mi, ma) - bad
            );
        }

        return ans;
    }
};

// ~ JustJie