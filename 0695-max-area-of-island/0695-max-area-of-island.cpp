class Solution {
    private:
    void dfs(int i, int j, vector<vector<int>> &grid,int &count,int row,int col){
         if(grid[i][j]==0){
            return;

        }
        
        if(grid[i][j]==1){
            count++;
            grid[i][j]=0;

        }
        if(i+1<row) dfs(i+1,j,grid,count,row,col);
        if(j+1<col) dfs(i,j+1,grid,count,row,col);
        if(i-1>=0)  dfs(i-1,j,grid,count,row,col);
        if(j-1>=0)  dfs(i,j-1,grid,count,row,col);
        

    }
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int row=grid.size();
        int col=grid[0].size();
        int mx=0;


        for (int i = 0; i < row; i++) {
                for (int j = 0; j < col; j++) {

                    if(grid[i][j]==1){
                        int count=0;
                        dfs(i,j,grid,count,row,col);
                        mx=max(count,mx);

                    }
                     
                }
        }
        return mx;
    }
};