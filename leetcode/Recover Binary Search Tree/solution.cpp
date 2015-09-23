class Solution {
public:
    // 48ms, dfs
    // rather simple "Hard" problem
    TreeNode* errorNodes[3];
    TreeNode* preNode = NULL;
    int found = 0;

    void dfs(TreeNode* node) {
        if (NULL != node->left) dfs(node->left);
        if (NULL != preNode) {
            if (preNode->val > node->val){
                errorNodes[found] = preNode;
                errorNodes[++found] = node;
            }
        }
        preNode = node;
        if (NULL != node->right && found <= 1) dfs(node->right);
    }

    void recoverTree(TreeNode* root) {
        dfs(root);
        if (0 != found) swap(errorNodes[0]->val, errorNodes[found]->val);
    }
};