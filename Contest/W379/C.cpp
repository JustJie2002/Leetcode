/********************************************
 * author : Jie Chen (3rd Year CS)
 * school : Rochester Institute of Technology
 * created: 01.06.2024 21:33:04
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
using hash_map = __gnu_pbds::gp_hash_table<K, V, Hash>;
 
template <typename K, typename Hash = custom_hash>
using hash_set = hash_map<K, __gnu_pbds::null_type, Hash>;

class Solution {
public:
    int maximumSetSize(vector<int>& a, vector<int>& b) {
        int n = a.size();

        map<int, int> afreq, bfreq;
        for (int x : a) {
            afreq[x]++;
        }
        for (int x : b) {
            bfreq[x]++;
        }

        int rema = n / 2, remb = n / 2;
        int diffa = 0, diffb = 0, same = 0;
        for (const auto& [x, f] : afreq) {
            if (bfreq.contains(x)) {
                same++;
            } else {
                diffa++;
            }
            rema -= (f - 1);
        }
        for (const auto& [x, f] : bfreq) {
            if (!afreq.contains(x)) {
                diffb++;
            }
            remb -= (f - 1);
        }

        vector<int> good(same, 2);
        if (diffa >= diffb) {
            for (int i = 0, j = 0; i < rema; i++) {
                if (j < same) {
                    good[j]--;
                    j++;
                } else {
                    diffa--;
                }
            }
            for (int i = 0, j = same - 1; i < remb; i++) {
                if (j >= 0) {
                    good[j]--;
                    j--;
                } else {
                    diffb--;
                }
            }
        } else {
            for (int i = 0, j = same - 1; i < remb; i++) {
                if (j >= 0) {
                    good[j]--;
                    j--;
                } else {
                    diffb--;
                }
            }
            for (int i = 0, j = 0; i < rema; i++) {
                if (j < same) {
                    good[j]--;
                    j++;
                } else {
                    diffa--;
                }
            }
        }
        int ans = diffa + diffb;
        for (int i = 0; i < same; i++) {
            if (good[i]) {
                ans++;
            }
        }
        return ans;
    }
};

// ~ JustJie