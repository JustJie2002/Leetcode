/********************************************
 * author : Jie Chen (3rd Year CS)
 * school : Rochester Institute of Technology
 * created: 03.13.2024 23:55:51
*********************************************/

using i64 = long long;

class Solution {
public:
    int numSubarraysWithSum(vector<int>& a, int t) {
        unordered_map<int, int> pre = {{0, 1}};
        int cur = 0;
        int ans = 0;
        for (int x : a) {
            cur += x;
            int w = cur - t;
            ans += pre[w];
            pre[cur]++;
        }

        return ans;
    }
};

// ~ JustJie