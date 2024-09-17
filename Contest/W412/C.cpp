/********************************************
 * author : Jie Chen (4th Year CS)
 * school : Rochester Institute of Technology
 * created: 08.24.2024 23:18:32
*********************************************/

using i64 = long long;
using Info = array<int, 2>;

class Solution {
public:
    vector<int> getFinalState(vector<int>& a, int k, int m) {
        int n = a.size();

        vector<Info> sorted;
        for (int i = 0; i < n; i++) {
            sorted.push_back({a[i], i});
        }

        ranges::sort(sorted);

        
    }
};

// ~ JustJie