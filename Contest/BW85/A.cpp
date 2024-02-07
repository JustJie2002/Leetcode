/********************************************
 * author : Jie Chen (3rd Year CS)
 * school : Rochester Institute of Technology
 * created: 02.06.2024 21:31:09
*********************************************/

using i64 = long long;

constexpr int INF = 1e9 + 5;

class Solution {
public:
    int minimumRecolors(string s, int k) {
        int n = s.size();

        int ans = INF;
        for (int i = 0; i < n - k + 1; i++) {
            int b = 0;
            for (int j = 0; j < k; j++) {
                if (s[i + j] == 'B') {
                    b++;
                }
            }
            ans = min(ans, k - b);
        }

        return ans;
    }
};

// ~ JustJie