class Solution {
private:
    bool check(vector<int>& nums,  int index, vector<int>& dp) {
        if (index >=nums.size()-1) return true;
        if (dp[index] != -1) return dp[index];

        for (int i = 1; i <= nums[index]; i++) {

         int newIndex = index + i;
            if (newIndex < nums.size() && check(nums,newIndex, dp)) {
                return dp[index] = true;
            }
        }
        return dp[index] = false;
    }


public:
    bool canJump(vector<int>& nums) {
        
        vector<int> dp(nums.size(), -1); 
        return check(nums, 0, dp);
    }
};