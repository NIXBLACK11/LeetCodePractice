class Solution {
public:
    bool trav(TreeNode* root, int targetSum, int sum) {
        if (root == nullptr) {
            return false;
        }
        
        sum += root->val;

        if (root->left == nullptr && root->right == nullptr) {
            return sum == targetSum;
        }

        return trav(root->left, targetSum, sum) || trav(root->right, targetSum, sum);
    }

    bool hasPathSum(TreeNode* root, int targetSum) {
        if (root == nullptr) {
            return false;
        }
        
        return trav(root, targetSum, 0);
    }
};