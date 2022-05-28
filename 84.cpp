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
    int largestRectangleArea(vector<int>& heights) {
        stack<pii> st;
        st.emplace(-1, 0);
        int n = sz(heights);
        int mx = -1;
        for (int i = 0; i < n; i++) {
            if (heights[i] < st.top().se) {
                while (st.top().se > heights[i]) {
                    auto bar = st.top();
                    st.pop();
                    ckmax(mx, bar.se * (i - st.top().fi - 1));
                }
            }
            st.emplace(i, heights[i]);
        }
        while (st.top().fi != -1) {
            auto bar = st.top();
            st.pop();
            ckmax(mx, bar.se * (n - st.top().fi - 1));
        }
        return mx;
    }
};