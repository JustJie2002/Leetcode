/********************************************
 * author : Jie Chen (4th Year CS)
 * school : Rochester Institute of Technology
 * created: 06.02.2024 13:18:23
*********************************************/

using i64 = long long;

constexpr int inf = 1e9 + 5;

class Solution {
public:
    int minimumDifference(vector<int>& a, int k) {
        int n = a.size();

        int ans = inf;
        for (int i = 0; i < n; i++) {
            ans = min(ans, abs(a[i] - k));
            for (int j = i - 1; j >= 0 && (a[j] & a[i]) != a[j]; j--) {
                ans = min(ans, abs(a[j] - k));
                a[j] &= a[i];
            }
        }

        return ans;
    }
};

// ~ JustJie