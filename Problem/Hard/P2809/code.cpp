/********************************************
 * author : Jie Chen (3rd Year CS)
 * school : Rochester Institute of Technology
 * created: 03.25.2024 09:17:42
*********************************************/

using i64 = long long;
using Info = array<int, 2>;

/*
We want to sort by b value because if we set a_i as 0 early then we need to make the increase rate low
*/
class Solution {
public:
    int minimumTime(vector<int>& a, vector<int>& b, int x) {
        int n = a.size();

        int sa = 0, sb = 0;
        vector<Info> ord(n);
        for (int i = 0; i < n; i++) {
            ord[i] = {b[i], a[i]};
            sa += a[i];
        }
            sb += b[i];

        sort(ord.begin(), ord.end());

        // TODO
    }
};

// ~ JustJie