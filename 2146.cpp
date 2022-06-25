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
using vb = vector<bool>;
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
    int dist, price, row, col;
    
    node(int d, int p, int r, int c) : 
        dist(d), price(p), row(r), col(c) {}
    
    node() {}
    
    bool operator > (const node& other) const {
        if (dist != other.dist) return dist < other.dist;
        if (price != other.price) return price < other.price;
        if (row != other.row) return row < other.row;
        return col < other.col;
    }
};

const int d4i[] = {-1, 0, 1, 0};
const int d4j[] = {0, -1, 0, 1};

class Solution {
public:
    vvi highestRankedKItems(vvi& grid, vi& pricing, vi& start, int k) {
        priority_queue<node, vector<node>, greater<node>> heap;
        int n = sz(grid), m = sz(grid[0]);
        vector vis(n, vb(m, false));
        vector dist(n, vi(m, 0));
        queue<pii> Q;
        Q.emplace(start[0], start[1]);
        vis[start[0]][start[1]] = true;
        auto walkable = [&](int i, int j) {
            return 0 <= i && i < n && 0 <= j && j < m && !vis[i][j] && grid[i][j] != 0;
        };
        while (!Q.empty()) {
            auto [i, j] = Q.front(); Q.pop();
            
            if (grid[i][j] >= pricing[0] && grid[i][j] <= pricing[1]) 
                heap.emplace(dist[i][j], grid[i][j], i, j);
            
            for (int x = 0; x < 4; x++) {
                int ni = i + d4i[x];
                int nj = j + d4j[x];
                if (walkable(ni, nj)) {
                    vis[ni][nj] = true;
                    dist[ni][nj] = dist[i][j] + 1;
                    Q.emplace(ni, nj);
                }
            }
        }
        vvi coords;
        while (!heap.empty() && k--) {
            auto Info = heap.top(); heap.pop();
            coords.pb({Info.row, Info.col});
        }
        return coords;
    }
};