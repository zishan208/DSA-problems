class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int size=nums.size();
        vector<int> pre_mul(size);
        vector<int> pos_mul(size);
        int pmul=1;
        for(int i=0; i< size;i++){
            pre_mul[i]=pmul;
            pmul=pmul*nums[i];
        }
        pmul=1;
        for(int i=size-1; i>=0;i--){
            pos_mul[i]=pmul;
            pmul=pmul*nums[i];
        }
        vector<int> ans(size);
        for(int i=0; i< size;i++){
            ans[i]=pre_mul[i]*pos_mul[i];
        }
        return ans;
    }
};