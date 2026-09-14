class Solution {
public:
    int maximumSum(vector<int>& arr) {

        int n=arr.size();
        if(n==1) return arr[0];
        vector<int> dp(n),dp1(n);
        dp[0]=arr[0];
        dp1[0]=-1e9;
        
   
        int ans=dp[0];

        for(int i=1;i<n;i++){
        
          
        dp[i]=max(dp[i-1]+arr[i],arr[i]);
        dp1[i] = max(dp[i-1], dp1[i-1] + arr[i]);

        ans=max(ans,max(dp[i],dp1[i]));


        


        }
        return ans;

        
    }
};