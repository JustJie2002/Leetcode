/********************************************
 * author : Jie Chen (3rd Year CS)
 * school : Rochester Institute of Technology
 * created: 05.11.2024 22:30:10
*********************************************/

using i64 = long long;
using Info = array<int, 2>;

constexpr int inf = 1e9 + 5;

pair<int, vector<int>> held_karp(const vector<vector<int>>& aa) {
    int n = aa.size();
    const int N = 1 << n;

    vector dp(N, vector<Info>(n));
    for (int msk = 0; msk < N; msk++) {
        for (int i = 0; i < n; i++) {
            dp[msk][i][1] = -1;
        }
    }

    for (int k = 1; k < n; ++k) {
        dp[1 << k][0] = {aa[0][k], 0};
    }

    for (int msk = 0; msk < N; msk++) {
        for (int a = 0; a < n; a++) if (msk & (1 << k)) {
            
        }
    }
    
    for (int subset_size = 2; subset_size < n; ++subset_size) {
        for (int subset = 0; subset < N; ++subset) {
            if (__builtin_popcount(subset) != subset_size) {
                continue;
            }
            
            for (int k = 0; k < n; ++k) if (subset & (1 << k)) {
                int pre = subset ^ (1 << k);

                for (int m = 0; m < n; ++m) {
                    if (m == 0 || m == k || dp[pre][m][1] != -1) {
                        continue;
                    }

                    int new_cost = dp[pre][m][0] + aa[m][k];
                    if (new_cost < dp[subset][k][0]) {
                        dp[subset][k] = {new_cost, m};
                    }
                }
            }
        }
    }
    
    int bits = (1 << n) - 1;
    pair<int, int> opt = {inf, -1};
    
    for (int k = 1; k < n; ++k) {
        if (dp[bits][k][1] != -1) {
            int new_cost = dp[bits][k][0] + aa[k][0];
            if (new_cost < opt.first) {
                opt = {new_cost, k};
            }
        }
    }
    
    vector<int> path;
    int parent = opt.second;
    
    for (int i = 0; i < n - 1; ++i) {
        path.push_back(parent);
        cout << parent << "\n";
        int new_bits = bits ^ (1 << parent);
        parent = dp[bits][parent][1];
        bits = new_bits;
    }
    path.push_back(0);
    reverse(path.begin(), path.end());
    return {opt.first, path};
}

class Solution {
public:
    vector<int> findPermutation(vector<int>& a) {
        int n = a.size();

        vector cost(n, vector<int>(n, inf));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (i != j) {
                    cost[i][j] = abs(i - a[j]);
                }
            }
        }
        auto [_, ass] = held_karp(cost);
        return ass;
    }
};

// ~ JustJie