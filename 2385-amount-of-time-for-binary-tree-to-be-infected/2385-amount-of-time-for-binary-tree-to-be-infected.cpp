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
public:
    int amountOfTime(TreeNode* root, int start) {
        

        if(root==nullptr) return 0;
        TreeNode* req=nullptr;
        
        map<TreeNode*, TreeNode*> child_parent;
        //1.find parent
        //found req
        queue<TreeNode*> q;
        q.push(root);
        child_parent[root]=nullptr;
        while(!q.empty()){
        
            TreeNode* temp=q.front();
            q.pop();
            if(temp->val==start) req=temp;

            if(temp->left){
                child_parent[temp->left]=temp;
                q.push(temp->left);
            }
            if(temp->right){
                child_parent[temp->right]=temp;
                q.push(temp->right);
            }
        }
        //parent pushing end here

        //find node;

        map<TreeNode*, bool> visited;

        //each node have three option
       //use q again;
        int ans=0;

        q.push(req);
        visited[req] = true;
       while(!q.empty()){

        int size=q.size();
         bool isAny=false;
        for(int i=0;i<size;i++){
            TreeNode* temp=q.front();
            q.pop();
           


            if(temp->left && !visited[temp->left]){ 
                q.push(temp->left);
                isAny=true;
                visited[temp->left]=true;
            }
            if(temp->right && !visited[temp->right]){
                q.push(temp->right);
                isAny=true;
                visited[temp->right]=true;
                }
            if(child_parent[temp] &&  !visited[child_parent[temp]]) 
            { q.push(child_parent[temp]);
            isAny=true;
            visited[child_parent[temp]]=true;
            }

          



        }
          if(isAny)  ans++;

       }
       



return ans;
        
    }
};