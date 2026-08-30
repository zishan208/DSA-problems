class Solution {
    private:
    void count(vector<vector<int>>& grid,int i ,int j,int row,int col){
       if(i<0 || i>row-1 || j<0 || j>col-1 || grid[i][j]==0){
        return;
       }

       grid[i][j]=0;
       count(grid,i+1,j,row,col);
       count(grid,i-1,j,row,col);
        count(grid,i,j+1,row,col);
        count(grid,i,j-1,row,col);

    }
public:
    int numEnclaves(vector<vector<int>>& grid) {
        int row=grid.size();
        int col=grid[0].size();

           for (int j = 0; j < col; j++) {
            if (grid[0][j] == 1) count(grid, 0, j, row, col);         
         if (grid[row - 1][j] == 1) count(grid, row - 1, j, row, col);
        }

       
        for (int i = 0; i < row; i++) {
            if (grid[i][0] == 1) count(grid, i, 0, row, col);         
          if (grid[i][col - 1] == 1) count(grid, i, col - 1, row, col); 
        }
        int c=0;
        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                if(grid[i][j]==1) c++;
             }

        }
       
        return c;
    }
};