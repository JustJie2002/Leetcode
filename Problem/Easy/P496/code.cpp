/********************************************
 * author : Jie Chen (3rd Year CS)
 * school : Rochester Institute of Technology
 * created: 01.30.2024 18:16:55
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

class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& a, vector<int>& b) {
        int n = a.size(), m = b.size();

        HashMap<int, int> idx;
        for (int i = 0; i < n; i++) {
            idx[a[i]] = i;
        }

        vector<int> ans(n, -1);
        stack<int, vector<int>> stk;
        for (int i = m - 1; i >= 0; i--) {
            int x = b[i];
            while (!stk.empty() && x > b[stk.top()]) {
                stk.pop();
            }
            if (!stk.empty() && idx.find(x) != idx.end()) {
                int j = idx[x];
                ans[j] = b[stk.top()];
            }
            stk.push(i);
        }

        return ans;
    }
};

// ~ JustJie