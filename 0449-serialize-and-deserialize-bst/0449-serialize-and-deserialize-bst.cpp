/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
    private:
    void dfs(TreeNode* root, string& ans) {
        if (!root) return;
        if (!ans.empty()) ans += ",";
       ans += to_string(root->val);
        dfs(root->left, ans);
        dfs(root->right, ans);
    }
   TreeNode* buildBST(vector<int>& preorder,int &idx,int minVal,int maxVal){

     if (idx >= preorder.size()) return nullptr;
        
        int val = preorder[idx];
    if (val < minVal || val > maxVal) return nullptr;
        
    TreeNode* root = new TreeNode(val);
        idx++;
        
     root->left = buildBST(preorder, idx, minVal, val);
        root->right = buildBST(preorder, idx, val, maxVal);
        
        return root;
   }
public:

    string serialize(TreeNode* root) {


        string ans="";
        dfs(root,ans);
        return ans;


        
    }

 
    TreeNode* deserialize(string data) {
            if (data.empty()) return nullptr;
        
        vector<int> preorder;
        stringstream ss(data);
        string token;
      
        while (getline(ss, token, ',')) {
            preorder.push_back(stoi(token));
        }

    int idx = 0;
        return buildBST(preorder, idx, INT_MIN, INT_MAX);

     

        }



        
};

// Your Codec object will be instantiated and called as such:
// Codec* ser = new Codec();
// Codec* deser = new Codec();
// string tree = ser->serialize(root);
// TreeNode* ans = deser->deserialize(tree);
// return ans;