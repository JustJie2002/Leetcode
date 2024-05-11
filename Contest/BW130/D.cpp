/********************************************
 * author : Jie Chen (3rd Year CS)
 * school : Rochester Institute of Technology
 * created: 05.11.2024 10:26:52
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
 
constexpr int P = 0;
using Z = MInt<P>;

constexpr i64 INF = 1e16 + 10;
constexpr int B = 62;

class Solution {
public:
    vector<int> findProductsOfElements(vector<vector<long long>>& queries) {
        int qs = queries.size();

        auto count2 = [&](i64 x, int b) {
            i64 res = x >> (b + 1);
            i64 rem = x & ((1LL << (b + 1)) - 1);
            i64 ans = res * (1LL << b);
            ans += max(0LL, rem - (1LL << b) + 1);
            return ans;
        };

        auto count = [&](i64 x) {
            i64 sum = 0;
            i64 cnt = 0;
            for (int b = 0; b < B; b++) {
                i64 cnt2 = count2(x, b);
                cnt += cnt2;
                sum += cnt2 * b;
            }
            return pair(cnt, sum);
        };

        auto go = [&](i64 x, int over) {
            int ans = 0;
            for (int b = 0; b < B && over; b++) {
                if (x >> b & 1) {
                    ans += b;
                    over--;
                }
            }
            return ans;
        };

        auto work = [&](i64 x) {
            i64 lo = 0, hi = INF, mid;
            while (lo < hi) {
                mid = (lo + hi + 1) / 2;
                if (count(mid).first <= x) {
                    lo = mid;
                } else {
                    hi = mid - 1;
                }
            }
            auto [cnt, sum] = count(lo);
            int over = x - cnt;
            return sum + go(lo + 1, over);
        };

        vector<int> ans(qs);
        for (int q = 0; q < qs; q++) {
            i64 a = queries[q][0];
            i64 b = queries[q][1] + 1;
            int mod = queries[q][2];
            Z::setMod(mod);
            i64 tot = work(b) - work(a);
            ans[q] = power(Z(2), tot).val();
        }
        return ans;
    }
};

// ~ JustJie