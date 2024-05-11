/********************************************
 * author : Jie Chen (3rd Year CS)
 * school : Rochester Institute of Technology
 * created: 05.04.2024 22:30:11
*********************************************/

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

constexpr i64 inf = 1e18 + 10;

class Solution {
public:
    int minCostToEqualizeArray(vector<int>& a, int c1, int c2) {
        int n = a.size();
        int v = *max_element(a.begin(), a.end());

        vector<i64> d;
        d.reserve(n);
        i64 tot = 0;
        for (int x : a) {
            i64 dif = v - x;
            d.push_back(dif);
            tot += dif;
        }

        while (!d.empty() && d.back() == 0) {
            d.pop_back();
        }

        if (d.empty()) {
            return 0;
        }

        Z ans = 0;
        if (2 * c1 <= c2) {
            ans += tot * c1;
        } else {
            i64 ma = d[0];
            if (n == 2) {
                ans += ma * c1;
                return ans.val();
            }
            i64 rem = tot - ma;
            if (ma > rem) {
                ma -= rem;
                ans += rem * c2;
                i64 res = 1LL * ma * c1;
                i64 ret = 0;
                while (ma >= n - 2) {
                    ret += 1LL * (n - 1) * c2;
                    ma -= (n - 2);
                }
                i64 rest = n - ma;
                res = min({
                    res,
                    ret + ma * c1,
                    ret + 1LL * c2 * ma + 1LL * rest / 2 * c2 + 
                    (rest % 2 == 0 ? 0 : (n % 2 == 0 ? c1 : min<i64>(c1, 1LL * (n + 1) / 2 * c2)))
                });
                ans += res;
            } else {
                ans += c2 * (tot / 2);
                if (tot & 1) {
                    ans += min<i64>(c1, (n % 2 == 0 ? c1 : min<i64>(c1, 1LL * (n + 1) / 2 * c2)));
                }
            }
        }
        return ans.val();
    }
};

// ~ JustJie