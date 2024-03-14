/********************************************
 * author : Jie Chen (3rd Year CS)
 * school : Rochester Institute of Technology
 * created: 03.09.2024 22:01:11
*********************************************/

using i64 = long long;

class Solution {
public:
    i64 maximumHappinessSum(vector<int>& hap, int k) {
        int n = hap.size();
        sort(hap.rbegin(), hap.rend());

        i64 ans = 0;
        for (int i = 0; i < k; i++) {
            ans += max(0, hap[i] - i);
        }

        return ans;
    }
};

// ~ JustJie