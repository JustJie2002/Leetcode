/********************************************
 * author : Jie Chen (4th Year CS)
 * school : Rochester Institute of Technology
 * created: 06.30.2024 17:50:04
*********************************************/

using i64 = long long;

class Solution {
public:
    int maximumLength(vector<int>& a) {
        int n = a.size();

        int occ[2] {};
        int dp[2] {};
        for (int x : a) {
            x %= 2;
            occ[x]++;
            dp[1 - x] = max(dp[1 - x], dp[x] + 1);
        }
        
        return max(
            *max_element(occ, occ + 2),
            *max_element(dp, dp + 2)
        );
    }
};

// ~ JustJie