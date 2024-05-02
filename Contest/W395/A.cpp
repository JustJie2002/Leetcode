/********************************************
 * author : Jie Chen (3rd Year CS)
 * school : Rochester Institute of Technology
 * created: 04.27.2024 22:24:32
*********************************************/

using i64 = long long;

class Solution {
public:
    int addedInteger(vector<int>& a, vector<int>& b) {
        sort(a.begin(), a.end());
        sort(b.begin(), b.end());

        return b[0] - a[0];
    }
};

// ~ JustJie