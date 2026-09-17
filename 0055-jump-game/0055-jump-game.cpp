class Solution {
private:
    bool check(vector<int>& nums, int size, int index, vector<int>& dp) {
        if (index >= size - 1) return true;
        if (dp[index] != -1) return dp[index];

        for (int i = 1; i <= nums[index]; i++) {
            
         int newIndex = index + i;
            if (newIndex < size && check(nums, size, newIndex, dp)) {
                return dp[index] = true;
            }
        }
        return dp[index] = false;
    }


public:
    bool canJump(vector<int>& nums) {
        int size = nums.size();
        vector<int> dp(size, -1); 
        return check(nums, size, 0, dp);
    }
};