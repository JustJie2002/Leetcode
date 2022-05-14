using i64 = long long;
using pii = pair<int, int>;

#define pb push_back
#define mp make_pair
#define ins insert
#define fi first
#define se second
#define all(v) (v).begin(), (v).end()
#define rall(v) (v).rbegin(), (v).rend()
#define sz(a) int(a.size())

template <typename T> bool ckmax(T &a, T b) { return a < b ? a = b, true : false; }
template <typename T> bool ckmin(T &a, T b) { return a > b ? a = b, true : false; }

constexpr int INF = 1E9;

class Solution {
public:

    int findMinFibonacciNumbers(int N) {
        vector<int> ch;
        priority_queue<int> q;
        unordered_map<int, int> m;
        int a = 0, b = 1;
        while (b <= N) {
            int p = b;
            ch.pb(b);
            q.push(b);
            m[b] = 1;
            b += a;
            a = p;
        }
        while (!q.empty()) {
            int u = q.top(); q.pop();
            
            if (u == N) return m[u];
            
            for (int& x : ch) {
                int sum = x + u;
                if (sum > N) break;
                if (!m.count(sum) || ckmin(m[sum], m[u] + 1)) {
                    q.push(sum);
                    m[sum] = m[u] + 1;
                }
            }
        }
        assert(false);
    }
};