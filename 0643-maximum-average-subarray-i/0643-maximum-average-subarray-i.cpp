class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        int s = 0;
        long long sum = 0;
      double ans = 0.0;


      for (int i = 0; i < k; i++) {
         
                sum += nums[i];


                if (i == k - 1) {
                    ans = (double)sum / k;
                }
            }
                

        for (int i = k; i < nums.size(); i++) {
          
                sum -= nums[s];
                s++;
                sum += nums[i];

                ans = max(ans, (double)sum / k);
            }
        

        return ans;
    }
};