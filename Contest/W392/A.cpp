/********************************************
 * author : Jie Chen (3rd Year CS)
 * school : Rochester Institute of Technology
 * created: 04.06.2024 22:14:50
*********************************************/

using i64 = long long;

class Solution {
public:
    int longestMonotonicSubarray(vector<int>& a) {
        int n = a.size();

        auto work = [&]() {
            int res = 0;
            int p = -1;
            int ans = 0;
            for (int x : a) {
                if (x > p) {
                    res++;
                } else {
                    res = 1;
                }
                p = x;
                ans = max(ans, res);
            }
            return ans;
        };

        int ans = work();
        reverse(a.begin(), a.end());
        ans = max(ans, work());
        return ans;
    }
};

// ~ JustJie