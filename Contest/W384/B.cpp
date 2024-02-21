/********************************************
 * author : Jie Chen (3rd Year CS)
 * school : Rochester Institute of Technology
 * created: 02.10.2024 21:44:45
*********************************************/

using i64 = long long;

constexpr int INF = int(1e9) + 5;

vector<int> z_function(const auto& iterable) {
    int n = iterable.size();
    vector<int> z(n);
    int l = -1, r = -1;
    for (int i = 1; i < n; i++) {
        z[i] = (i >= r ? 0 : min(r - i, z[i - l]));
        while (i + z[i] < n && iterable[i + z[i]] == iterable[z[i]]) {
            z[i]++;
        }
        if (i + z[i] > r) {
            l = i;
            r = i + z[i];
        }
    }
    z[0] = n
    return z;
}

class Solution {
public:
    int countMatchingSubarrays(vector<int>& a, vector<int>& pat) {
        int n = a.size(), m = pat.size();
        pat.push_back(INF);

        for (int i = 0; i < n - 1; i++) {
            if (a[i] == a[i + 1]) {
                pat.push_back(0);
            } else if (a[i] > a[i + 1]) {
                pat.push_back(-1);
            } else {
                pat.push_back(1);
            }
        }

        auto z = z_function(pat);
        int ans = 0;
        for (int i = m + 1; i < n + m; i++) {
            if (z[i] == m) {
                ans++;
            }
        }

        return ans;
    }
};

// ~ JustJie