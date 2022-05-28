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
    int maximumWhiteTiles(vector<vector<int>>& tiles, int k) {
        sort(all(tiles));
        vector<pii> w;
        pii pr = mp(-1, -1);
        // touching carpets?
        // merging touching carpets
        for (const auto& tile : tiles) {
            int left = tile[0], right = tile[1];
            if (pr.fi == -1)
                pr = mp(left, right);
            else if (left - 1 == pr.se)
                pr.se = right;
            else {
                w.pb(pr);
                pr = mp(left, right);
            }
        }
        w.pb(pr);
        int n = sz(w);
        int best = 0;
        // sliding window
        int cover = 0, bad = 0;
        for (int i = 0, j = 0; i < n; i++) {
            // printf("%d %d %d %d\n", i, j, cover, bad);
            while (j < n && k > cover + bad) {
                int cur = w[i].fi + cover + bad;
                int l = k - (cover + bad);
                if (cur >= w[j].fi) {
                    // printf("here %d\n", l);
                    assert(l > 0);
                    int remain = w[j].se - w[j].fi + 1 - (cur - w[j].fi);
                    int most_cover = min(remain, l);
                    // printf("most cover: %d\n", most_cover);
                    cover += most_cover;
                    if (cover + bad == k) break;
                    l -= most_cover;
                    assert(l > 0);
                    if (j < n - 1) {
                        int dist = w[j + 1].fi - w[j].se - 1;
                        if (cover + dist >= k) {
                            break;
                        }
                        bad += dist;
                    }
                } else {
                    // go over 
                    int dist = w[j].fi - w[j - 1].se - 1;
                    bad += dist;
                    if (cover + bad >= k) {
                        j++;
                        break;
                    }
                    l -= dist;
                    int most_cover = min(l, w[j].se - w[j].fi + 1);
                    cover += most_cover;
                }
                j++;
            }
            ckmax(best, cover);
            // printf("%d %d %d %d\n", i, j, cover, bad);
            if (i < j && i != n - 1) {
                bad -= (w[i + 1].fi - w[i].se - 1);
                cover -= (w[i].se - w[i].fi + 1);
            } else {
                cover = 0;
                assert(bad == 0);
                j++;
            }
        }
        ckmax(cover, best);
        return best;
    }
};