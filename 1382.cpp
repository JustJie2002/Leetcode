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
private:
    vector<int> vals;

public:
    void dfs1(TreeNode* root) {
        if (root != nullptr) {
            vals.push_back(root->val);
            dfs1(root->left);
            dfs1(root->right);
        }
    }

    TreeNode* dfs2(int l, int r) {
        if (l > r)
            return nullptr;
        int mid = l + (r - l) / 2;
        TreeNode* left = dfs2(l, mid - 1);
        TreeNode* right = dfs2(mid + 1, r);
        TreeNode* ans = new TreeNode(vals[mid], left, right);
        return ans;
    }

    TreeNode* balanceBST(TreeNode* root) {
        dfs1(root);
        sort(vals.begin(), vals.end());
        return dfs2(0, int(vals.size()) - 1);
    }
};