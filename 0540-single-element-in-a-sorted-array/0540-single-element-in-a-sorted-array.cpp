class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {

    //ones we get mid then compare it to it right and left index, if anyone equal then proceed next
      int element=0;
      for (int i = 0; i < nums.size(); i++)
      {
        element=element^nums[i];
      }
        
            return element;

    }

};