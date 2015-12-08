// 40ms
// BST solution
class Solution {
public:
    class BSNode {
    public:
        int count, val;
        BSNode *left, *right;
        BSNode(int val, int count) {
            this->left = NULL;
            this->right = NULL;
            this->val = val;
            this->count = count;
        }
    };

    int insertNode(BSNode *root, int val){
        if (root->count++ == 0) {
            root->val = val;
            return 0;
        }

        int left_count = 0;
        if (root->left != NULL) left_count = root->left->count;
        int right_count = 0;
        if (root->right != NULL) right_count = root->right->count;

        if (root->val == val) {
            return left_count;
        }

        if (root->val > val) {
            if (root->left == NULL){
                root->left = new BSNode(val, 1);
                return 0;
            } else {
                return insertNode(root->left, val);
            }
        } else {
            if (root->right == NULL) {
                root->right = new BSNode(val, 1);
                return left_count + root->count - left_count - right_count - 1;
            } else {
                return left_count + insertNode(root->right, val)
                    + root->count - left_count - right_count - 1;
            }
        }
    };

    vector<int> countSmaller(vector<int>& nums) {
        vector<int> ret(nums.size(), 0);
        BSNode* root = new BSNode(0, 0);
        for (int i = (int)nums.size() - 1; i >= 0; --i){
            ret[i] = insertNode(root, nums[i]);
        }
        return ret;
    }
};
