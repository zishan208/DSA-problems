class Solution {
    int fi(vector<int>& nums, int index, int prev, vector<vector<int>>& dp, int size) {
        if (index >= size) return 0;

       if (dp[index][prev + 1] != -1)
        return dp[index][prev + 1];

        int s1 = fi(nums, index + 1, prev, dp, size);
        int s2 = 0;
        if (prev == -1 || nums[index] > nums[prev]) {
            s2 = 1 + fi(nums, index + 1, index, dp, size);
        }
        dp[index][prev + 1] = max(s1, s2);
        return dp[index][prev + 1];
    }

public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp(n, vector<int>(n + 1, -1));
        return fi(nums, 0, -1, dp, n);
    }
};