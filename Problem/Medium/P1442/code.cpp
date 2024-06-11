/********************************************
 * author : Jie Chen (4th Year CS)
 * school : Rochester Institute of Technology
 * created: 05.30.2024 00:13:05
*********************************************/

using i64 = long long;

class Solution {
public:
    int countTriplets(vector<int>& a) {
        int n = a.size();
        unordered_map<int, int> par, tot;
        int pre = 0;
        int ans = 0;
        par[0]++;
        for (int i = 0; i < n; i++) {
            pre ^= a[i];
            ans += par[pre] * i - tot[pre];
            tot[pre] += (i + 1);
            par[pre]++;
        }
        return ans;
    }
};

// ~ JustJie