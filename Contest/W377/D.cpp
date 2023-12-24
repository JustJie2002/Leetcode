/********************************************
 * author : Jie Chen (3rd Year CS)
 * school : Rochester Institute of Technology
 * created: 12.23.2023 21:35:53
*********************************************/

using i64 = long long;

struct hashes {
    int base, inv, mod, sz;
    vector<long long> powers = {1}, invpowers = {1}, psa = {0};

    hashes(const string& s, int m = 1000000007, int b = 131) {
        sz = s.size();
        base = b;
        mod = m;

        inv = 1;
        long long cur = base;
        int exp = m - 2;
        for (int exp=m-2; exp; exp>>=1) {
            if (exp&1) inv = 1LL * inv * cur % m;
            cur = cur * cur % m;
        }

        for (int i=0; i<s.size(); i++) {
            powers.push_back(powers.back()*base%mod);
            invpowers.push_back(invpowers.back()*inv%mod);
            psa.push_back((psa.back()+s[i]*powers[i])%mod);
        }
    }

    hashes() {}
    
    long long get(int l, int r) {
        return (psa[r+1]-psa[l]+mod)*invpowers[l]%mod;
    }
};

i64 whole(const string& s) {
    int m = 1000000007, int b = 131;
    i64 psa = 0;
    i64 pw = 0;
    for (int i=0; i<s.size(); i++) {
        powers.push_back(powers.back()*base%mod);
        psa.push_back((psa.back()+s[i]*powers[i])%mod);
    }
}

constexpr int N = 201;
constexpr i64 inf = i64(1e18) + 5;
i64 w[N][N];

void Init() {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (i != j) {
                w[i][j] = inf;
            }
        }
    }
}

void ckmin(i64& a, i64 b) {
    if (b < a) {
        a = b;
    }
}

struct custom_hash {
    static uint64_t splitmix64(uint64_t x) {
        // http://xorshift.di.unimi.it/splitmix64.c
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }

    size_t operator()(uint64_t x) const {
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }
};

class Solution {
public:
    long long minimumCost(string s, string t, vector<string>& a, vector<string>& b, vector<int>& c) {
        int n = s.size();
        int m = a.size();

        Init();

        hashes s_hash(s), t_hash(t);

        unordered_map<i64, int, custom_hash> ids;
        int id = 0;

        auto create = [&](const auto& s) -> int {
            if (!ids.count(s)) {
                ids[s] = id++;
            }
            return ids[s];
        };
        auto get = [&](const auto& s) -> int {
            if (!ids.count(s)) {
                return -1;
            }
            return ids[s];
        };

        for (int i = 0; i < m; i++) {
            int o = a[i].size();
            i64 from = create(hashes(a[i]).get(0, o - 1)), to = create(hashes(b[i]).get(0, o - 1));
            ckmin(w[from][to], c[i]);
        }

        for (int k = 0; k < id; k++) {
            for (int i = 0; i < id; i++) {
                for (int j = 0; j < id; j++) {
                    ckmin(w[i][j], w[i][k] + w[k][j]);
                }
            }
        }

        vector<vector<i64>> dp(n, vector<i64>(n, inf));
        for (int j = n - 1; j >= 0; j--) {
            for (int i = j; i < n; i++) {
                i64 from = s_hash.get(j, i);
                i64 to = t_hash.get(j, i);
                int aa = get(from), bb = get(to);
                if (from == to) {
                    if (i == n - 1) {
                        ckmin(dp[j][i], 0);
                    } else if (dp[i + 1][n - 1] != inf) {
                        ckmin(dp[j][n - 1], dp[i + 1][n - 1]);
                    }
                }
                if (aa == -1 || bb == -1) {
                    continue;
                }
                if (w[aa][bb] != inf) {
                    if (i == n - 1) {
                        ckmin(dp[j][i], w[aa][bb]);
                    } else if (dp[i + 1][n - 1] != inf) {
                        ckmin(dp[j][n - 1], dp[i + 1][n - 1] + w[aa][bb]);
                    }
                }
            }
        }

        auto& res = dp[0][n - 1];
        return (res == inf ? -1 : res);
    }
};

// ~ JustJie