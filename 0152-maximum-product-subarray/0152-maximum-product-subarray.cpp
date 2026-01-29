class Solution{
public:
    int maxProduct(vector<int>& nums) {


        int suffix=1;
        int prefix=1;
        int result=INT_MIN;
        int n=nums.size();
        for (int i = 0; i < n; i++)
        {
           
           if (suffix==0) suffix=1;
           if (prefix==0) prefix=1;
            suffix=suffix*nums[i];
            prefix=prefix*nums[n-1-i];

           result=max(result,max(prefix,suffix));
          
           
        }
        
return result;
        
    };
};

