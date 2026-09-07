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
    void check(TreeNode* root,int max,int &count){
        if(root==nullptr) return;
        if(root->val>=max){
             count++;
             max=root->val;
        }
        check(root->right,max,count);
        check(root->left,max,count);
        

    }
public:
    int goodNodes(TreeNode* root) {


        int max=root->val;
        int count=0;
        check(root,max,count);
        return count;
        
    }
};