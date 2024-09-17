/********************************************
 * author : Jie Chen (4th Year CS)
 * school : Rochester Institute of Technology
 * created: 07.06.2024 13:16:10
*********************************************/

using i64 = long long;

class Solution {
public:
    long long maximumPoints(vector<int>& a, int cur) {
        ranges::sort(a);
        int lo = a[0];
        if (lo > cur) {
            return 0;
        }
        i64 sum = accumulate(a.begin(), a.end(), 0LL) - 2 * lo + cur;
        return sum / lo + 1;
    }
};

// ~ JustJie