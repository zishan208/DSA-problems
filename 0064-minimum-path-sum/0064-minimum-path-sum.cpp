class Solution {
     private:
    int s(vector<vector<int>> &grid,int &row,int &col,int i,int j,vector<vector<int>> &dp){

          if(i>=row || j>=col) return 0;
        if(i==row-1 && j==col-1) return grid[i][j];
      
        if(dp[i][j]!=-1) return dp[i][j];

        int sum1=INT_MAX;
        int sum2=INT_MAX;
           if(i+1<row ) sum1=grid[i][j]+s(grid,row,col,i+1,j,dp);
           if(j+1<col) sum2=grid[i][j]+s(grid,row,col,i,j+1,dp);

           dp[i][j]=min(sum1,sum2);

           return dp[i][j];


    }
public:
    int minPathSum(vector<vector<int>>& grid) {

         int row=grid.size();
        int col=grid[0].size();

        vector<vector<int>> dp(row,vector<int>(col,-1));


        return s(grid,row,col,0,0,dp);
        
    }
};

