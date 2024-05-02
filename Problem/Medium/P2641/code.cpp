/********************************************
 * author : Jie Chen (3rd Year CS)
 * school : Rochester Institute of Technology
 * created: 05.01.2024 20:36:52
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
    TreeNode* replaceValueInTree(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);
        vector<int> sum;
        while (!q.empty()) {
            sum.push_back(0);
            int siz = q.size();
            while (siz--) {
                auto rt = q.front();
                q.pop();

                sum.back() += rt->val;
                for (auto subtree : {rt->left, rt->right}) {
                    if (subtree) {
                        q.push(subtree);
                    }
                }
            }
        }

        auto sum_under_same_parent = [&](TreeNode* node) -> int {
            int v = 0;
            for (const auto& subtree : {node->left, node->right}) {
                if (subtree) {
                    v += subtree->val;
                }
            }
            return v;
        };

        TreeNode* tr = new TreeNode(0);
        y_combinator([&](auto&& dfs, TreeNode* tr, TreeNode* rt, TreeNode* fa, int depth) -> void {
            if (fa) {
                tr->val = sum[depth] - sum_under_same_parent(fa);
            }
            if (rt->left) {
                tr->left = new TreeNode(0);
                dfs(tr->left, rt->left, rt, depth + 1);
            }
            if (rt->right) {
                tr->right = new TreeNode(0);
                dfs(tr->right, rt->right, rt, depth + 1);
            }
        })(tr, root, nullptr, 0);
        return tr;
    }
};

// ~ JustJie