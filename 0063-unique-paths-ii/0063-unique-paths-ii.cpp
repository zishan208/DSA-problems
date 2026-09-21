class Solution {

    private:
    int s(vector<vector<int>> &obstacleGrid,int &row,int &col,int i,int j,vector<vector<int>> &dp){

          if(i>=row || j>=col) return 0;
          
        if(obstacleGrid[i][j]==1) return 0;

        if(i==row-1 && j==col-1) return 1;
      

        if(dp[i][j]!=-1) return dp[i][j];

        int down=0;
        int right=0;

           if(i+1<row ) down=s(obstacleGrid,row,col,i+1,j,dp);
           if(j+1<col) right=s(obstacleGrid,row,col,i,j+1,dp);

           dp[i][j]=down+right;

           return dp[i][j];


    }
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {



        int row=obstacleGrid.size();
        int col=obstacleGrid[0].size();

        vector<vector<int>> dp(row,vector<int>(col,-1));


        return s(obstacleGrid,row,col,0,0,dp);
        
    }
};