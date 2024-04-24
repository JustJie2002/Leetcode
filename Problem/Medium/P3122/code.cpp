/********************************************
 * author : Jie Chen (3rd Year CS)
 * school : Rochester Institute of Technology
 * created: 04.22.2024 17:03:01
*********************************************/

using i64 = long long;
using Info = array<int, 2>;

constexpr int inf = 1e9 + 5;

class Solution {
public:
    int minimumOperations(vector<vector<int>>& aa) {
        int n = aa.size(), m = aa[0].size();

        auto get_requires = [&](int c) {
            array<int, 10> freq {};
            for (int r = 0; r < n; r++) {
                int x = aa[r][c];
                freq[x]++;
            }
            for (int i = 0; i < 10; i++) {
                freq[i] = n - freq[i];
            }
            return freq;
        };

        auto dp = get_requires(0);
        for (int i = 1; i < m; i++) {
            auto nfreq = get_requires(i);
            array<int, 10> ndp {};
            ndp.fill(inf);
            for (int j = 0; j < 10; j++) {
                for (int k = 0; k < 10; k++) {
                    if (j != k) {
                        ndp[k] = min(ndp[k], dp[j] + nfreq[k]);
                    }
                }
            }
            dp.swap(ndp);
        }

        return *min_element(dp.begin(), dp.end());
    }
};

// ~ JustJie