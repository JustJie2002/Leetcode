/********************************************
 * author : Jie Chen (3rd Year CS)
 * school : Rochester Institute of Technology
 * created: 01.09.2024 14:42:02
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
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {

        auto solve = [&](TreeNode* root) {
            vector<int> ord;
            auto dfs = [&](const auto& self, TreeNode* node) -> void {
                if (node->left) {
                    self(self, node->left);
                }
                if (node->right) {
                    self(self, node->right);
                }
                if (node->left == NULL && node->right == NULL) {
                    ord.push_back(node->val);
                }
            };
            dfs(dfs, root);
            return ord;
        };

        auto ord1 = solve(root1);
        auto ord2 = solve(root2);
        return ord1 == ord2;
    }

};

// ~ JustJie