class Solution {
    int c(vector<int>& nums, int s, int e, vector<int>& dp) {
        if (s > e) return 0;
        if (dp[s] != -1) return dp[s];

        int sum1 = nums[s] + c(nums, s + 2, e, dp); 
        int sum2 = c(nums, s + 1, e, dp);      

        dp[s] = max(sum1, sum2);
        return dp[s];
    }

public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n == 1) return nums[0];
        if (n == 2) return max(nums[0], nums[1]);

        vector<int> dp1(n, -1);
        vector<int> dp2(n, -1);

        return max(c(nums, 0, n - 2, dp1), c(nums, 1, n - 1, dp2));
    }
};