/********************************************
 * author : Jie Chen (3rd Year CS)
 * school : Rochester Institute of Technology
 * created: 04.15.2024 21:54:03
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
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        if (depth == 1) {
            TreeNode* new_root = new TreeNode(val, root, NULL);
            return new_root;
        }

        y_combinator([&](auto&& dfs, TreeNode* tr, int dep) -> void {
            if (tr == NULL) {
                return;
            }
            if (dep == depth - 1) {
                tr->left = new TreeNode(val, tr->left, NULL);
                tr->right = new TreeNode(val, NULL, tr->right);
                return;
            }
            for (auto nxt : {tr->left, tr->right}) {
                dfs(nxt, dep + 1);
            }
        })(root, 1);
        return root;
    }
};

// ~ JustJie