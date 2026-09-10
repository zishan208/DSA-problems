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
    pair<int,int> travesrse(TreeNode* root,int &count){
        if(root==nullptr) return {0,0};

        

       auto left=travesrse(root->left,count);
       auto right=travesrse(root->right,count);

            int sum=root->val+left.first+right.first;
            int c = 1 + left.second + right.second;
            
            if(sum/c == root->val) count++;

            

            return {sum,c};
        




    }
public:
    int averageOfSubtree(TreeNode* root) {
        if(root==nullptr) return 0;
        
        int count=0;

        travesrse(root,count);
        return count;
        
    }
};