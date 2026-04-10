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
void usequeue(TreeNode* root,  queue<TreeNode*> &q){
    if(root==nullptr) return;
    q.push(root);
    usequeue(root->left,q);
    usequeue(root->right,q);
}

public:
    void flatten(TreeNode* root) {
        if(root==nullptr) return;
        queue<TreeNode*> q;
        usequeue(root,q);
        TreeNode* prev=q.front();
        q.pop();

        while(!q.empty()){
            TreeNode* current=q.front();
            
            q.pop();
          prev->left=nullptr;
          prev->right=current;

          prev=current;

        }

        prev->left=nullptr;
        prev->right=nullptr;
        
    }
};