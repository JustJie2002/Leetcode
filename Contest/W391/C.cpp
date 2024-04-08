/********************************************
 * author : Jie Chen (3rd Year CS)
 * school : Rochester Institute of Technology
 * created: 03.30.2024 22:31:51
*********************************************/

using i64 = long long;

class Solution {
public:
    i64 countAlternatingSubarrays(vector<int>& a) {
        int n = a.size();
        
        a.push_back(a.back());

        i64 ans = 0;
        int res = 0;
        int p = !a[0];
        for (int x : a) {
            if (x != p) {
                res++;
            } else {
                ans += 1LL * res * (res + 1) / 2;
                res = 1;
            }
            p = x;
        }

        return ans;
    }
};

// ~ JustJie