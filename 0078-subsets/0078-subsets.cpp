
class Solution {
public:

void solution(vector<vector<int>> & ans, vector<int> output,int index,vector<int> nums){



    //base case
    if (index>=nums.size())
    {
        ans.push_back(output);
       return;
    }
    
    // if exclude
    solution(ans,output,index+1,nums);

    // if include
    int element=nums[index];
    output.push_back(element);

       solution(ans,output,index+1,nums);
     
}
    vector<vector<int>> subsets(vector<int>& nums) {
        
         vector<vector<int>> ans;
            vector<int> output;
            int index=0;
            solution(ans,output,index,nums);
            return ans;



        
    }
};