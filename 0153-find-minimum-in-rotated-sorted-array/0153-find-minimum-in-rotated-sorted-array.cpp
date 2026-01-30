
class Solution {
public:
    int findMin(vector<int>& nums) {
            int s=0;
            int e=nums.size()-1;
        while (s<e)
        {
            int mid=s+(e-s)/2;

            // this only applciable when array is sorted
            if (nums[mid]>nums[e])
            {
                s=mid+1;
            }   
            else {
                e=mid;
            }     
        }

        return nums[s];


        // if (s==nums.size()-1)
        // {
        //     return nums[0];
        // }
        // else{
        //     return nums[s+1];
        // }     
      
    }
};