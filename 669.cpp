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
 * 
 * The idea here is that for a binary search tree
 *  - all of the values to the left of the current node is less than it
 *  - all of the values to the right of the current node is greater than it
 * Therefore, if the value of the current node is less than low then we take the right
 * Similarly, if the value of the current node is greater than high, we take the left
 * otherwise, we keep on going through the tree until we hit a nullptr
 * 
 **/
class Solution {
public:
    TreeNode* trimBST(TreeNode* root, int low, int high) {
        if (root) {
            if (root->val < low) return trimBST(root->right, low, high);
            if (root->val > high) return trimBST(root->left, low, high);
            return new TreeNode(root->val, trimBST(root->left, low, high), trimBST(root->right, low, high));
        }
        return nullptr;
    }
};