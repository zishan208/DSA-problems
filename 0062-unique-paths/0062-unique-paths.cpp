class Solution {
private:
        void calculation(int r1, int r2, int &count,int m,int n,vector<vector<int>>& dp){

            if(r1==m && r2==n){
                    count ++;
                    return;
            } 
            if(r1>m || r2>n) return;
                if (dp[r1][r2] != -1) {
            count += dp[r1][r2];
            return;
                                        }
 int before = count;
      
            //go to right
            calculation(r1,r2+1,count,m,n,dp);
            //go to bottom
            calculation(r1+1,r2,count,m,n,dp);
            dp[r1][r2] = count - before;

        }
        
public:
    int uniquePaths(int m, int n) {
            //these are initials
        int r1=1;//right
        int r2=1;//bottom
        int count=0;
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, -1));

        calculation(r1,r2,count,m,n,dp);
         
            return count;     
    }
};