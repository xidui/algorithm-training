/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    unordered_map<TreeNode*, int> m1;
    unordered_map<TreeNode*, int> m2;

    // rob the root
    int dfs_1(TreeNode* root) {
        if (root == NULL) return 0;
        if (m1.find(root) != m1.end()) return m1[root];
        int ans = dfs_2(root->left) + dfs_2(root->right) + root->val;
        m1[root] = ans;
        return ans;
    }

    // do not rob the root
    int dfs_2(TreeNode* root) {
        if (m2.find(root) != m2.end()) return m2[root];
        if (root == NULL) return 0;
        int ans = rob(root->left) + rob(root->right);
        m2[root] = ans;
        return ans;
    }

    int rob(TreeNode* root) {
        return max(dfs_1(root), dfs_2(root));
    }
};