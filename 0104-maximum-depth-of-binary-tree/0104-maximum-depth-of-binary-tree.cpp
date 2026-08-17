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
    private:
    int xfind(TreeNode* root){
        if(root==nullptr) return 0;
        int ld= xfind(root->left);
        int rd= xfind(root->right);
        return 1+max(ld,rd);
    }
public:
    int maxDepth(TreeNode* root) {
      return  xfind(root);  
    }
};