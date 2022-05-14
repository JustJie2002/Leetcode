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

class Solution {
public:
    vector<int> memLeak(int memory1, int memory2) {
        int i = 1;
        while (true) {
            if (memory1 >= memory2) {
                if (memory1 < i) break;
                memory1 -= i;
            } else {
                if (memory2 < i) break;
                memory2 -= i;
            }
            i++;
        }
        return {i, memory1, memory2};
    }
};