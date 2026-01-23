class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int rows= matrix.size();
        int columns=matrix[0].size();
        int row_index=0;
        int column_index=columns-1;
 
        while (row_index<rows && column_index>=0)
        {
            int elem=matrix[row_index][column_index];
             if (elem==target)
            {
                return 1;
            
            }
            else if (elem<target)
            {
                row_index++;
            }
            else{
                column_index--;
            } 
        }     
        return 0;
    }
};