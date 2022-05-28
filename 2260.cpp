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
    int minimumCardPickup(vector<int>& cards) {
        int n = sz(cards);
        unordered_map<int, int> last;
        int mn = INF;
        for (int i = 0; i < n; i++) {
            if (last.count(cards[i])) {
                ckmin(mn, i - last[cards[i]] + 1);
            }
            last[cards[i]] = i; 
        }
        return mn == INF ? -1 : mn;
    }
};