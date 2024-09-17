/********************************************
 * author : Jie Chen (4th Year CS)
 * school : Rochester Institute of Technology
 * created: 06.29.2024 22:45:36
*********************************************/

using i64 = long long;

class Solution {
public:
    int maximumLength(vector<int>& a) {
        int n = a.size();

        int e = 0, o = 0;

        for (int x : a) {
            if (x % 2 == 0) {
                e++;
            } else {
                o++;
            }
        }

        int ans = max(e, o);
        e = 0, o = 0;
        for (int x : a) {
            if (x % 2 == 0) {
                e = max(e, o + 1);
            } else {
                o = max(o, e + 1);
            }
        }
        ans = max(ans, e);
        ans = max(ans, o);
        return ans;
    }
};

// ~ JustJie