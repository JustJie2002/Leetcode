/********************************************
 * author : Jie Chen (3rd Year CS)
 * school : Rochester Institute of Technology
 * created: 04.16.2024 12:44:18
*********************************************/

using i64 = long long;

class Solution {
public:
    int longestOnes(vector<int>& a, int k) {
        int n = a.size();
        
        int res = 0;
        int ans = 0;
        for (int l = 0, r = 0; r < n; r++) {
            if (a[r] == 0) {
                res++;
            }

            while (res > k) {
                if (a[l] == 0) {
                    res--;
                }
                l++;
            }

            ans = max(ans, r - l + 1);
        }

        return ans;
    }
};

// ~ JustJie