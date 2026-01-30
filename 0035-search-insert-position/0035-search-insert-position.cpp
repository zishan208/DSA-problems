class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {

            int s=0;
            int e=nums.size()-1;
        while (s<=e)
        {

            int mid=s+(e-s)/2;

            // when elemnt found
            if (nums[mid]==target) return mid;
            // when element not found
            
            if(target>nums[mid] && mid==nums.size()-1) return mid+1;
            if(target<nums[mid] && mid==0) return 0;
             if (target>nums[mid] && target<nums[mid+1] && mid<nums.size()-1) return (mid+1);
            
            

            if (nums[mid]>target)
            {
                e=mid-1;
            }   
            else {
                s=mid+1;
            }     
        }
        return s;
    }
};