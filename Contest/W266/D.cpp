/********************************************
 * author : Jie Chen (3rd Year CS)
 * school : Rochester Institute of Technology
 * created: 01.10.2024 23:20:29
*********************************************/

using i64 = long long;
using Pair = pair<int, int>;

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

class Solution {
public:
    int maximalPathQuality(vector<int>& a, vector<vector<int>>& edges, int m) {
        int n = a.size();

        vector<vector<Pair>> adj(n);
        for (const auto& edge : edges) {
            int u = edge[0], v = edge[1], w = edge[2];
            adj[u].emplace_back(v, w);
            adj[v].emplace_back(u, w);
        }

        HashMap<int, int> vis;
        int ans = 0;
        auto dfs = [&](const auto& self, int cur, int t) -> void {
            vis[cur]++;
            if (cur == 0) {
                int res = 0;
                for (const auto& [x, _] : vis) {
                    res += a[x];
                }
                ans = max(ans, res);
            }
            for (const auto& [nei, dis] : adj[cur]) {
                if (t >= dis) {
                    self(self, nei, t - dis);
                }
            }
            if (--vis[cur] == 0) {
                vis.erase(cur);
            }
        };
        dfs(dfs, 0, m);
        return ans;
    }
};

// ~ JustJie