/********************************************
 * author : Jie Chen (3rd Year CS)
 * school : Rochester Institute of Technology
 * created: 03.04.2024 18:35:43
*********************************************/

using i64 = long long;

template<class T> constexpr T power(T a, i64 b) {
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
template<int P> struct MInt {
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
int MInt<0>::Mod = 998244353;
 
template<int V, int P>
constexpr MInt<P> CInv = MInt<P>(V).inv();
 
constexpr int P = 1'000'000'007; // 998244353;
using Z = MInt<P>;

template <typename T> struct Matrix {
    int n;
    vector<vector<T>> mat;
    Matrix(int _n): n(_n), mat(n, vector<T>(n)) {}

    // set
    vector<T>& operator[](int row) {
        assert(0 <= row && row < n);
        return mat[row];
    }
    T& operator() (int row, int col) {
        assert(0 <= row && row < n);
        assert(0 <= col && col < n);
        return mat[row][col];
    }

    // get
    vector<T> operator[](int row) const {
        assert(0 <= row && row < n);
        return mat[row];
    }
    T operator() (int row, int col) const {
        assert(0 <= row && row < n);
        assert(0 <= col && col < n);
        return mat[row][col];
    }

    Matrix operator*(const Matrix& o) {
        assert(n == o.n);
        Matrix res(n);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                for (int k = 0; k < n; k++) {
                    res[i][k] += mat[i][j] * o[j][k];
                }
            }
        }
        return res;
    }

    constexpr Matrix& operator*=(const Matrix& rhs) & {
        mat = (*this * rhs).mat;
        return *this;
    }

    Matrix pow(i64 b) {
        auto a = *this;
        Matrix<T> res(n);
        for (int i = 0; i < n; i++) {
            res[i][i] = 1;
        }
        for (; b; b /= 2, a *= a) {
            if (b % 2) {
                res *= a;
            }
        }
        return res;
    }

    void debug() {
        cout << "DEBUGGING:\n";
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cout << mat[i][j] << " \n"[j == n - 1];
            }
        }
        cout << "END\n";
    }
};

vector<int> z_function(const auto& iterable) {
    int n = iterable.size();
    vector<int> z(n);
    int l = -1, r = -1;
    for (int i = 1; i < n; i++) {
        z[i] = (i >= r ? 0 : min(r - i, z[i - l]));
        while (i + z[i] < n && iterable[i + z[i]] == iterable[z[i]]) {
            z[i]++;
        }
        if (i + z[i] > r) {
            l = i;
            r = i + z[i];
        }
    }
    z[0] = n;
    return z;
}

class Solution {
public:
    int numberOfWays(string s, string t, long long k) {
        int n = s.length(), m = t.length();

        auto cyc = t + "$" + s + s;
        int sz = cyc.length();
        auto z = z_function(cyc);

        int good = 0;
        for (int i = m + 1; i < sz; i++) {
            if (z[i] == n) {
                good++;
            }
        }

        if (s == t) {
            good--;
        }
        int bad = n - good;

        Matrix<Z> mat(2);
        mat[0][0] = good - 1;
        mat[1][0] = good;
        mat[0][1] = bad;
        mat[1][1] = bad - 1;

        auto res = mat.pow(k);

        vector<int> dp(2);
        dp[0] = int(s == t);
        dp[1] = 1 - dp[0];

        vector<Z> ndp(2);
        for (int i = 0; i < 2; i++) {
            for (int j = 0; j < 2; j++) {
                ndp[j] += dp[i] * res[i][j];
            }
        }

        return ndp[0].val();
    }
};

// ~ JustJie