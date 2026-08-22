class Solution {
        
    private:
            int findmax(vector<int>& nums,int size,int index,vector<int>& maxtill){
                
                if(index>=size) return 0;
        if(maxtill[index]!=-1) return maxtill[index];
            
                int sum1= nums[index]+findmax(nums,size,index+2,maxtill);
                int sum2 =nums[index]+findmax(nums,size,index+3,maxtill);
                
                int sum3=findmax(nums,size,index+1,maxtill);
                
        int maxi=max(sum1,max(sum2,sum3));
                
               
                    maxtill[index]=maxi;
                
            
                return maxi;
                }
                



public:
    int rob(vector<int>& nums) {

         vector<int> maxtill(nums.size()+1,-1);
        
        
      return findmax(nums,nums.size(),0,maxtill);
        
    }
};
