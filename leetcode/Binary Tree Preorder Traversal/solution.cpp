class Solution {
public:
    vector<int> nodes;

    void traversal(TreeNode* root){
        if (NULL == root) return;
        nodes.push_back(root->val);
        traversal(root->left);
        traversal(root->right);
    }

    vector<int> preorderTraversal(TreeNode* root) {
        nodes.clear();
        traversal(root);
        return nodes;
    }
};