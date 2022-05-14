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
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        sort(all(nums));
        set<vector<int>> s;
        do {
            s.ins(nums);
        } while (next_permutation(all(nums)));
        return vector<vector<int>>(all(s));
    }
};