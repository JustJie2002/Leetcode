/********************************************
 * author : Jie Chen (3rd Year CS)
 * school : Rochester Institute of Technology
 * created: 04.14.2024 20:24:04
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
    int sumNumbers(TreeNode* root, int pre = 0) {
        pre = pre * 10 + root->val;
        int ans = 0;
        bool is_leaf = true;
        for (TreeNode* nxt : {root->left, root->right}) {
            if (nxt) {
                is_leaf = false;
                ans += sumNumbers(nxt, pre);
            }
        }
        if (is_leaf) {
            ans = pre;
        }
        return ans;
    }
};

// ~ JustJie