/********************************************
 * author : Jie Chen (3rd Year CS)
 * school : Rochester Institute of Technology
 * created: 05.25.2024 12:23:13
*********************************************/

using i64 = long long;

class Solution {
public:
    int duplicateNumbersXOR(vector<int>& a) {
        unordered_set<int> S;
        int ans = 0;
        int res = 0;
        for (int x : a) {
            if (!S.contains(x)) {
                res ^= x;
                S.insert(x);
            }
            ans ^= x;
        }
        return ans ^ res;
    }
};

// ~ JustJie