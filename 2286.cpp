template <typename A, typename B>
string to_string(pair<A, B> p);
 
template <typename A, typename B, typename C>
string to_string(tuple<A, B, C> p);
 
template <typename A, typename B, typename C, typename D>
string to_string(tuple<A, B, C, D> p);
 
string to_string(const string& s) {
    return '"' + s + '"';
}
 
string to_string(const char* s) {
    return to_string((string) s);
}
 
string to_string(bool b) {
    return (b ? "true" : "false");
}
 
string to_string(vector<bool> v) {
    bool first = true;
    string res = "{";
    for (int i = 0; i < static_cast<int>(v.size()); i++) {
        if (!first) {
            res += ", ";
        }
        first = false;
        res += to_string(v[i]);
    }
    res += "}";
    return res;
}
 
template <size_t N>
string to_string(bitset<N> v) {
    string res = "";
    for (size_t i = 0; i < N; i++) {
        res += static_cast<char>('0' + v[i]);
    }
    return res;
}
 
template <typename A>
string to_string(A v) {
    bool first = true;
    string res = "{";
    for (const auto &x : v) {
        if (!first) {
            res += ", ";
        }
        first = false;
        res += to_string(x);
    }
    res += "}";
    return res;
}
 
template <typename A, typename B>
string to_string(pair<A, B> p) {
    return "(" + to_string(p.first) + ", " + to_string(p.second) + ")";
}
 
template <typename A, typename B, typename C>
string to_string(tuple<A, B, C> p) {
    return "(" + to_string(get<0>(p)) + ", " + to_string(get<1>(p)) + ", " + to_string(get<2>(p)) + ")";
}
 
template <typename A, typename B, typename C, typename D>
string to_string(tuple<A, B, C, D> p) {
    return "(" + to_string(get<0>(p)) + ", " + to_string(get<1>(p)) + ", " + to_string(get<2>(p)) + ", " + to_string(get<3>(p)) + ")";
}
 
void debug_out() { cout << endl; }
 
template <typename Head, typename... Tail>
void debug_out(Head H, Tail... T) {
    cout << " " << to_string(H);
    debug_out(T...);
}

#define debug(...) cout << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)

typedef long long ll;
typedef double db;
typedef pair<int, int> pii;
typedef pair<ll, int> pli;
typedef pair<ll, ll> pll;
typedef long double ld;
using vi = vector<int>;
using vvi = vector<vi>;
using vs = vector<string>;
using vpi = vector<pii>;
using vl = vector<ll>;
template <typename A, typename B> using wgraph = vector<vector<pair<A, B>>>;
template <typename T> using graph = vector<vector<T>>;

#define pb push_back
#define mp make_pair
#define eb emplace_back
#define ins insert
#define fi first
#define se second
#define all(v) (v).begin(), (v).end()
#define rall(v) (v).rbegin(), (v).rend()
#define sz(a) int(a.size())
#define Each(x, a) for (auto& x : a)

constexpr int inf = 1E9;
constexpr ll INF = 1E18;
constexpr int mod = 1000000007; // 998244353
const ld pi = acos((ld)-1);

template <typename T> bool ckmax(T &a, T b) { return a < b ? a = b, true : false; }
template <typename T> bool ckmin(T &a, T b) { return a > b ? a = b, true : false; }

/* stuff you should look for 
	* check for int overflow
	* check for time complexity (make sure not to TLE)
	* special case (n = 1)
	* make sure to initialize everything (array)
	* don't be lazy, write out your thought and code it out
*/

struct node {
    ll sum; 
    int maxv;
};

node combine(node a, node b) {
    return {
        a.sum + b.sum,
        max(a.maxv, b.maxv)
    };
}

typedef node T;
struct SegTree {
private:
    const T base{0, 0}; // define base
    int n;
    vector<T> s;
    T f(T a, T b) { return combine(a, b); }

public:
    SegTree(int _n) : n(_n) {
        s.resize(2 * n, base);
    }
    
    void update(int pos, T val) {
        for (s[pos += n] = val; pos >>= 1;)
            s[pos] = f(s[pos << 1], s[(pos << 1) + 1]);
    }
    
    T query(int b, int e) {
        ++e;
        T ra = base, rb = base;
        for (b += n, e += n; b < e; b >>= 1, e >>= 1) {
            if (b & 1) ra = f(ra, s[b++]);
            if (e & 1) rb = f(s[--e], rb);
        }
        return f(ra, rb);
    }
};

class BookMyShow {
    SegTree seg;
    int n, m;
    int l = 0;
public:
    BookMyShow(int n, int _m) : n(n), m(_m), seg(n) {
        for (int i = 0; i < n; i++) seg.update(i, {m, m});
    }
    
    vector<int> gather(int k, int maxRow) {
        int lo = l, hi = maxRow, ans = -1;
        while (lo <= hi) {
            int mid = lo + (hi - lo) / 2;
            T info = seg.query(lo, mid);
            if (info.maxv >= k) {
                hi = mid - 1;
                ans = mid;
            } else {
                lo = mid + 1;
            }
        }
        if (ans == -1)
            return {};
        T info = seg.query(ans, ans);
        seg.update(ans, {info.sum - k, info.maxv - k});
        int nsum = m - info.sum;
        return {ans, nsum};
    }
    
    bool scatter(ll k, int maxRow) {
        int lo = l, hi = maxRow, ans = -1;
        while (lo <= hi) {
            int mid = lo + (hi - lo) / 2;
            T info = seg.query(0, mid);
            if (info.sum >= k) {
                hi = mid - 1;
                ans = mid;
            } else {
                lo = mid + 1;
            }
        }
        if (ans == -1)
            return false;
        for (int i = l; i <= ans && k; i++) {
            T info = seg.query(i, i);
            int need = min(k, info.sum);
            seg.update(i, {info.sum - need, info.maxv - need});
            if (info.sum - need == 0) ++l;
            k -= need;
        }
        return true;
    }
};

/**
 * Your BookMyShow object will be instantiated and called as such:
 * BookMyShow* obj = new BookMyShow(n, m);
 * vector<int> param_1 = obj->gather(k,maxRow);
 * bool param_2 = obj->scatter(k,maxRow);
 */