class Solution {
    int finds(int n,vector<int> & dp,int maxprod){
        if (n == 1) return 1;   
          if(n==2) return 1;
        if(n==3) return 2;

        if(dp[n]!=-1) return dp[n];
        
        for(int i=1;i<n;i++){
            int prod1=i*(n-i);
            int prod2=i*finds(n-i,dp,maxprod);
            maxprod=max(maxprod,max(prod1,prod2));

        }

        dp[n]=maxprod;


        return maxprod;



        

         }
    
public:
    int integerBreak(int n) {
        vector<int> dp(n+1,-1);
        return finds(n,dp,1);

    }
};

