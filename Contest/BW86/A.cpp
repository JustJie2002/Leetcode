/********************************************
 * author : Jie Chen (3rd Year CS)
 * school : Rochester Institute of Technology
 * created: 02.27.2024 21:47:36
*********************************************/

using i64 = long long;

class Solution {
public:
    bool findSubarrays(vector<int>& a) {
        int n = a.size();
        set<int> s;
        for (int i = 0; i < n - 1; i++) {
            s.insert(a[i] + a[i + 1]);
        }
        return s.size() != n - 1;
    }
};

// ~ JustJie