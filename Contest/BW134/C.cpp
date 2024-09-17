/********************************************
 * author : Jie Chen (4th Year CS)
 * school : Rochester Institute of Technology
 * created: 07.06.2024 11:29:11
*********************************************/

using i64 = long long;

class Solution {
public:
    int numberOfAlternatingGroups(vector<int>& a, int k) {
        int n = a.size();

        for (int i = 0; i < n; i++) {
            a.push_back(a[i]);
        }

        int ans = 0;
        int res = 0;
        for (int i = 0; i < k - 1; i++) {
            if (a[i] != a[i + 1]) {
                res++;
            }
        }
        if (res == k - 1) {
            ans++;
        }
        for (int i = 0; i < n - 1; i++) {
            if (a[i] != a[i + 1]) {
                res--;
            }
            if (a[i + k - 1] != a[i + k]) {
                res++;
            }
            if (res == k - 1) {
                ans++;
            }
        }
        return ans;
    }
};

// ~ JustJie