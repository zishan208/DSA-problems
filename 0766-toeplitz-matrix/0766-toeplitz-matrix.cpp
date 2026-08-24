class Solution {
public:
    bool isToeplitzMatrix(vector<vector<int>>& matrix) {

        int row_size=matrix.size();
        int col_size=matrix[0].size();
        if(row_size==1 && col_size==1) return true;
        int last_index=row_size+col_size-1;
        vector<vector<int>> ans(last_index);

        for(int i=0;i<row_size;i++){
            for(int j=0;j<col_size;j++){
                int index=i - j + col_size - 1;
                ans[index].push_back(matrix[i][j]);
                
            }
        }

       for(int i=0;i<ans.size();i++){
            
        
            for(int j=0;j<ans[i].size()-1;j++){
                if(ans[i].size()==1) continue;
                if(ans[i][j]!=ans[i][j+1]) return false;




                
                
                
            }
        }
        return true;
        
    }
};