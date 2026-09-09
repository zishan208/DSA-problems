class Solution {
    private:
    void per(vector<int> &nums,vector<vector<int>> &ans,vector<int> temp,int size,vector<bool> v){

        if(temp.size()==size){
            ans.push_back(temp);
            return;
        }


       for(int i=0;i< size;i++){

        if(!v[i]){
            temp.push_back(nums[i]);
            v[i]=true;
            per(nums,ans,temp,size,v);
            temp.pop_back();
            v[i]=false;


        }else{
            continue;
        }
       
       }




    }
public:
    vector<vector<int>> permute(vector<int>& nums) {
        
        int size=nums.size();

        vector<int> temp;

        vector<vector<int>> ans;
        vector<bool> v(size,false);

        per(nums,ans,temp,size,v);

        return ans;
        

    }
};