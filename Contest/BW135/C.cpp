/********************************************
 * author : Jie Chen (4th Year CS)
 * school : Rochester Institute of Technology
 * created: 07.20.2024 10:38:17
*********************************************/

using i64 = long long;

class Solution {
public:
    int minChanges(vector<int>& a, int k) {
        int n = a.size();

        const auto get = [&](int x) -> int {
            return max(x, k - x);
        };

        map<int, int> dif;
        vector<int> use;
        for (int i = 0; i < n / 2; i++) {
            int v = abs(a[i] - a[n - i - 1]);
            dif[v]++;
            use.push_back(max(get(a[i]), get(a[n - i - 1])));
        }

        ranges::sort(use);

        int ans = n;
        for (const auto &[x, v] : dif) {
            int res = n / 2 - v + int(lower_bound(use.begin(), use.end(), x) - use.begin());
            ans = min(ans, res);
        }

        return ans;
    }
};

// ~ JustJie