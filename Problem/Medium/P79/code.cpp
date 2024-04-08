/********************************************
 * author : Jie Chen (3rd Year CS)
 * school : Rochester Institute of Technology
 * created: 04.02.2024 22:11:13
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

constexpr int di[] {-1, 0, 1, 0};
constexpr int dj[] {0, -1, 0, 1};

class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        int n = board.size(), m = board[0].size();
        int w = word.length();

        vector used(n, vector<int>(m));

        auto good = [&](int i, int j) {
            return 0 <= i && i < n && 0 <= j && j < m;
        };

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (board[i][j] == word[0]) {
                    auto res = y_combinator([&](auto&& dfs, int i, int j, int k) -> bool {
                        if (k == w) {
                            return true;
                        }
                        used[i][j] = 1;
                        for (int d = 0; d < 4; d++) {
                            int ni = i + di[d];
                            int nj = j + dj[d];
                            if (good(ni, nj) && board[ni][nj] == word[k] && !used[ni][nj]) {
                                if (dfs(ni, nj, k + 1)) {
                                    return true;
                                }
                                used[ni][nj] = 0;
                            }
                        }
                        used[i][j] = 0;
                        return false;
                    })(i, j, 1);
                    if (res) {
                        return true;
                    }
                }
            }
        }

        return false;
    }
};

// ~ JustJie