class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {

        int mini=INT_MAX;
        int maxi=INT_MIN;
        int n=nums.size();
        unordered_map<int ,bool> c;
        for(int i=0;i<n;i++){
            if(nums[i]<=0) continue;
            maxi=max(maxi,nums[i]);
            mini=min(nums[i],mini);
            c[nums[i]]=true;
        }

        if(mini>1) return 1;

        for(int i=1;i<=maxi;i++){
            if(!c[i]) return i;
            
        }

        return maxi+1;

        
    }
};