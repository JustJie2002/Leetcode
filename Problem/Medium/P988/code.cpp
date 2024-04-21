/********************************************
 * author : Jie Chen (3rd Year CS)
 * school : Rochester Institute of Technology
 * created: 04.16.2024 20:47:02
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

const char MIN_CHAR = 'a';

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
    string smallestFromLeaf(TreeNode* root) {
        auto chr = [&](int o) -> char {
            return char(o + MIN_CHAR);
        };

        string sans;
        string sb;
        y_combinator([&](auto&& dfs, TreeNode* root) -> void {
            if (root == NULL) {
                return;
            }
            bool is_leaf = true;
            sb += chr(root->val);
            for (TreeNode* next_root : {root->left, root->right}) {
                if (next_root) {
                    is_leaf = false;
                    dfs(next_root);
                }
            }
            if (is_leaf) {
                reverse(sb.begin(), sb.end());
                if (sans.empty() || sb < sans) {
                    sans = sb;
                }
                reverse(sb.begin(), sb.end());
            }
            sb.pop_back();
        })(root);

        return sans;
    }
};

// ~ JustJie