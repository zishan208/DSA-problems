class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n = nums.size();
        int start = 0;
        int pre_sum = 0;
        int ans = INT_MAX;


        for (int end = 0; end < n; end++) {
            
            pre_sum += nums[end];

            while (pre_sum >= target) {
                ans = min(ans, end - start + 1);
                pre_sum -= nums[start];
                start++;
            }
        }
        return ans == INT_MAX ? 0 : ans;
    }
};