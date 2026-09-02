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
    TreeNode* inorder(TreeNode* root,int &count,int k){
             if (root == nullptr) return nullptr;
        TreeNode* left=inorder(root->left,count,k);
        if(left) return left;


        count++;
        if(count==k) return root;

        return inorder(root->right,count,k);
    

    }
public:
    int kthSmallest(TreeNode* root, int k) {
       
                int count=0;
      TreeNode* ans= inorder(root,count,k);
      return ans->val;

      

        
    }
};