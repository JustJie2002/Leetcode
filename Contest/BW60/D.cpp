/********************************************
 * author : Jie Chen (3rd Year CS)
 * school : Rochester Institute of Technology
 * created: 05.19.2024 20:41:30
*********************************************/

using Factor = pair<int, int>;

constexpr int MAX_SIEVE = 1e6 + 5;
struct PrimeTable {
    vector<int> minp, primes;

    PrimeTable(int n) {
        sieve(n);
    }

    void sieve(int n) {
        minp.assign(n + 1, 0);
        primes.clear();
        
        for (int i = 2; i <= n; i++) {
            if (minp[i] == 0) {
                minp[i] = i;
                primes.push_back(i);
            }
            
            for (auto p : primes) {
                if (i * p > n) {
                    break;
                }
                minp[i * p] = p;
                if (p == minp[i]) {
                    break;
                }
            }
        }
    }

    int sf(int x) {
        return minp[x];
    }
    
    bool is_prime(int x) {
        return sf(x) == x;
    }

    vector<Factor> prime_factorize(int x) {
        vector<Factor> factors;
        int cur_prime = 0, freq = 0;
        while (x != 1) {
            int v = sf(x);
            if (cur_prime == v) {
                freq++;
            } else {
                if (freq) {
                    factors.emplace_back(cur_prime, freq);
                }
                cur_prime = v;
                freq = 1;
            }
            x /= v;
        }
        if (freq) {
            factors.emplace_back(cur_prime, freq);
        }
        return factors;
    }

    vector<int> get_factors(int x) {
        vector<int> a, b;
        for (int i = 1; i * i <= x; i++) {
            if (x % i == 0) {
                a.push_back(i);
                if (i * i != x) {
                    b.push_back(x / i);
                }
            }
        }
        reverse(b.begin(), b.end());
        for (int x : b) {
            a.push_back(x);
        }
        return a;
    }
} pt(MAX_SIEVE);

template<class Fun> class y_combinator_result {
    Fun fun_;
public:
    template<class T> explicit y_combinator_result(T &&fun): fun_(std::forward<T>(fun)) {}
    template<class ...Args> decltype(auto) operator()(Args &&...args) { return fun_(std::ref(*this), std::forward<Args>(args)...); }
};
template<class Fun> decltype(auto) y_combinator(Fun &&fun) { return y_combinator_result<std::decay_t<Fun>>(std::forward<Fun>(fun)); }

using i64 = long long;

// Credit: Jiangly
template<class T>
constexpr T power(T a, i64 b) {
    T res = 1;
    for (; b; b /= 2, a *= a) {
        if (b % 2) {
            res *= a;
        }
    }
    return res;
}

constexpr i64 mul(i64 a, i64 b, i64 p) {
    i64 res = a * b - i64(1.L * a * b / p) * p;
    res %= p;
    if (res < 0) {
        res += p;
    }
    return res;
}
template<int P>
struct MInt {
    int x;
    constexpr MInt() : x{} {}
    constexpr MInt(i64 x) : x{norm(x % getMod())} {}
    
    static int Mod;
    constexpr static int getMod() {
        if (P > 0) {
            return P;
        } else {
            return Mod;
        }
    }
    constexpr static void setMod(int Mod_) {
        Mod = Mod_;
    }
    constexpr int norm(int x) const {
        if (x < 0) {
            x += getMod();
        }
        if (x >= getMod()) {
            x -= getMod();
        }
        return x;
    }
    constexpr int val() const {
        return x;
    }
    explicit constexpr operator int() const {
        return x;
    }
    constexpr MInt operator-() const {
        MInt res;
        res.x = norm(getMod() - x);
        return res;
    }
    constexpr MInt inv() const {
        assert(x != 0);
        return power(*this, getMod() - 2);
    }
    constexpr MInt &operator*=(MInt rhs) & {
        x = 1LL * x * rhs.x % getMod();
        return *this;
    }
    constexpr MInt &operator+=(MInt rhs) & {
        x = norm(x + rhs.x);
        return *this;
    }
    constexpr MInt &operator-=(MInt rhs) & {
        x = norm(x - rhs.x);
        return *this;
    }
    constexpr MInt &operator/=(MInt rhs) & {
        return *this *= rhs.inv();
    }
    friend constexpr MInt operator*(MInt lhs, MInt rhs) {
        MInt res = lhs;
        res *= rhs;
        return res;
    }
    friend constexpr MInt operator+(MInt lhs, MInt rhs) {
        MInt res = lhs;
        res += rhs;
        return res;
    }
    friend constexpr MInt operator-(MInt lhs, MInt rhs) {
        MInt res = lhs;
        res -= rhs;
        return res;
    }
    friend constexpr MInt operator/(MInt lhs, MInt rhs) {
        MInt res = lhs;
        res /= rhs;
        return res;
    }
    friend constexpr std::istream &operator>>(std::istream &is, MInt &a) {
        i64 v;
        is >> v;
        a = MInt(v);
        return is;
    }
    friend constexpr std::ostream &operator<<(std::ostream &os, const MInt &a) {
        return os << a.val();
    }
    friend constexpr bool operator==(MInt lhs, MInt rhs) {
        return lhs.val() == rhs.val();
    }
    friend constexpr bool operator!=(MInt lhs, MInt rhs) {
        return lhs.val() != rhs.val();
    }
};

template<>
int MInt<0>::Mod = 998'244'353;

template<int V, int P>
constexpr MInt<P> CInv = MInt<P>(V).inv();

constexpr int P = 1'000'000'007; // 998'244'353;
using Z = MInt<P>;

class Solution {
public:
    int numberOfGoodSubsets(vector<int>& a) {
        int n = a.size();

        const auto& primes = pt.primes;
        int pcnt = primes.size();

        int free = 0;
        unordered_map<int, int> occs;
        unordered_set<int> seen;
        vector<int> mask;
        for (int x : a) {
            if (x == 1) {
                free++;
            } else {
                int cur_mask = 0;
                for (int p = 0; p < pcnt; p++) {
                    int pr = primes[p];
                    if (pr > x) {
                        break;
                    }
                    if (x % pr == 0) {
                        if (x % (pr * pr) == 0) {
                            cur_mask = 0;
                            break;
                        }
                        cur_mask |= (1 << p);
                    }
                }
                if (cur_mask) {
                    if (!seen.contains(cur_mask)) {
                        seen.insert(cur_mask);
                        mask.push_back(cur_mask);
                    }
                    occs[cur_mask]++;
                }
            }
        }

        int m = mask.size();

        auto ans = y_combinator(
            [&](auto&& dfs, int cur_mask, int i, Z cnt) -> Z {
                if (i == m) {
                    return cur_mask ? cnt : 0;
                }
                Z res = dfs(cur_mask, i + 1, cnt);
                if ((cur_mask & mask[i]) == 0 && occs[mask[i]]) {
                    res += dfs(cur_mask | mask[i], i + 1, cnt * occs[mask[i]]);
                }
                return res;
            }
        )(0, 0, Z(1));

        ans *= power(Z(2), free);
        return ans.val();
    }
};

// ~ JustJie