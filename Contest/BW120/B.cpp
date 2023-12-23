/********************************************
 * author : Jie Chen (3rd Year CS)
 * school : Rochester Institute of Technology
 * created: 12.23.2023 09:31:59
*********************************************/

using i64 = long long;

class Solution {
public:
    long long largestPerimeter(vector<int>& a) {
        int n = a.size();
        sort(a.begin(), a.end());

        i64 init = a[0] + a[1];
        i64 per = init;
        int res = -1;
        for (int i = 2; i < n; i++) {
            if (a[i] < per) {
                res = i;
            }
            per += a[i];
        }

        return (res == -1 ? -1 : accumulate(a.begin(), a.begin() + res + 1, 0LL));
    }
};

// ~ JustJie