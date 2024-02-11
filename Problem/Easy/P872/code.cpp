/********************************************
 * author : Jie Chen (3rd Year CS)
 * school : Rochester Institute of Technology
 * created: 01.09.2024 14:42:02
*********************************************/

using i64 = long long;

// http://www.open-std.org/jtc1/sc22/wg21/docs/papers/2016/p0200r0.html
template<class Fun> class y_combinator_result {
    Fun fun_;
public:
    template<class T> explicit y_combinator_result(T &&fun): fun_(std::forward<T>(fun)) {}
    template<class ...Args> decltype(auto) operator()(Args &&...args) { return fun_(std::ref(*this), std::forward<Args>(args)...); }
};
template<class Fun> decltype(auto) y_combinator(Fun &&fun) { return y_combinator_result<std::decay_t<Fun>>(std::forward<Fun>(fun)); }

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
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {

        auto solve = [&](TreeNode* root) {
            vector<int> ord;
            y_combinator([&](auto&& dfs, TreeNode* node) -> void {
                if (node->left) {
                    dfs(node->left);
                }
                if (node->right) {
                    dfs(node->right);
                }
                if (node->left == NULL && node->right == NULL) {
                    ord.push_back(node->val);
                }
            })(root);
            return ord;
        };

        auto ord1 = solve(root1);
        auto ord2 = solve(root2);
        return ord1 == ord2;
    }

};

// ~ JustJie