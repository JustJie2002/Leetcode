/********************************************
 * author : Jie Chen (3rd Year CS)
 * school : Rochester Institute of Technology
 * created: 04.18.2024 20:48:13
*********************************************/

// http://www.open-std.org/jtc1/sc22/wg21/docs/papers/2016/p0200r0.html
template<class Fun> class y_combinator_result {
    Fun fun_;
public:
    template<class T> explicit y_combinator_result(T &&fun): fun_(std::forward<T>(fun)) {}
    template<class ...Args> decltype(auto) operator()(Args &&...args) { return fun_(std::ref(*this), std::forward<Args>(args)...); }
};
template<class Fun> decltype(auto) y_combinator(Fun &&fun) { return y_combinator_result<std::decay_t<Fun>>(std::forward<Fun>(fun)); }

using i64 = long long;

constexpr int d[] {-1, 0, 1, 0, -1};

class Solution {
public:
    int numIslands(vector<vector<char>>& mat) {
        int n = mat.size(), m = mat[0].size();

        auto dfs = y_combinator([&](auto&& dfs, int i, int j) -> void {
            mat[i][j] = '0';
            for (int k = 0; k < 4; k++) {
                int ni = i + d[k];
                int nj = j + d[k + 1];
                if (0 <= ni && ni < n && 0 <= nj && nj < m && mat[ni][nj] == '1') {
                    dfs(ni, nj);
                }
            }
        });

        int ans = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (mat[i][j] == '1') {
                    ans++;
                    dfs(i, j);
                }
            }
        }

        return ans;
    }
};

// ~ JustJie