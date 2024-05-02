/********************************************
 * author : Jie Chen (3rd Year CS)
 * school : Rochester Institute of Technology
 * created: 04.29.2024 10:01:33
*********************************************/

using i64 = long long;

class Solution {
public:
    int minOperations(vector<int>& a, int k) {
        a.push_back(k);

        int v = 0;
        for (int x : a) {
            v ^= x;
        }

        return __builtin_popcount(v);
    }
};

// ~ JustJie