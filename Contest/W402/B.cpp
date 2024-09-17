/********************************************
 * author : Jie Chen (4th Year CS)
 * school : Rochester Institute of Technology
 * created: 06.15.2024 22:53:29
*********************************************/

using i64 = long long;

class Solution {
public:
    long long countCompleteDayPairs(vector<int>& a) {
        unordered_map<int, int> res;
        i64 ans = 0;
        for (int x : a) {
            x %= 24;
            ans += res[(24 - x) % 24];
            res[x]++;
        }
        return ans;
    }
};

// ~ JustJie