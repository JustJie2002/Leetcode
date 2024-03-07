/********************************************
 * author : Jie Chen (3rd Year CS)
 * school : Rochester Institute of Technology
 * created: 03.06.2024 17:19:40
*********************************************/

using i64 = long long;
using Edge = pair<int, int>;
using Info = pair<i64, int>;

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

constexpr i64 INF = 1e18 + 10;

class Solution {
public:
    int countPaths(int n, vector<vector<int>>& edges) {
        if (n == 1) {
            return 1;
        }

        vector<vector<Edge>> adj(n);
        for (const auto& edge : edges) {
            int u = edge[0], v = edge[1], w = edge[2];
            adj[u].emplace_back(v, w);
            adj[v].emplace_back(u, w);
        }

        // dijkstra
        priority_queue<Info, vector<Info>, greater<Info>> pq;
        vector<i64> dis(n, INF);
        
        auto add = [&](int cur, i64 dist) {
            if (dis[cur] > dist) {
                dis[cur] = dist;
                pq.emplace(dist, cur);
            }
        };

        add(0, 0);
        vector<int> ord;
        while (!pq.empty()) {
            auto [d, cur] = pq.top(); pq.pop();

            if (dis[cur] != d) {
                continue;
            }

            ord.push_back(cur);

            if (cur == n - 1) {
                break;
            }

            for (auto& [nei, w] : adj[cur]) {
                add(nei, w + d);
            }
        }

        int m = ord.size();

        vector<Z> dp(n);
        dp[0] = 1;
        for (int i = 1; i < m; i++) {
            int cur = ord[i];

            for (auto& [nei, w] : adj[cur]) {
                if (dis[nei] + w == dis[cur]) {
                    dp[cur] += dp[nei];
                }
            }

            if (cur == n - 1) {
                break;
            }
        }

        return dp[n - 1].val();
    }
};

// ~ JustJie