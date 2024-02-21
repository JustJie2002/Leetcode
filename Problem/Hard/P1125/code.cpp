/********************************************
 * author : Jie Chen (3rd Year CS)
 * school : Rochester Institute of Technology
 * created: 01.09.2024 13:39:22
*********************************************/

#include <ext/pb_ds/assoc_container.hpp>

struct custom_hash {
    static uint64_t splitmix64(uint64_t x) {
        // http://xorshift.di.unimi.it/splitmix64.c
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }
 
    size_t operator()(uint64_t x) const {
        static const uint64_t FIXED_RANDOM = std::chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }
};
 
template <typename K, typename V, typename Hash = custom_hash>
using HashMap = __gnu_pbds::gp_hash_table<K, V, Hash>;
 
template <typename K, typename Hash = custom_hash>
using HashSet = HashMap<K, __gnu_pbds::null_type, Hash>;

using i64 = long long;

constexpr int N = 16, M = 1 << 16;

pair<int, int> dp[N + 1][M];
// dp[i][j]: [pre_mask, cnt]

class Solution {
public:
    vector<int> smallestSufficientTeam(vector<string>& req, vector<vector<string>>& pref) {
        int n = req.size(), m = pref.size();

        HashMap<string, int> compression;
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