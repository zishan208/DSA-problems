/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

// class Solution {
// private:

// int find_level(TreeNode* root, TreeNode* temp,int level=0){

//     if (root==nullptr) return -1;
//     if(root==temp) return level;
                                
//     int left_depth=find_level(root->left,temp,level+1);
//     if(left_depth!=-1) return left_depth;

//     return find_level(root->right,temp,level+1);



// }
// public:
//     TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
//         if(root==nullptr) return nullptr;
        
//         int level1=find_level(root,p,0);
//         int level2=find_level(root,q,0);

//         map<TreeNode*, TreeNode*> child_parent;
//         queue<TreeNode*> que;
//         que.push(root);
//         child_parent[root]=nullptr;

//         while (!que.empty()) {
//             int size=que.size();

//             for (int i = 0; i < size; i++) {
//                 TreeNode* temp=que.front();
//                 que.pop();
//                 if (temp->left) {
//                     que.push(temp->left);
//                     child_parent[temp->left]=temp;
//                 }
//                 if (temp->right) {
//                     que.push(temp->right);
//                     child_parent[temp->right]=temp;
//                 }
//             }
            
//         }
//         // now we have father of each
//         TreeNode* ancestor1=p;
//          TreeNode* ancestor2=q;
//         while (level1!=level2) {

//             if (level1>level2) {
//                 ancestor1=child_parent[ancestor1];
//                 level1--;
                
//             }
//              if (level1<level2) {
//                 ancestor2=child_parent[ancestor2];
//                 level2--;
                
//             }
           
//         }

//         //we have equal level
//         while (ancestor1!=ancestor2) {
//             ancestor1=child_parent[ancestor1];
//              ancestor2=child_parent[ancestor2];
//         }

       


        



// return ancestor1;
        
//     }
// };










class Solution {

public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root==nullptr || root==q || root==p) return root;

    TreeNode* left= lowestCommonAncestor(root->left, p, q) ;
        TreeNode* right= lowestCommonAncestor(root->right, p, q) ;
       
        if (left != nullptr && right != nullptr) {
            return root;
     }

       
    return (left != nullptr) ? left : right;
        
    }
};