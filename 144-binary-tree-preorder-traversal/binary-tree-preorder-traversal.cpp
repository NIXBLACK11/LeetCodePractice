class Solution {
public:
    void preOrder(TreeNode* root, vector<int>& res) {
        if(root == nullptr) return;
        else res.push_back(root->val);
        preOrder(root->left, res);
        preOrder(root->right, res);
    }
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> res;
        preOrder(root, res);
        return res;
    }
};