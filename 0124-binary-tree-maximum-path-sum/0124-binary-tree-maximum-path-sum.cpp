class Solution {
private:
    int ans = INT_MIN;

    int c(TreeNode* root) {
        if (root == nullptr) return 0;

        int left = max(0, c(root->left));
        int right = max(0, c(root->right));

        ans = max(ans, root->val + left + right);

        return root->val + max(left, right);
    }

public:
    int maxPathSum(TreeNode* root) {
        c(root);
        return ans;
    }
};