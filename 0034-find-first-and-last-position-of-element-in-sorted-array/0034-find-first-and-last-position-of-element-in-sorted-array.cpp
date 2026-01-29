

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int s=0;
        int e=nums.size()-1;
        int reqM=-1;
        vector<int> result;

        while (s<=e)
        {
         int mid=s+(e-s)/2;
            if (nums[mid]>target)
            {
                e=mid-1;
            }
            else if(nums[mid]<target){
                s=mid+1;
            }
            else{
                reqM=mid;
                break;
            }
            

            
            
        }


            int FO=-1;
            int LO=-1;

            if (reqM!=-1)
            {
                FO=reqM;
                LO=reqM;           
        //lets i get a mid as requires position;
        for (int i = reqM+1; i < nums.size(); i++)// calculation of last ocurence
        {
            if (target==nums[i])
            {
                LO=i;
            }
            else{
                break;
            }
            
        }

        for (int i = reqM-1; i >=0; i--)// calculation of last ocurence
        {
            if (target==nums[i])
            {
                FO=i;
            }
            else{
                break;
            }
            
        }
        
    }
        result.push_back(FO);
        result.push_back(LO);

return result;
       
        
        
    }
        

};