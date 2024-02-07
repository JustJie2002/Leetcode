/********************************************
 * author : Jie Chen (3rd Year CS)
 * school : Rochester Institute of Technology
 * created: 01.20.2024 12:39:45
*********************************************/

using i64 = long long;

#define foo(mask)  __builtin_popcount(mask)

class Solution {
public:
    bool canSortArray(vector<int>& a) {
        int n = a.size();

        for (int i = 0; i < n; i++) {
            for (int j = n - 1; j > i; j--) {
                if (a[j] < a[j - 1] && foo(a[j]) == foo(a[j - 1])) {
                    swap(a[j], a[j - 1]);
                }
            }
        }

        return is_sorted(a.begin(), a.end());
    }
};

// ~ JustJie