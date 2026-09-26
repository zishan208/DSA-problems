class Solution {
public:
    int trap(vector<int>& height) {


        int n=height.size();
        vector<int> leftmax(n,-1);
        vector<int> rightmax(n,-1);

        int left=-1;
        int right=-1;
        
        for(int i=0;i<n;i++){
            leftmax[i]=left;
            left=max(left,height[i]);
        }
        
        for(int i=n-1;i>=0;i--){
            rightmax[i]=right;
            right=max(right,height[i]);
        }
        int unit=0;
         for(int i=1;i<n-1;i++){
            
           int most=min(rightmax[i],leftmax[i]);
           if(most>height[i]){
            unit+=most-height[i];
           }
        }
        return unit;
        
    }
};