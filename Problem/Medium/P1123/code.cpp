/********************************************
 * author : Jie Chen (3rd Year CS)
 * school : Rochester Institute of Technology
 * created: 04.04.2024 15:22:15
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
using Info = array<int, 2>;

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
    TreeNode* lcaDeepestLeaves(TreeNode* root) {
        int max_depth = 0;
        int res = 0;
        TreeNode* ans;
        y_combinator([&](auto&& dfs, TreeNode* node, int dep) -> Info {
            if (node == NULL) {
                return {0, -1};
            }
            if (dep > max_depth) {
                max_depth = dep;
                res = 0;
            }
            int l = 0;
            auto a = dfs(node->left, dep + 1);
            auto b = dfs(node->right, dep + 1);
            if (dep == max_depth) {
                l++;
            }
            l += (a[1] == max_depth ? a[0] : 0);
            l += (b[1] == max_depth ? b[0] : 0);
            if (l > res) {
                res = l;
                ans = node;
            }
            int cur_max = max({dep, a[1], b[1]});
            return {l, cur_max};
        })(root, 0);

        return ans;
    }
};

// ~ JustJie