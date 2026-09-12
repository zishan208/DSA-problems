class Solution {
public:
    vector<int> getRow(int rowIndex) {

        if(rowIndex==0) return {1};

        
        vector<vector<int>> ans;
        ans.push_back({1});

          for (int i = 1; i <= rowIndex; i++) {
            vector<int> curr(i + 1, 1); 
            for (int j = 1; j <i; j++) {
                curr[j] = ans[i - 1][j - 1] + ans[i - 1][j];
            }
            ans.push_back(curr);
        }
return ans[rowIndex];
        
    }
};