/********************************************
 * author : Jie Chen (3rd Year CS)
 * school : Rochester Institute of Technology
 * created: 01.09.2024 13:39:22
*********************************************/

using i64 = long long;

constexpr int N = 16, M = 1 << 16;

pair<int, int> dp[N + 1][M];
// dp[i][j]: [pre_mask, cnt]

class Solution {
public:
    vector<int> smallestSufficientTeam(vector<string>& req, vector<vector<string>>& pref) {
        int n = req.size(), m = pref.size();

        unordered_map<string, int> compression;
        for (int i = 0; i < n; i++) {
            compression[req[i]] = i;
        }

        vector<int> pref_mask(m);
        for (int i = 0; i < m; i++) {
            for (const auto& r : pref[i]) {
                pref_mask[i] |= (1 << compression[r]);
            }
        }

        memset(dp, -1, sizeof(dp));

        for (int i = 0; i < m; i++) {
            for (int mask = 0; mask < (1 << n); mask++) {
                if (dp[i][mask] != -1) {
                    int can_use_mask = pref_mask[i] & ~mask;
                    for (int j = 0; j < m; j++) {
                        if (can_use_mask & (1 << j)) {
                            dp[i + 1][mask] = 
                        }
                    }
                }
            }
        }
    }
};

// ~ JustJie