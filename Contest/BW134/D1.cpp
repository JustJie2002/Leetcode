/********************************************
 * author : Jie Chen (4th Year CS)
 * school : Rochester Institute of Technology
 * created: 07.06.2024 11:48:43
*********************************************/

using i64 = long long;

class Solution {
public:
    long long countSubarrays(vector<int>& a, int k) {
        int n = a.size();

        i64 ans = 0;
        int res = 0;
        for (int i = 0; i < n; i++) {
            if (a[i] == k) {
                res++;
            }
            for (int j = i - 1; j >= 0; j--) {
                if ((a[j] & a[i]) == a[j]) {
                    break;
                }
                if (a[j] == k) {
                    res--;
                }
                a[j] &= a[i];
                if (a[j] == k) {
                    res++;
                }
            }
            ans += res;
        }
        return ans;
    }
};

// ~ JustJie