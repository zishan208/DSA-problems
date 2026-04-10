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
   
 vector<vector<int>> levelOrderBottom(TreeNode* root) {
    vector<vector<int>> ans;
    if (root==nullptr)
    {
      return ans;
    }
    queue<TreeNode*> q;
    stack<vector<int>> st;
    
    q.push(root);
    while (!q.empty())
    {
        int sizeoflevel=q.size();
        vector<int> currentlevel;

        for (int i = 0; i < sizeoflevel; i++)
        {
            TreeNode* fr=q.front();
            q.pop();
            currentlevel.push_back(fr->val);

            if (fr->left)
            {
                q.push(fr->left);
            }
            if (fr->right)
            {
                q.push(fr->right);
            }
        
            }
            st.push(currentlevel);
        }
        //now we have level order from top to bottom
        while (!st.empty())
        {
            ans.push_back(st.top());
            st.pop();
        }
        
return ans;
    
 }

};