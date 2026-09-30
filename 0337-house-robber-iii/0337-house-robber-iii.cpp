class Solution {
    int check(TreeNode* root, unordered_map<TreeNode*,int>& dp) {
        if (root == nullptr) return 0;

        if (dp.count(root)) return dp[root];

        int rob = root->val;
        if (root->left) {
            rob += check(root->left->left, dp) + check(root->left->right, dp);
        }
        if (root->right) {
            rob += check(root->right->left, dp) + check(root->right->right, dp);
        }

        int skip = check(root->left, dp) + check(root->right, dp);

        dp[root] = max(rob, skip);
        return dp[root];
    }

public:
    int rob(TreeNode* root) {
        unordered_map<TreeNode*,int> dp;
        return check(root, dp);
    }
};