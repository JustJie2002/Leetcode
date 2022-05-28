#include "bits/stdc++.h"

using namespace std;

#ifdef DEBUG
#include "debug.h"
#else
#define debug(...) "AiNi BaoBei"
#endif

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
using vb = vector<bool>;
template <typename A, typename B> using wgraph = vector<vector<pair<A, B>>>;
template <typename T> using graph = vector<vector<T>>;

mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
int randint(int p) { return (unsigned int)rng() % p; }
ll randi64(ll p) { return (unsigned ll)rng() % p; }

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
#define read(a) Each(x, a) cin >> x

constexpr int inf = 1E9;
constexpr ll INF = 1E18;
constexpr int mod = 1000000007; // 998244353
const ld pi = acos((ld)-1);
const char nl = '\n';

void write(bool result, string end = "\n") { cout << (result ? "YES" : "NO") << end; }
template <typename T> void print(T statement, string end = "") { cout << statement << end; }
template <typename T> void println(T statement, bool flush = false) { cout << statement; if (flush) cout << endl; else cout << "\n"; }
template <typename T> bool ckmax(T &a, T b) { return a < b ? a = b, true : false; }
template <typename T> bool ckmin(T &a, T b) { return a > b ? a = b, true : false; }

/* stuff you should look for 
	* check for int overflow
	* check for time complexity (make sure not to TLE)
	* special case (n = 1)
	* make sure to initialize everything (array)
	* don't be lazy, write out your thought and code it out
*/

struct Info {
    int available, seat, idx;
};

typedef multiset<Info> mi;

mi combine(mi a, mi b) {
    mi c;
    set_union(all(a), all(b), inserter(c, c.begin()));
    return c;
}


struct Node {
    int sum;
    mi m;
};

Node Merge(Node a, Node b) {
    return {
        a.sum + b.sum,
        combine(a.m, b.m)
    };
}

struct SegTree {
private:
    typedef Node T;
    const T base; // define base
    int n;
    vector<T> s;
    T f(T a, T b) { return combine(a, b); }

public:
    SegTree(int _n = 0) : n(_n) {
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

int main() 
{
    ios::sync_with_stdio(false), cin.tie(nullptr);


}