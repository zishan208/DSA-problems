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
    int height(TreeNode* root){
            if(root==nullptr) return 0;
            int lefts=height(root->left);
            int rights=height(root->right);
            // here is our answer
        return max(lefts,rights)+1;

    }
    
    
 
    
  public:
    int diameterOfBinaryTree(TreeNode* root) {
    
        if(root==nullptr) return 0;
                int op1=diameter(root->left);
                int op2=diameter(root->right);
                int op3=height(root->left)+height(root->right);

                return max(max(op1,op2),op3);
      


        
    }
};


