/********************************************
 * author : Jie Chen (3rd Year CS)
 * school : Rochester Institute of Technology
 * created: 04.14.2024 02:04:52
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
    int sumOfLeftLeaves(TreeNode* root, bool is_left = false) {
        if (root == NULL) {
            return 0;
        }
        if (is_left && !root->left && !root->right) {
            return root->val;
        }
        int res = sumOfLeftLeaves(root->left, true);
        res += sumOfLeftLeaves(root->right);
        return res;
    }
};

// ~ JustJie