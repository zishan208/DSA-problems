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
    int height(TreeNode* roor){
        if (roor==nullptr)    return 0;
        int lefts=height(roor->left);
        int rights=height(roor->right);
        return max(lefts,rights)+1;
    }
  public:
    bool isBalanced(TreeNode* root) {
          if (root==nullptr)    return true;
        int lefts=height(root->left);
        int rights=height(root->right);
        if(abs(lefts-rights)>1) return false;

      
       return  isBalanced(root->left)&isBalanced(root->right);
        
    }
};
