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

#define pb push_back
#define eb emplace_back
#define ins insert
#define fi first
#define se second
#define all(v) (v).begin(), (v).end()
#define rall(v) (v).rbegin(), (v).rend()
#define rev(a) std::reverse(all(a))
#define sz(a) int(a.size())
#define each(x, a) for (auto& x : a)

// credit: William Lin
#define FOR(i, a, b, s) for (int i = (a); (s) > 0 ? i < (b) : i > (b); i += (s))
#define FOR1(e) FOR(_, 0, e, 1)
#define FOR2(i, e) FOR(i, 0, e, 1)
#define FOR3(i, b, e) FOR(i, b, e, 1)
#define FOR4(i, b, e, s) FOR(i, b, e, s)
#define GET5(a, b, c, d, e, ...) e
#define FORC(...) GET5(__VA_ARGS__, FOR4, FOR3, FOR2, FOR1)
#define loop(...) FORC(__VA_ARGS__)(__VA_ARGS__)

constexpr int inf = 1E9 + 5;
constexpr ll INF = 1E18;
constexpr int mod = 1000000007; // 998244353
const ld pi = acos((ld)-1);
const double EPS = 1E-6;

/* stuff you should look for
	* check for int overflow
	* check for time complexity (make sure not to TLE)
	* special case (n = 1)
	* make sure to initialize everything (array)
	* don't be lazy, write out your thought and code it out
*/

class Solution {
public:
    int rangeBitwiseAnd(int left, int right) {
        if (left == right) return left;
        int mask = 0;
        loop(i, 1, 30) {
            int p = i - 1;
            if (left >= (1 << p) && right < (1 << i)) {
                mask |= (1 << p);
            }
        }
        return mask;
    }
};
