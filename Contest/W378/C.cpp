/********************************************
 * author : Jie Chen (3rd Year CS)
 * school : Rochester Institute of Technology
 * created: 12.30.2023 21:31:32
*********************************************/

using i64 = long long;
using Pair = pair<char, int>;

vector<Pair> groupby(string s) {
    s += '$';
    char u = s[0];
    int cnt = 0;
    vector<Pair> res;
    for (char c : s) {
        if (c == u) {
            cnt++;
        } else {
            res.emplace_back(u, cnt);
            u = c;
            cnt = 1;
        }
    }
    return res;
}

class Solution {
public:
    int maximumLength(string s) {
        auto g = groupby(s);

        vector<vector<int>> f(26);
        for (const auto& [c, cnt] : g) {
            f[c - 'a'].push_back(cnt);
        }

        int ans = -1;
        for (int a = 0; a < 26; a++) {
            const auto& ff = f[a];
            if (ff.empty()) {
                continue;
            }
            if (ff.size() == 1 && ff[0] <= 2) {
                continue;
            }
            if (ff.size() == 2 && ff[0] + ff[1] == 2) {
                continue;
            }
            int lo = 1, hi = *max_element(ff.begin(), ff.end());
            while (lo < hi) {
                int mid = (lo + hi + 1) / 2;
                int res = 0;
                for (int x : ff) {
                    res += max(0, x - mid + 1);
                }
                if (res >= 3) {
                    lo = mid;
                } else {
                    hi = mid - 1;
                }
            }
            // printf("%d %d %d\n", a, lo, hi);
            ans = max(ans, lo);
        }

        return ans;
    }
};

// ~ JustJie