/********************************************
 * author : Jie Chen (3rd Year CS)
 * school : Rochester Institute of Technology
 * created: 02.17.2024 21:30:16
*********************************************/

using i64 = long long;

constexpr int A = 26;

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

struct Trie {
    struct Info {
        HashMap<int, Info*> nex;
        int count = 0;
    };

    Info* head = NULL;
    Trie() { head = new Info(); }

    int ord(char c) { return c - 'a'; }

    void add(const string& s) {
        int n = s.size();
        Info* temp = head;
        for (int i = 0; i < n; i++) {
            int x = ord(s[i]), y = ord(s[n - i - 1]);
            if (temp->nex.find(x * A + y) == temp->nex.end()) {
                temp->nex[x * A + y] = new Info();
            }
            temp = temp->nex[x * A + y];
        }
        temp->count++;
    }

    i64 query(const string& s) {
        int n = s.size();
        Info* temp = head;
        i64 ans = 0;
        for (int i = 0; i < n; i++) {
            int x = ord(s[i]), y = ord(s[n - i - 1]);
            if (temp->nex.find(x * A + y) == temp->nex.end()) {
                break;
            }
            temp = temp->nex[x * A + y];
            ans += temp->count;
        }
        return ans;
    }
};

class Solution {
public:
    i64 countPrefixSuffixPairs(vector<string>& words) {
        // good(a, b),  a is both prefix and suffix of b

        Trie t;
        i64 res = 0;
        for (const auto& word : words) {
            res += t.query(word);
            t.add(word);
        }

        return res;
    }
};

// ~ JustJie