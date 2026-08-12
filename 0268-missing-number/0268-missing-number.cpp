// class Solution {
// public:
//     int missingNumber(vector<int>& nums) {

//         int range=nums.size()-1;
//         map<int,bool> count;
//         for (int i = 0; i < nums.size(); i++) {
//             count[nums[i]]=true;
//         }

//         for (int i = 0; i <=nums.size(); i++) {
//             if (!count[i]) {
//                return i;
//             } 
//         }
//         return 0;
//     }
// };


// class Solution {
// public:
//     int missingNumber(vector<int>& nums) {
//         unordered_set<int> seen(nums.begin(), nums.end());
//         for (int i = 0; i <= nums.size(); i++) {
//             if (!seen.count(i)) return i;
//         }
//         return 0;
//     }
// };


class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int total=0;
        for (int i = 0; i < nums.size(); i++) {
           total+=nums[i];
        }

        int sum=nums.size()*(nums.size()+1)/2;
        return sum-total;

        
       
    }
};