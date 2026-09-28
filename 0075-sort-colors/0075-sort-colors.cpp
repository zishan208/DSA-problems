class Solution {
public:
    void sortColors(vector<int>& nums) {
        
        int r=0,w=0,b=0;
        
        for(int &c:nums){
            if(c==0){
                r++;
            }
            else if(c==1){
                 w++;
                 }
            else {
                b++;
                 }
        }

        int i=0;
        while(r){
            nums[i]=0;
            i++;
            r--;

        }
        while(w){
            nums[i]=1;
            i++;
            w--;
        }
        while(b){
            nums[i]=2;
            i++;
            b--;
        }

    }
    
};