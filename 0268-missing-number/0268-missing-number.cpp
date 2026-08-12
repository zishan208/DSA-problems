class Solution {
public:
    int missingNumber(vector<int>& nums) {

        int range=nums.size()-1;
        map<int,bool> count;
        for (int i = 0; i < nums.size(); i++) {
            count[nums[i]]=true;
        }

        for (int i = 0; i <=nums.size(); i++) {
            if (!count[i]) {
               return i;
            } 
        }
        return 0;
    }
};