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
typedef __int128 i128;
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
#define Read(a) Each(x, a) cin >> x

constexpr int inf = 1E9 + 5;
constexpr ll INF = 1E18;
constexpr int mod = 1000000007; // 998244353
const ld pi = acos((ld)-1);
const char nl = '\n';
const double EPS = 1E-6;

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

class Solution {
public:
    bool matchReplacement(string s, string sub, vector<vector<char>>& mappings) {
        int n = sz(s), m = sz(sub);
        vector<vector<bool>> dp(n, vb(m, false));
        map<char, set<char>> conversion;
        Each(w, mappings) conversion[w[0]].ins(w[1]);
        set<int> ss;
        ss.ins(sub[0]);
        Each(x, conversion[sub[0]]) ss.ins(x);
        for (int i = 0; i < n - m; i++) {
            dp[i][0] = ss.find(s[i]) != ss.end();
            if (!dp[i][0]) continue;
            debug(i);
            for (int j = 1; j < m; j++) {
                dp[i + j][j] = dp[i + j - 1][j - 1];
                bool same = s[i + j] == sub[j];
                Each(x, conversion[sub[j]]) same |= (x == s[i + j]);
                cout << s[i + j] << " " << sub[j] << " " << same << nl;
                dp[i + j][j] = dp[i + j][j] && same;
            }
        }
        bool good = false;
        for (int i = 0; i < n; i++) good |= dp[i][m - 1];
        return good;
    }
};

int main() 
{
    ios::sync_with_stdio(false), cin.tie(nullptr);
    
    string s = "fool3e7bar";
    string sub = "leet";
    vector<vector<char>> mappings = {{'e', '3'}, {'t', '7'}, {'t', '8'}};
    Solution Solution;
    write(Solution.matchReplacement(s, sub, mappings));
}