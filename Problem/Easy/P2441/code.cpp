/********************************************
 * author : Jie Chen (3rd Year CS)
 * school : Rochester Institute of Technology
 * created: 05.01.2024 20:33:51
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
using umap = __gnu_pbds::gp_hash_table<K, V, Hash>;
 
template <typename K, typename Hash = custom_hash>
using uset = umap<K, __gnu_pbds::null_type, Hash>;

class Solution {
public:
    int findMaxK(vector<int>& a) {
        uset<int> s;
        int ans = -1;
        for (int x : a) {
            int op = -x;
            if (s.find(op) != s.end()) {
                ans = max(ans, abs(x));
            }
            s.insert(x);
        }
        return ans;
    }
};

// ~ JustJie