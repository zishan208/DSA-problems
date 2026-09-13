class Solution {
public:
    int maxSubArray(vector<int>& nums) {
            int n=nums.size();

          if(n==1) return nums[0];

               vector<int> dp(n);
               dp[0]=nums[0];
               int ans=dp[0];
               for(int i=1;i<n;i++){
                dp[i]=max(nums[i],nums[i]+dp[i-1]);
                 ans = max(ans, dp[i]);
               }


    


        
   

        return ans;

        
    }
};


// class Solution {
// private:
//         int maximum(vector<int> &nums,int i,int j,int sum,vector<vector<int>> &dp){
//             if(i>j) return INT_MIN;

//             if(dp[i][j]!=-1) return dp[i][j];
//             int sum1=maximum(nums,i+1,j,sum-nums[i],dp);
//              int sum2=maximum(nums,i,j-1,sum-nums[j],dp);

//                 dp[i][j]=max(sum,max(sum1,sum2));
//              return dp[i][j] ;


//         }
// public:
//     int maxSubArray(vector<int>& nums) {

//         if(nums.size()==1) return nums[0];
//         int n=nums.size();


//         int sum=0;
//         for(int c: nums){
//             sum+=c;
//         }
//         vector<vector<int>> dp(n+1,vector<int>(n,-1));

//         return maximum(nums,0,nums.size()-1,sum,dp);

        
//     }
// };