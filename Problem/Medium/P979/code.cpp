/********************************************
 * author : Jie Chen (3rd Year CS)
 * school : Rochester Institute of Technology
 * created: 05.18.2024 19:39:56
*********************************************/

using i64 = long long;

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
    int distributeCoins(TreeNode* root) {
        // O(n^2) approach is if current tree node has more than 1 then we can
        // try to give one to its child and see if any accepts it, otherwise
        // we give the excessive coins back up (normie)

        // let's try an O(n) approach
        int ans = 0;
        y_combinator(
            [&](auto&& dfs, TreeNode* root) -> int {
                if (!root) {
                    return 0;
                }
                int m = root->val + dfs(root->left) + dfs(root->right);
                int excessive = m - 1;
                ans += abs(excessive);
                return excessive;
            }
        )(root);
        return ans;
    }
};

// ~ JustJie