class Solution {
    int f(int n,vector<int>& dp) {
        if (n < 0) return INT_MAX;
    if (n == 0) return 0;
        if (dp[n] != -1) return dp[n];

        int minimum=INT_MAX;

        for (int i = 1; i*i <= n; i++) {
            
                int num=i*i;
                int p=f(n-num,dp);

                 if (p != INT_MAX) {
                minimum = min(minimum, 1 + p); 
            }
        }

        dp[n]=minimum;
        return dp[n];

       
    }

public:
    int numSquares(int n) {
        if (n == 0 || n == 1) return n;

        

        vector<int> dp(n + 1, -1);
        return f(n, dp);
    }
};