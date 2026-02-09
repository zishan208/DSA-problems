
// class Solution {
// public:
//     vector<vector<int>> fourSum(vector<int>& nums, int target) {
//         sort(nums.begin(),nums.end());
//         vector<vector<int>> result;
//         for (int i = 0; i < nums.size(); i++)
//         {
//            target=target-nums[i];

//            for (int j = i+1; i < nums.size(); j++)
//            {
//             target-=nums[j];
//             // now we need two elements;
//             int left=0;
//             int right=nums.size()-1;
//             while (left<right)
//             {
//                 if (target>(nums[left]+nums[right]))
//                 {
//                     left++;
//                 }
//                 else if (target<(nums[left]+nums[right]))
//                 {
//                     right--;
//                 }
//                 else{
//                     vector<int> arr={nums[i],nums[j],nums[left],nums[right]};
//                     result.push_back(arr);
//                     left++;
//                     right--;
//                 }
                
                
//             }
            

//            }
           
//         }
        
//         return result;
//     }
// };

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> result;
        int n = nums.size();

        for (int i = 0; i < n; i++) {
            if (i > 0 && nums[i] == nums[i-1]) continue; // skip duplicates

            for (int j = i+1; j < n; j++) {
                if (j > i+1 && nums[j] == nums[j-1]) continue; // skip duplicates

                int left = j+1, right = n-1;
                long long newTarget = (long long)target - nums[i] - nums[j];

                while (left < right) {
                    long long sum = nums[left] + nums[right];
                    if (sum < newTarget) {
                        left++;
                    } else if (sum > newTarget) {
                        right--;
                    } else {
                        result.push_back({nums[i], nums[j], nums[left], nums[right]});
            while (left < right && nums[left] == nums[left+1]) left++;
                        while (left < right && nums[right] == nums[right-1]) right--;
                        left++;
                        right--;
                    }
                }
            }
        }
        return result;
    }
};


