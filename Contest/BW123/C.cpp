/********************************************
 * author : Jie Chen (3rd Year CS)
 * school : Rochester Institute of Technology
 * created: 03.09.2024 20:06:44
*********************************************/

using i64 = long long;

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

constexpr i64 inf = 1e15 + 10;

class Solution {
public:
    i64 maximumSubarraySum(vector<int>& a, int k) {
        HashMap<int, i64> pos;
        i64 pre = 0, ans = -inf;
        for (int x : a) {
            if (pos.find(x) == pos.end()) {
                pos[x] = inf;
            }
            pos[x] = min(pos[x], pre);

            pre += x;
            for (int d : {x - k, x + k}) {
                if (pos.find(d) != pos.end()) {
                    ans = max(ans, pre - pos[d]);
                }
            }
        }

        if (ans == -inf) {
            ans = 0;
        }
        return ans;
    }
};

// ~ JustJie