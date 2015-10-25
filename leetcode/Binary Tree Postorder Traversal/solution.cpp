// iterative solution
class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> ret;
        if (NULL == root) return ret;
        stack<TreeNode*> sn;
        stack<int> si;
        sn.push(root);
        while (sn.size()){
            TreeNode* temp = sn.top();
            sn.pop();
            si.push(temp->val);
            if (NULL != temp->left) sn.push(temp->left);
            if (NULL != temp->right) sn.push(temp->right);
        }
        while (si.size()){
            ret.push_back(si.top());
            si.pop();
        }
        return ret;
    }
};