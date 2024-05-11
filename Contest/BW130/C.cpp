/********************************************
 * author : Jie Chen (3rd Year CS)
 * school : Rochester Institute of Technology
 * created: 05.11.2024 10:49:41
*********************************************/

using i64 = long long;

constexpr int A = 26;

constexpr int inf = 1e9 + 5;

class Solution {
public:
    int minimumSubstringsInPartition(string s) {
        int n = s.length();

        vector<array<int, A>> freq(n + 1);
        freq[0] = {};
        for (int i = 0; i < n; i++) {
            freq[i + 1] = freq[i];
            freq[i + 1][s[i] - 'a']++;
        }

        auto issoke = [&](int l, int r) {
            auto cur = freq[r + 1];
            int cnt = -1;
            for (int a = 0; a < A; a++) {
                int d = (freq[r + 1][a] - freq[l][a]);
                if (d == 0) {
                    continue;
                }
                if (cnt == -1) {
                    cnt = d;
                }
                if (d != cnt) {
                    return false;
                }
            }
            return true;
        };

        vector<int> dp(n + 1);
        iota(dp.begin(), dp.end(), 0);
        for (int i = 0; i < n; i++) {
            for (int j = i; j < n; j++) {
                if (issoke(i, j)) {
                    dp[j + 1] = min(dp[j + 1], dp[i] + 1);
                }
            }
        }
        return dp[n];
    }
};

// ~ JustJie