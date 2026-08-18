class Solution {
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<vector<int>> ans;
        
    map<int, vector<pair<int, int>>> mpp; 
        
        if (root == nullptr) return ans;
        
        queue<pair<TreeNode*, pair<int, int>>> q;
        q.push({root, {0, 0}}); // root at index 0, level 0

        while (!q.empty()) {
            auto temp = q.front();
            q.pop();
            
            TreeNode* temp_node = temp.first;
            int index = temp.second.first; 
      int level = temp.second.second; 

            mpp[index].push_back({level, temp_node->val});

            if (temp_node->left) {
                q.push({temp_node->left, {index - 1, level + 1}});
      }
            if (temp_node->right) {
                q.push({temp_node->right, {index + 1, level + 1}});
            }
        }

  
        for (auto &it : mpp) {
            vector<pair<int, int>> &colData = it.second;
            
       
     sort(colData.begin(), colData.end(), [](auto &a, auto &b) {
                if (a.first != b.first) return a.first < b.first;
                return a.second < b.second;
            });
   vector<int> colValues;
             for (auto &p : colData) {
                colValues.push_back(p.second);
       }
            ans.push_back(colValues);
        }
        
        return ans;
    }
};