class Solution {
    private:
    
    vector<vector<int>> transpose(vector<vector<int>>& matrix) {
        int rows = matrix.size();
    int cols = matrix[0].size();
        vector<vector<int>> ans(cols, vector<int>(rows));
        
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
       ans[j][i] = matrix[i][j]; 
            }
        }
        return ans;
    }


public:
    void rotate(vector<vector<int>>& matrix) {

        matrix=transpose( matrix);

        for(int i=0;i<matrix.size();i++){
            reverse(matrix[i].begin(),matrix[i].end());

        }
        
        
    }
};