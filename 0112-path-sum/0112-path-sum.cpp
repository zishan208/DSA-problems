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
  void pathsum(TreeNode* root, int targetSum,int sum,bool &yes){

    if(root==nullptr || yes) return;
    sum=sum+root->val;


   if(!root->left && !root->right){
     if(sum==targetSum){
            yes=true;}
            return;
   }    
    pathsum( root->left,targetSum,sum,yes);
     pathsum( root->right,targetSum,sum,yes);




  }
public:
    bool hasPathSum(TreeNode* root, int targetSum) {
        if(root==nullptr) false;
        bool yes=false;

        pathsum(root,targetSum,0,yes);
        return yes;

        
    }
};