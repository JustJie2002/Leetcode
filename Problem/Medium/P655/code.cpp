/********************************************
 * author : Jie Chen (3rd Year CS)
 * school : Rochester Institute of Technology
 * created: 05.08.2024 23:26:37
*********************************************/

template<class Fun> class y_combinator_result {
    Fun fun_;
public:
    template<class T> explicit y_combinator_result(T &&fun): fun_(std::forward<T>(fun)) {}
    template<class ...Args> decltype(auto) operator()(Args &&...args) { return fun_(std::ref(*this), std::forward<Args>(args)...); }
};
template<class Fun> decltype(auto) y_combinator(Fun &&fun) { return y_combinator_result<std::decay_t<Fun>>(std::forward<Fun>(fun)); }

using i64 = long long;

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<vector<string>> printTree(TreeNode* root) {
        int height = y_combinator(
            [&](auto&& dfs, TreeNode* rt) -> int {
                if (rt == nullptr) {
                    return -1;
                }
                return 1 + max(dfs(rt->left), dfs(rt->right));
            }
        )(root);

        vector<int> pow2(height + 2);
        pow2[0] = 1;
        for (int i = 0; i < height + 1; i++) {
            pow2[i + 1] = pow2[i] * 2;
        }

        int n = pow2[height + 1] - 1;
        vector res(height + 1, vector<string>(n));

        y_combinator(
            [&](auto&& grow, TreeNode* rt, int r, int c) -> void {
                if (rt == nullptr) {
                    return;
                }
                res[r][c] = to_string(rt->val);
                if (rt->left) {
                    grow(rt->left, r + 1, c - pow2[height - r - 1]);
                }
                if (rt->right) {
                    grow(rt->right, r + 1, c + pow2[height - r - 1]);
                }
            }
        )(root, 0, (n - 1) / 2);

        return res;
    }
};

// ~ JustJie