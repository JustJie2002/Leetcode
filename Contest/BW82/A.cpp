/********************************************
 * author : Jie Chen (3rd Year CS)
 * school : Rochester Institute of Technology
 * created: 03.12.2024 22:05:56
*********************************************/

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
    bool evaluateTree(TreeNode* root) {
        
        function<int(TreeNode*)> dfs = [&](TreeNode* node) -> int {
            if (!node->left && !node->right) {
                return node->val;
            }
            if (node->val == 2) {
                return dfs(node->left) | dfs(node->right);
            }
            return dfs(node->left) & dfs(node->right);
        };

        return dfs(root);
    }
};

// ~ JustJie