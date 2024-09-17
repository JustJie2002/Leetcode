/********************************************
 * author : Jie Chen (4th Year CS)
 * school : Rochester Institute of Technology
 * created: 07.06.2024 22:33:50
*********************************************/

using i64 = long long;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
constexpr int MOD = int(1e9) + 7;

template<typename T, bool RAND = true, bool LEFT_HASH = true>
struct hashes {
    static int global_base1, global_base2;
    static vector<i64> powers1, inv_powers1, powers2, inv_powers2;
    vector<i64> pre;

    hashes(const T &s, int b = 131) {
        int n = s.size();
        int& chosen_base = LEFT_HASH ? global_base1 : global_base2;
        vector<i64> &powers = LEFT_HASH ? powers1 : powers2;
        vector<i64> &inv_powers = LEFT_HASH ? inv_powers1 : inv_powers2;
        if (!chosen_base) {
            chosen_base = RAND ? uniform_int_distribution<int>(200, MOD - 1)(rng) : b;
            i64 cur = chosen_base, inv = 1;
            for (int exp = MOD - 2; exp; exp >>= 1) {
                if (exp & 1) inv = inv * cur % MOD;
                cur = cur * cur % MOD;
            }
            powers.push_back(chosen_base);
            inv_powers.push_back(inv);
        }
        while (powers.size() < n) {
            powers.push_back(powers.back() * chosen_base % MOD);
            inv_powers.push_back(inv_powers.back() * inv_powers[1] % MOD);
        }
        pre.resize(n + 1);
        for (int i = 0; i < n; i++) {
            pre[i + 1] = (pre[i] + s[i] * (LEFT_HASH ? powers1 : powers2)[i]) % MOD;
        }
    }
    hashes() {}

    i64 get(int L, int R) {
        return (pre[R + 1] - pre[L] + MOD) * (LEFT_HASH ? inv_powers1 : inv_powers2)[L] % MOD;
    }
};

template<typename T, bool R, bool LEFT_HASH> int hashes<T, R, LEFT_HASH>::global_base1 = 0;
template<typename T, bool R, bool LEFT_HASH> int hashes<T, R, LEFT_HASH>::global_base2 = 0;
template<typename T, bool R, bool LEFT_HASH> vector<i64> hashes<T, R, LEFT_HASH>::powers1 = {1};
template<typename T, bool R, bool LEFT_HASH> vector<i64> hashes<T, R, LEFT_HASH>::powers2 = {1};
template<typename T, bool R, bool LEFT_HASH> vector<i64> hashes<T, R, LEFT_HASH>::inv_powers1 = {1};
template<typename T, bool R, bool LEFT_HASH> vector<i64> hashes<T, R, LEFT_HASH>::inv_powers2 = {1};

template<typename T, bool RAND = true>
struct double_hash {
    hashes<T, RAND, true> hash1;
    hashes<T, RAND, false> hash2;

    double_hash(const T &s, int base1 = 131, int base2 = 173) : 
        hash1(hashes<T, RAND, true>(s, base1)),
        hash2(hashes<T, RAND, false>(s, base2)) {}
    double_hash() {}

    // Get hash [L, R] inclusive
    i64 get(int L, int R) {
        return (hash1.get(L, R) << 32) | hash2.get(L, R);
    }
};

using string_hash = double_hash<string, true>;

constexpr int INF = int(1e9) + 5;

class Solution {
public:
    int minimumCost(string t, vector<string>& words, vector<int>& costs) {
        int n = t.size(), m = words.size();

        string_hash t_hash(t);

        unordered_map<i64, int> hashes;
        set<int> sizes;

        for (int i = 0; const auto &word : words) {
            auto hash = string_hash(word).get(0, word.size() - 1);
            if (!hashes.contains(hash)) {
                hashes[hash] = costs[i];
            } else {
                hashes[hash] = min(hashes[hash], costs[i]);
            }
            sizes.insert(int(word.size()));
            i++;
        }

        vector<int> dp(n + 1, INF);
        dp[0] = 0;
        for (int i = 1; i <= n; i++) {
            if (dp[i - 1] == INF) {
                continue;
            }
            for (int sz : sizes) {
                if (i + sz - 1 > n) {
                    break;
                }
                auto sub_hash = t_hash.get(i - 1, i + sz - 2);
                if (hashes.contains(sub_hash)) {
                    dp[i + sz - 1] = min(dp[i + sz - 1], dp[i - 1] + hashes[sub_hash]);
                }
            }
        }

        int ans = dp.back();
        if (ans == INF) {
            ans = -1;
        }
        return ans;
    }
};

// ~ JustJie