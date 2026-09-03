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
    TreeNode* make_tree(vector<int>& nums,int s,int e){

        if(s>e) return nullptr;

        int index=s;
       for(int i=s;i<=e;i++){
        if(nums[i]>nums[index]) index=i;
       }
              TreeNode* root=new TreeNode(nums[index]);

              root->left=make_tree(nums,s,index-1);
              root->right=make_tree(nums,index+1,e);

              return root;

      

    }
public:
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        return make_tree(nums,0,nums.size()-1);
    }
};