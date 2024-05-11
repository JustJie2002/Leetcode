/********************************************
 * author : Jie Chen (3rd Year CS)
 * school : Rochester Institute of Technology
 * created: 05.08.2024 23:06:13
*********************************************/

using i64 = long long;

constexpr int inf = 1e9 + 5;

struct Info {
    int cnt;
    vector<int> vec;
    Info(): cnt(inf) {}
};

class Solution {
public:
    vector<int> smallestSufficientTeam(vector<string>& req, vector<vector<string>>& p) {
        int n = p.size(), m = req.size();

        int id = 0;
        unordered_map<string, int> compression;
        auto get = [&](const string& s) {
            return compression[s];
        };

        for (const auto& r : req) {
            compression[r] = id++;
        }

        const int M = 1 << m;
        vector<Info> dp(M);
        dp[0].cnt = 0;
        for (int i = 0; i < n; i++) {
            int msk = 0;
            for (const auto& s : p[i]) {
                msk |= (1 << get(s));
            }
            for (int mask = 0; mask < M; mask++) {
                if (dp[mask].cnt != inf) {
                    int unioned_mask = msk | mask;
                    if (unioned_mask == mask) {
                        continue;
                    }
                    if (dp[unioned_mask].cnt > dp[mask].cnt + 1) {
                        dp[unioned_mask].cnt = dp[mask].cnt + 1;
                        dp[unioned_mask].vec = dp[mask].vec;
                        dp[unioned_mask].vec.push_back(i);
                    }
                }
            }
        }

        return dp[M - 1].vec;
    }
};

// ~ JustJie