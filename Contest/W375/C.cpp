/********************************************
 * author : Jie Chen (3rd Year CS)
 * school : Rochester Institute of Technology
 * created: 12.14.2023 02:23:47
*********************************************/

using i64 = long long;

class Solution {
public:
    i64 countSubarrays(vector<int>& a, int k) {
        int n = a.size(), mx = *max_element(a.begin(), a.end());

        int acc = 0;
        i64 res = 0;
        for (int R = 0, L = 0; R < n; R++) {
            acc += int(a[R] == mx);
            while (acc >= k) {
                acc -= int(a[L] == mx);
                L++;
            }
            res += L;
        }
        return res;
    }
};

// ~ JustJie