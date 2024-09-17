/********************************************
 * author : Jie Chen (4th Year CS)
 * school : Rochester Institute of Technology
 * created: 06.29.2024 22:45:36
*********************************************/

using i64 = long long;

class Solution {
public:
    int maximumLength(vector<int>& a) {
        int n = a.size();

        vector dp(n + 1, vector<int>(k + 1, 1));
        int ans = 1;
        vector<int> dp(2);
        for (int i = 0; i < n; i++) {
            int r = a[i] % 2;

        }
        return ans;
    }
};

// ~ JustJie