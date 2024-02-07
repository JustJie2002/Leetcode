/********************************************
 * author : Jie Chen (3rd Year CS)
 * school : Rochester Institute of Technology
 * created: 02.04.2024 20:48:20
*********************************************/

using i64 = long long;

class Solution {
public:
    long long numberOfWays(string s) {
        int n = s.size();

        vector<array<int, 2>> suf(n + 1);
        suf[n] = {};
        for (int i = n - 1; i >= 0; i--) {
            suf[i] = suf[i + 1];
            suf[i][s[i] - '0']++;
        }

        array<int, 2> pre{};
        i64 ans = 0;
        for (int i = 0; i < n; i++) {
            int a = s[i] - '0';
            int b = a ^ 1;
            ans += 1LL * pre[b] * suf[i + 1][b];
            pre[a]++;
        }
        return ans;
    }
};

// ~ JustJie