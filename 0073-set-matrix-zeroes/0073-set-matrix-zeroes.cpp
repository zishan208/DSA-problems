
class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {

        int row=matrix.size();
        int column=matrix[0].size();

        for (int i = 0; i < row; i++)
        {
            for(int j=0;j<column;j++){
                if (matrix[i][j]==0)
                {

                    for (int k = 0; k < row; k++)
                    {
                        matrix[k][j]=0;
                    }
                    for (int k = 0; k < column; k++)
                    {
                        matrix[i][k]=0;
                    }
                    
                    
                    



                }
                




            }
        }
        

        

        
    }
};