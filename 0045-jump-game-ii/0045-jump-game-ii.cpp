class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        if (n <= 1) return 0;

        int jumpcount = 0;
    int end = 0;
        int maxcover = 0;

        for (int i = 0; i < n - 1; i++) {
            maxcover = max(maxcover, i + nums[i]);

            if (i == end) {
                jumpcount++;
                end = maxcover;

                if (end >= n - 1) break;
            }
        }

        return jumpcount;
    }
};