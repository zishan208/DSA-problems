class Solution {
private:
 int pas(int n,int step_count, vector<int> &dp){
          if(step_count>n) return 0;
        if(step_count==n){
        
            return 1;
        }

        if(dp[step_count]!=-1) return dp[step_count];

       dp[step_count] = (pas(n, step_count + 1, dp) + pas(n, step_count + 2, dp)) ;


        return dp[step_count];
      

    }

public:
    int climbStairs(int n) {
         if (n <= 1) return 1;

    vector<int> dp(n + 1, -1);

        return pas(n,0,dp);
    }
};


