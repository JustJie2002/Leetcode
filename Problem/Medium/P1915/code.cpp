/********************************************
 * author : Jie Chen (3rd Year CS)
 * school : Rochester Institute of Technology
 * created: 04.30.2024 18:46:48
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

constexpr int A = 'j' - 'a' + 1;

class Solution {
public:
    i64 wonderfulSubstrings(string s) {
        int n = s.length();

        umap<int, int> occs;
        occs[0]++;
        int msk = 0;
        i64 ans = 0;
        for (auto c : s) {
            int o = c - 'a';
            msk ^= (1 << o);
            ans += occs[msk];
            for (int a = 0; a < A; a++) {
                ans += occs[msk ^ (1 << a)];
            }
            occs[msk]++;
        }
        return ans;
    }
};

// ~ JustJie