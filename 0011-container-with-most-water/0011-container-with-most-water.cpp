class Solution {
public:
    int maxArea(vector<int>& height) {

        int n=height.size();

        int l=0,r=n-1;

        int area=INT_MIN;

        while(l<r){
            
            int breadth=r-l;
            int length=min(height[l],height[r]);
            area=max(area,length*breadth);

            if(height[l]<height[r]){
                l++;
                
            }else if(height[l]>height[r]){
                r--;
                
            }else{
                l++;
                r--;
            }
        }
        return area;
        
    }
};