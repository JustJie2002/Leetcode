/********************************************
 * author : Jie Chen (3rd Year CS)
 * school : Rochester Institute of Technology
 * created: 04.24.2024 22:40:57
*********************************************/

using i64 = long long;

constexpr int A = 26;

class Solution {
public:
    int longestIdealString(string s, int k) {
        array<int, A> dp {};
        for (char c : s) {
            int o = c - 'a';
            dp[o]++;
            for (int a = 0; a < A; a++) {
                if (abs(o - a) <= k && o != a) {
                    dp[o] = max(dp[o], dp[a] + 1);
                }
            }
        }
        return *max_element(dp.begin(), dp.end());
    }
};

// ~ JustJie