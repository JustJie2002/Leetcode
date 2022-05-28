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

template<typename T_vector>
void output_vector(const T_vector &v, bool add_one = false, int start = -1, int end = -1) {
    if (start < 0) start = 0;
    if (end < 0) end = int(v.size());

    for (int i = start; i < end; i++) {
        cout << v[i] + (add_one ? 1 : 0) << " \n"[i == end - 1];
    }
}

class Solution {
private:
    bool check(const vector<int>& w) {
        int n = sz(w);
        for (int i = 0; i < n; i++) {
            if (w[i] != i) return false;
        }
        return true;
    }

public:
    int reinitializePermutation(int n) {
        vector<int> perm(n);
        for (int i = 0; i < n; i++) perm[i] = i;
        int ans = 0;
        do {
            vector<int> a(n);
            for (int i = 0; i < n; i++) {
                if (i & 1)
                    a[i] = perm[n / 2 + (i - 1) / 2];
                else
                    a[i] = perm[i / 2];
            }
            perm.swap(a);
            ans++;
        } while (!check(perm));
        return ans;
    }
};