/********************************************
 * author : Jie Chen (3rd Year CS)
 * school : Rochester Institute of Technology
 * created: 03.20.2024 00:37:14
*********************************************/

using i64 = long long;

class Solution {
public:
    int hIndex(vector<int>& a) {
        int n = a.size();

        sort(a.rbegin(), a.rend());

        for (int i = 0; i < n; i++) {
            if (a[i] < i + 1) {
                return i;
            }
        }

        return n;
    }
};

// ~ JustJie