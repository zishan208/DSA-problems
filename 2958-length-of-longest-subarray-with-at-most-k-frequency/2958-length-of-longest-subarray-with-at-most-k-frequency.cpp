class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
            unordered_map<int,int> count;
            vector<int> ans;
            int maxm=0;
            int left=0, right=0;
            for (int i = 0; i < nums.size(); i++) {
            
                ++count[nums[i]];
                if (count[nums[i]]>k) {
                 while (count[nums[i]]>k) {
                   
                    count[nums[left]]--;
                     left++;
                     
                 } 
                
                }
                 int newmax=i-left+1;
                 maxm=max(maxm,newmax);
           
                }
                 return maxm;
            }

          
    };
