class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int n = nums.size();

        int sum = 0;
        for (int c : nums) sum += c;

        int req = sum - x;
        if (req < 0) return -1;
     if (req == 0) return n; 

        int s = 0, e = 0, temp = 0;
        int maxLen = -1;

        while (e < n) {
            temp += nums[e];

            while (temp > req && s <= e) {
                temp -= nums[s];
                s++;
            }

            if (temp == req) {
               maxLen = max(maxLen, e - s + 1);
            }

            e++;
        }

        return maxLen == -1 ? -1 : n - maxLen;
    }
};










// class Solution {
//     int check(vector<int> &nums,int x,int last,int first,vector<vector<int>> &dp){

//         if(x==0) return 0;
//         if(last<first) return INT_MAX;

//         if(dp[first][last]!=-1) return dp[first][last];

//         int num1=INT_MAX;
//         int num2=INT_MAX;
    

//         if(first+1 <nums.size())
//         num1=check(nums,x-nums[first],last,first+1,dp);
//         if(num1!=INT_MAX) num1++;

//         if(last>=0) 
//         num2=check(nums,x-nums[last],last-1,first,dp);
//         if(num2!=INT_MAX) num2++;

//         dp[first][last]=min(num1,num2);


//         return min(num1,num2) ;

//     }
//     public:
//     int minOperations(vector<int>& nums, int x) {
//      int n = nums.size();
//         vector<vector<int>> dp(n, vector<int>(n, -1));
//         int ans = check(nums, x, n - 1, 0, dp);
//         return ans == INT_MAX ? -1 : ans;
        
//     }
// };