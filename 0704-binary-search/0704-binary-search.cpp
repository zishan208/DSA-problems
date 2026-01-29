class Solution {
public:
    int search(vector<int>& nums, int target) {
        int s=0;
        int e=nums.size()-1;

        return binarySearch(nums,target,s,e) ;    
    }
    int binarySearch(vector<int>& nums, int target,int s, int e){
         if (s>e)   return -1;
         int mid=s+(e-s)/2;
        if (nums[mid]==target)  return mid;
       
        
        

        if (nums[mid]>target)
        {
               return binarySearch(nums,target,s, mid-1) ;
        }
        else{
            return  binarySearch(nums,target,mid+1, e) ;
        }
    }
};